#include "DHT.h"   //DHT library include the method that help you to measure the temperature and humidity easier

#define DHTPIN 2  //Define pin that you connect DHT to NODEMCU(2 is mean GPIO 2, You can search "PIN mapping of NODEMCU" for more informatino  
#define DHTTYPE 11  //Define type of DHT that you use
DHT dht(DHTPIN, DHTTYPE); //create the dht object by passing the DHTPIN and DHTTYPE as a parameters

void setup(){
  dht.begin();  //Start using the DHT sensor
  Serial.begin(115200);
}
void loop() {
  float humid = dht.readHumidity(); //call method readTemperature to read a temperature
  float temp = dht.readTemperature(); //call method readHumidity to read a humidity
  //Define string variable named "str" to contain the output and use for showing at serial monitor
  String str = "Humidity: " + String(humid) + "%RH / Temperature: "
    + String(temp) + "*C";
  Serial.println(str);
  delay(500);
}

