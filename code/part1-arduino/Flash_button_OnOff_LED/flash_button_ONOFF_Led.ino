//This program will use flash button(pin0) as a toggle switch to turn on/off of built-in LED
#define flash_button 0  //define flash_button as a 0 (it's mean pin 0)
boolean ON_OFF_STATUS = true;  //define ON_OFF_STATUS to control LED on=false, off=true

void setup() {
  Serial.begin(9600);
  pinMode(flash_button, INPUT); //Set flash_button(pin0 that we define above) as a input pin for read a user's pressing
  pinMode(LED_BUILTIN, OUTPUT); //Set LED built-in(LED_BUILTIN is the name for reference to LED on board) as a output. We can write
                                //true(off) or false(on) to control it 
}
void loop() {
  int read_flash_button_value = digitalRead(flash_button);  //Read user input
  //press button = low, not press button = high
  if(read_flash_button_value == 0){   //If user pressing button it will return low then the led will toggle once every you press
    ON_OFF_STATUS = !ON_OFF_STATUS;
    digitalWrite(LED_BUILTIN, ON_OFF_STATUS); //Write the ON_OFF_STATUS to control on/off for LED
  }
  delay(150); //Delay for debouncing(debouncing is state that you detect more than 1 logic in changing phrase(from 0->1 or 1->0) 
              //We need to clear the random state out by using delay
}
