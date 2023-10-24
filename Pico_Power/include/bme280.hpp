#ifndef BME280_H
#define BME280_H

#include "stdio.h"
#include "stdint.h"
#include <Arduino.h>

//include for access to Global data
#include "data_dictionary.hpp"


namespace bme280_sensor {

    class BME280 {
        public:
            static const uint8_t DEFAULT_I2C_ADDRESS    = BME_I2C_ADDRESS;
            static const uint8_t ALTERNATE_I2C_ADDRESS  = BME_I2C_BACKUP_ADDRESS;
            static const uint8_t DEFAULT_INT_PIN        = BME_I2C_INT_PIN ;
            };//end of class


        struct bme280_reading {
            float temperature   = 0.0;     //to do , check intialisation of variables is sensible and/or required
            float pressure      = 0.0;
            float humidty       = 0.0;
            bool status         = false;

        };



}//end of namespace




#endif