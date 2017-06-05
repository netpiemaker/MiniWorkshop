//Communicate to NODEMCU via HyperTerminal.It's a serial communication to board
void setup() {
  Serial.begin(9600);
}
void loop() {
  char option;  //Define option variable to contain your Selection mode
  //Serial.available for checking a byte in Receive Buffer of UART
  if(Serial.available() > 0){   
    option = Serial.read(); //Read the data and store in option

  //Compare option with your case
  //1. Option is 't' or 'T' ---> Use Temperature Mode
  //2. Option is 'h' or 'H' ---> Use Humidity Mode
  //Otherwise ---> Message "Please choose option"
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


