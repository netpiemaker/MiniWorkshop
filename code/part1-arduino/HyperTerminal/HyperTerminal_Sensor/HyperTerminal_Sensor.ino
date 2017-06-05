#include "DHT.h"   //DHT library include the method that help you to measure the temperature and humidity easier

#define DHTPIN 2  //Define pin that you connect DHT to NODEMCU(2 is mean GPIO 2, You can search "PIN mapping of NODEMCU" for more informatino  
#define DHTTYPE 11  //Define type of DHT that you use

DHT dht(DHTPIN, DHTTYPE); //create the dht object by passing the DHTPIN and DHTTYPE as a parameters

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();  //Start using the DHT sensor
}

void loop() {
  char option; 
  if(Serial.available() > 0){   //Check the Receive Buffer of UART if data is available then we read and store in varable named "option" 
    option = Serial.read();
    float tem = dht.readTemperature();  //call method readTemperature to read a temperature
    float hum = dht.readHumidity();     //call method readHumidity to read a humidity
    delay(300);

    //Compare option with your case
    //1. Option is 't' or 'T' ---> Use Temperature Mode and show temperature
    //2. Option is 'h' or 'H' ---> Use Humidity Mode and show humidity
    //Otherwise ---> Message "Please choose option"
    if(option == 'T' || option == 't'){
      Serial.print("\n");
      Serial.print("Temperature : ");
      Serial.print(tem);
      Serial.print(" *C");
    }
    else if(option == 'H' || option == 'h'){
      Serial.print("\n");
      Serial.print("Humidity : ");
      Serial.print(hum);
      Serial.print(" %");
    }
    else{
      Serial.print("\n");
      Serial.print("Please choose option");
    }
  }
}
