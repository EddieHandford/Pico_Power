#include "keypad.h"
uint16_t get_button_states();

int main() {
    Serial.begin(9600);
    stdio_init_all(); //Not sure if this is needed?

    while (true) {
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