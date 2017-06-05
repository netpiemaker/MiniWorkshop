#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  char option; 
  if(Serial.available() > 0){
    option = Serial.read();
    float tem = dht.readTemperature();
    float hum = dht.readHumidity();
    delay(300);
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
