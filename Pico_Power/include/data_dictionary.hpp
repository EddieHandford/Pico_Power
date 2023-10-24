#ifndef DATA_DICTIONARY
#define DATA_DICTIONARY

#include "stdio.h"
#include "stdint.h"
#include <Arduino.h>



//   ___ ___ _  _     _   ___ ___ ___ ___ _  _ __  __ ___ _  _ _____ ___ 
//  | _ \_ _| \| |   /_\ / __/ __|_ _/ __| \| |  \/  | __| \| |_   _/ __|
//  |  _/| || .` |  / _ \\__ \__ \| | (_ | .` | |\/| | _|| .` | | | \__ 
//  |_| |___|_|\_| /_/ \_\___/___/___\___|_|\_|_|  |_|___|_|\_| |_| |___/

//BME 280
static const uint8_t BME_I2C_INT_PIN                 = 0; //unknown - to do

//End of Pin Assignments




//     _      _    _                   _          _                         _      
//    /_\  __| |__| |_ _ ___ ______   /_\   _____(_)__ _ _ _  _ __  ___ _ _| |_ ___
//   / _ \/ _` / _` | '_/ -_|_-<_-<  / _ \ (_-<_-< / _` | ' \| '  \/ -_) ' \  _(_-<
//  /_/ \_\__,_\__,_|_| \___/__/__/ /_/ \_\/__/__/_\__, |_||_|_|_|_\___|_||_\__/__/
//                                                 |___/                           


//BME 280
static const uint8_t BME_I2C_ADDRESS                 = 0x76;
static const uint8_t BME_I2C_BACKUP_ADDRESS          = 0X77;

//End of Address Assignments







#endif