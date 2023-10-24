#include "keypad.h"
uint16_t get_button_states();
void initKeypad();

void setup() {
 Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    //stdio_init_all(); //Not sure if this is needed?
    Serial.println("This Port");
    initKeypad();
}


void loop()
{
 
  uint16_t button_states = get_button_states();
  Serial.println(button_states); // So this is currently outputting 65535 which is the highest number. Caused by it flipping the 2 zeros it gets from the previous function.
  //Serial.println(get_button_states());
  
  update();     
  sleep_ms(100); // Poll the button states every 100 milliseconds
} 

/*
int main() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    //stdio_init_all(); //Not sure if this is needed?
    Serial.println("This Port");
    while (true) {
        Serial.println("This Port");
        uint16_t button_states = get_button_states();
        
        // Iterate through all buttons in a 4x4 grid
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                int button_index = row * 4 + col;
                
                // Check if the button at button_index is pressed
                if (button_states & (1 << button_index)) {
                    Serial.println("Button Pressed \n" + row + col);
                } 
            }
        }
        
        sleep_ms(100); // Poll the button states every 100 milliseconds
    }

    return 0;
}

// Iterate through all buttons in a 4x4 grid
    for (int row = 0; row < 4; row++) 
    {
      for (int col = 0; col < 4; col++) 
      {
        int button_index = row * 4 + col;
                
        // Check if the button at button_index is pressed
        if (button_states & (1 << button_index)) 
        {
          Serial.println("Button Pressed \n" + row + col);
        } 
      }
    }
*/