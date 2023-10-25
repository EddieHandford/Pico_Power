
//debug float
#include <Wire.h>

//standard includes
#include "stdio.h"
#include "stdint.h"
#include <Arduino.h>

#include "bme280.hpp"


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
//Debug Serial Setup , Comment in and Out as required  
  Serial.begin(115200);


//debug
  Wire.begin();  


Wire.beginTransmission(0x76); //address of i2c device
Wire.write(0xE0);   
Wire.write(0xB6);             //address of register with data
Wire.endTransmission();




}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);               // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 // delay(1000);               // wait for a second

//float


//start i2c to device with address of BME  // to do , add functionaility to allow multiple devices on the i2c
 //Wire.beginTransmission(BME_I2C_ADDRESS);




const uint8_t ADDRESS_OF_SOFT_RESET_REGISTER = 224; //0xE0; 

const uint8_t SOFT_RESET_REGISTER_VALUE = 182; ////0xB6; 


const uint8_t Bme280RegisterAddressTemperatureData = 0xFA;

uint8_t i2c_buffer_send [2] ;
i2c_buffer_send [0] =   ADDRESS_OF_SOFT_RESET_REGISTER ; 
i2c_buffer_send [1] =   SOFT_RESET_REGISTER_VALUE ; 


//Wire.write(224);
//Wire.write(182);

 //reset the sensor with soft reset to ensure its IIR (Infinte impulse response) mode is disabled - this is a filter
// Wire.write(i2c_buffer_send, 2);    //address of register is : 0xE0  , value is 0xB6 to reset

 //Wire.endTransmission(); 


//to do, pretty sure sensor needs setup




Wire.beginTransmission(0x76); //address of i2c device
Wire.write(0xF7);             //address of register with data
Wire.endTransmission();


uint8_t i = 0;

Wire.requestFrom(0x76 , 8);   //request 8 bytes
uint8_t buffer[8];

 while(Wire.available())
  {
   buffer[i++] = Wire.read();
   Serial.print(buffer[i]);
  }
delay(1000);



//Serial.println("end of buffer");
//delay to make serial window readable
//delay (2000);






// bool BME280I2C::WriteRegister
// (
//   uint8_t addr,
//   uint8_t data
// )
// {
//   Wire.beginTransmission(m_settings.bme280Addr);
//   Wire.write(addr);
//   Wire.write(data);
//   Wire.endTransmission();

//   return true; // TODO: Check return values from wire calls.
// }


// /****************************************************************/
// bool BME280I2C::ReadRegister
// (
//   uint8_t addr,
//   uint8_t data[],
//   uint8_t length
// )
// {
//   uint8_t ord(0);

//   Wire.beginTransmission(m_settings.bme280Addr);
//   Wire.write(addr);
//   Wire.endTransmission();

//   Wire.requestFrom(static_cast<uint8_t>(m_settings.bme280Addr), length);

//   while(Wire.available())
//   {
//     data[ord++] = Wire.read();
//   }

//   return ord == length;
// }



















































//   Wire.requestFrom(0x76, 6);    // request 6 bytes from peripheral device #8

//   while (Wire.available()) { // peripheral may send less than requested
//     char c = Wire.read(); // receive a byte as character
//     Serial.print(c);         // print the character
//   }

//   delay(500);






// //test Serial Output
// Serial.println("Look at me MOM!");






  // byte error, address;
  // int nDevices;

  // Serial.println("Scanning...");

  // nDevices = 0;
  // for(address = 1; address < 127; address++ ) 
  // {
  //   // The i2c_scanner uses the return value of
  //   // the Write.endTransmisstion to see if
  //   // a device did acknowledge to the address.
  //   Wire.beginTransmission(address);
  //   error = Wire.endTransmission();

  //   if (error == 0)
  //   {
  //     Serial.print("I2C device found at address 0x");
  //     if (address<16) 
  //       Serial.print("0");
  //     Serial.print(address,HEX);
  //     Serial.println("  !");

  //     nDevices++;
  //   }
  //   else if (error==4) 
  //   {
  //     Serial.print("Unknown error at address 0x");
  //     if (address<16) 
  //       Serial.print("0");
  //     Serial.println(address,HEX);
  //   }    
  // }
  // if (nDevices == 0)
  //   Serial.println("No I2C devices found\n");
  // else
  //   Serial.println("done\n");








}
