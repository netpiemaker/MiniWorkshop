#include <ESP8266WiFi.h>
//Define a variable to cotain ssid and password of AP that you
//want to connect with NODEMCU
//This library help you to reconnect to wifi AP automatically

const char* ssid = "SSID";  
const char* password = "PASSWORD";

void setup(){
  Serial.begin(9600);
  Serial.print("\nConnecting to : ");
  Serial.println(ssid);
  //Starting a connection to your AP by using ssid and password that you define above
  if(WiFi.begin(ssid, password)){
    while (WiFi.status() != WL_CONNECTED){  //Waiting until the connection is success by checking connection 's status
      delay(500);
      Serial.print(". ");}}
  Serial.println("WiFi Connected");
  Serial.println("Device IP : ");
  Serial.print(WiFi.localIP()); //Showing your NODEMCU device IP
}
void loop(){
  //Do Nothing
  //WiFi.disconnect();  You can use this method to disconnect your NODEMCU from this AP
}

