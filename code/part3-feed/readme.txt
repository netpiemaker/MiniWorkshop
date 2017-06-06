..
#define FEEDID  "FEEDID" // ใส่ชื่อของ FEEDID
#define FEEDAPI  "FEEDAPI" // ใส่ API ของ FEED
..
unsigned long lastTimeWriteFeed = 0;
..
void loop() {
    if (microgear.connected()) {
    ..
        if(millis()-lastTimeWriteFeed > 15000){
          lastTimeWriteFeed = millis();
          if(humid!=0 && temp!=0){
            String data = "{\"humid\":";
            data += humid ;
            data += ", \"temp\":";
            data += temp ;
            data += "}"; 
            Serial.print("Write Feed --> ");
            Serial.println(data);
            microgear.writeFeed(FEEDID,data);
            //microgear.writeFeed(FEEDID,data,FEEDAPI);
          }
        }
    ..
    }
}
