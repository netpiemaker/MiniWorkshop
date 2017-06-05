void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  char option;
  if(Serial.available() > 0){
    option = Serial.read();
   
    if(option == 'T' || option == 't'){
      Serial.print("\n");
      Serial.print("Mode Temperature");
    }
    else if(option == 'H' || option == 'h'){
      Serial.print("\n");
      Serial.print("Mode Humidity");
    }
    else{
      Serial.print("\n");
      Serial.print("Please choose option");
    } 
  }
}


