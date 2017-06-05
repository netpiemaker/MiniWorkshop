#include <ESP8266WiFi.h>
#include <MicroGear.h>
#include "DHT.h"              // library สำหรับอ่านค่า DHT Sensor

const char* ssid     = "<SSID>";        // ชื่อ ssid
const char* password = "<PASSWORD>";                  // รหัสผ่าน wifi

#define APPID   "<APPID>"                              // ให้แทนที่ด้วย AppID
#define KEY     "<KEY>"                   // ให้แทนที่ด้วย Key
#define SECRET  "<SECRET>"         // ให้แทนที่ด้วย Secret
#define ALIAS   "switch"                            // ชื่ออุปกรณ์

#define DeviceControl "html5"                      // ชื่ออุปกรณ์ที่ต้องการส่งข้อความไปให้

#define DHTPIN D4        // GPIO2 ขาที่ต่อเข้ากับขา DATA(OUT) ของ DHT
#define DHTTYPE DHT11  // e.g. DHT11, DHT21, DHT22
DHT dht(DHTPIN, DHTTYPE);

char str[32];
int humid = 0;
int temp = 0;
unsigned long lastTimeDHT = 0;

WiFiClient client;

int timer = 0;
MicroGear microgear(client);

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) { // 
    Serial.print("Incoming message --> ");
    msg[msglen] = '\0';
    Serial.println((char *)msg);

    // สถานะ LED ที่แสดงผล จะติดก็ต่อเมื่อสั่ง LOW แต่ถ้าเป็น LED ที่ต่อแยก จะต้องสั่งเป็น HIGH 
    if(*(char *)msg == '1'){
        digitalWrite(LED_BUILTIN, LOW);   // LED on, 
        microgear.chat(DeviceControl,"1");
    }else{
        digitalWrite(LED_BUILTIN, HIGH);  // LED off
        microgear.chat(DeviceControl,"0");
    }
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    microgear.setAlias(ALIAS);
}


void setup() {
    // กำหนดฟังก์ชั้นสำหรับรับ event callback 
    microgear.on(MESSAGE,onMsghandler);
    microgear.on(CONNECTED,onConnected);

    // กำหนด baud rate สำหรับการสื่อสาร
    Serial.begin(115200);
    Serial.println("Starting...");
    
    dht.begin(); // setup ตัวแปรสำหรับอ่านค่า DHT Sensor

    // กำหนดชนิดของ PIN (ขาI/O) เช่น INPUT, OUTPUT เป็นต้น
    pinMode(LED_BUILTIN, OUTPUT);
    // กดหนดสถานะเริ่มต้นให้ LED ดับ
    digitalWrite(LED_BUILTIN, HIGH);

    // เชื่อมต่อ wifi
    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.print(".");
        }
    }

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    microgear.init(KEY,SECRET,ALIAS);   // กำหนดค่าตันแปรเริ่มต้นให้กับ microgear
    microgear.connect(APPID);           // ฟังก์ชั่นสำหรับเชื่อมต่อ NETPIE
}

void loop() {
    if (microgear.connected()) { // microgear.connected() เป็นฟังก์ชั่นสำหรับตรวจสอบสถานะการเชื่อมต่อ
        // microgear.loop() เป็นฟังก์ชั่นสำหรับทวนสถานะการเชื่อมต่อกับ NETPIE (จำเป็นต้องมีใช้ loop)
        microgear.loop();
        timer = 0;
        if(millis()-lastTimeDHT > 1000){
          lastTimeDHT = millis();
          int h = dht.readHumidity();     // อ่านค่าความชื้น
          int t = dht.readTemperature();  // อ่านค่าอุณหภูมิ
          
          Serial.print("Humidity: ");
          Serial.print(h);
          Serial.print(" %\t");
          Serial.print("Temperature: ");
          Serial.print(t);
          Serial.print(" *C ");

          // ตรวจสอบค่า humid และ temp เป็นตัวเลขหรือไม่ และค่าที่ได้เป็นค่าที่ถูกต้องหรือไม่
          if (isnan(humid) || isnan(temp) || h > 10000 || t > 10000) {
            Serial.println("Failed to read from DHT sensor!");
          }else{
            humid = h;
            temp = t;
          }

          // แปลงค่าข้อมูลให้เป็นชนิด char สำหรับส่งข้อมูลผ่าน NETPIE
          sprintf(str,"%d,%d",humid,temp);
          
          Serial.print("Sending --> ");
          Serial.println(str);
          if(humid!=0 && temp!=0) microgear.publish("/dht",str);
        }
    }
    else {
        Serial.println("connection lost, reconnect...");
        if (timer >= 5000) {
            microgear.connect(APPID); 
            timer = 0;
        }
        else timer += 100;
        delay(100);
    }
}
