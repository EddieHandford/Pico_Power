#include "bme280.hpp"

//access to global data
#include "data_dictionary.hpp"

//standard includes
#include "stdio.h"
#include "stdint.h"
#include <Arduino.h>

//I2C specific include
#include <Wire.h>


bme280_sensor::BME280 bmeObj;



void bme_setup ( ) {   // to do , add inputs to function

    Wire.begin(bmeObj.DEFAULT_I2C_ADDRESS);

};