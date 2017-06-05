//This program use the Serial communication via hyperterminal to control built-in LED
void setup() {
  Serial.begin(9600); //Initialize serial communication at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT); //Set LED built-in(LED_BUILTIN is the name for reference to LED on board) as a output. We can write
                                //true(off) or false(on) to control it 
}
void loop() {
  char option;
  if(Serial.available() > 0){   //Check data in Receive Buffer of UART 
    option = Serial.read();     //if the data is in buffer then read and store it to option var

    //Compare option with your case
    //1. Option is 'n' or 'N' ---> turn on the LED
    //2. Option is 'f' or 'F' ---> turn off the LED
    //Otherwise ---> Message alert for user to enter the correct input
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


