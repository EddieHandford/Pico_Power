
//debug float
#include <Wire.h>

//standard includes
#include "stdio.h"
#include "stdint.h"
#include <Arduino.h>



// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
//Debug Serial Setup , Comment in and Out as required  
  Serial.begin(9600);


//debug
  Wire.begin();  



}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second

//float






//   Wire.requestFrom(0x76, 6);    // request 6 bytes from peripheral device #8

//   while (Wire.available()) { // peripheral may send less than requested
//     char c = Wire.read(); // receive a byte as character
//     Serial.print(c);         // print the character
//   }

//   delay(500);






// //test Serial Output
// Serial.println("Look at me MOM!");






  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");








}
