#include <ESP8266WiFi.h>
const char* ssid = "NSTDA-Project-7013";
const char* password = "1q2w3e4r";

void setup(){
  Serial.begin(9600);
  Serial.flush();
  Serial.print("\nConnecting to : ");
  Serial.println(ssid);
  if(WiFi.begin(ssid, password)){
    while (WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(". ");}}
  Serial.println("WiFi Connected");
  Serial.println("Device IP : ");
  Serial.print(WiFi.localIP());
}
void loop(){
  //Do Nothing
}

