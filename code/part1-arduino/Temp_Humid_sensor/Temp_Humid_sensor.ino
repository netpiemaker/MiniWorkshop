#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN  2
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  dht.begin();
  Serial.begin(115200);
}
void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  String str = "Humidity: " + String(humid) + "%RH / Temperature: "
    + String(temp) + "*C";
  Serial.println(str);
  delay(500);
}

