void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  char option;
  if(Serial.available() > 0){
    option = Serial.read();
    if(option == 'n' || option == 'N'){ // Turn on
      Serial.print("\n");
      Serial.print("Turn on");
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(option == 'f' || option == 'F'){ // Turn off
      Serial.print("\n");
      Serial.print("Turn off");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else{
      Serial.print("\n");
      Serial.println("Press N to turn on");
      Serial.println("Press F to turn off");
    }
  }
}


