#define flash_button 0
boolean ON_OFF_STATUS = true;

void setup() {
  Serial.begin(9600);
  pinMode(flash_button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  int read_flash_button_value = digitalRead(flash_button);
  if(read_flash_button_value == 0){ 
    ON_OFF_STATUS = !ON_OFF_STATUS;
    digitalWrite(LED_BUILTIN, ON_OFF_STATUS);
  }
  delay(150);
}
