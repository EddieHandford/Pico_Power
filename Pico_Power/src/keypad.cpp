#include "keypad.h"
#include <Arduino.h>

/*
Key Code Table - Button number on left - Code on right
0 = 1
1 = 2
2 = 4
3 = 8
4 = 16
5 = 32
6 = 64
7 = 128
8 = 256
9 = 512
A = 1024
B = 2048
C = 4096
D = 8192
E = 16384
F = 32768
'''
*/

/*
Objective: Detect when a button is pressed on the keypad, and note the time and which button to the console.
Breakdown: Detect button pressed. Identify button. Identify time. Combine and output to consolde
*/

enum pin {
  SDA       =  4,
  SCL       =  5,
  CS        = 17,
  SCK1       = 18,
  MOSI1      = 19
}; // Enumerator to link up the GPIO pins to which port they are connected to.

//Initialise variables for Pad size and keys
int WIDTH {4};


//Initialise the I2C interface and keypad
  void initKeypad()
  {
    gpio_set_function(pin::SDA, GPIO_FUNC_I2C); gpio_pull_up(pin::SDA);
    gpio_set_function(pin::SCL, GPIO_FUNC_I2C); gpio_pull_up(pin::SCL);
    _i2c_init(i2c0, 600000);

    _spi_init(spi0, 4 * 1024 * 1024);
    gpio_set_function(pin::CS, GPIO_FUNC_SIO);
    gpio_set_dir(pin::CS, GPIO_OUT);
    gpio_put(pin::CS, 1);
    gpio_set_function(pin::SCK1, GPIO_FUNC_SPI);
    gpio_set_function(pin::MOSI1, GPIO_FUNC_SPI);

    update();
  }

  void update() 
  {
    uint8_t buffer[(16 * 4) + 8];
    gpio_put(pin::CS, 0);
    spi_write_blocking(spi0, buffer, sizeof(buffer));
    gpio_put(pin::CS, 1);         
  }


uint16_t get_button_states() //returns a 16-bit unsigned integer which is used to store the state of the buttons
{ 
    uint8_t i2c_read_buffer[2]; //An array of 2 8 bit unsigned integer that makes up the i2c_read_buffer variable. Stores the data read from the i2c device
    uint8_t reg = 0; //An 8-bit unsigned integer used to specify which register or memory location on the I2C to read from. Its set to 0 which should be the starting register for reading button states
    uint8_t KEYPAD_ADDRESS = 0x20; //An 8-bit unsigned integer used to specift the i2c device address
    i2c_write_blocking(i2c0, KEYPAD_ADDRESS, &reg, 1, true); //Sends a I2C write command to the device. (i2c Bus to use, I2C address of the device being written to, the register to read from, number of bytes to write, whether to send a stop condition after sending)
    i2c_read_blocking(i2c0, KEYPAD_ADDRESS, i2c_read_buffer, 2, false); //Sends an I2C read command. (i2c bus to use, I2C address of the device being read from, The buffer the data read from the device will be stored in, number of bytes to read (2 representing the ON/OFF nature of the buttons), whether to send a stop condition after reading)
    Serial.println(i2c_read_buffer[0]);
    Serial.println(i2c_read_buffer[1]);
    return ~((i2c_read_buffer[0]) | (i2c_read_buffer[1] << 8)); //This line combines the two bytes read from the i2c device into a single 16 bit value. The first byte is used as the lower 8 bits and the second is shifter left by 8 to make the upper 8 bits. Then the ~ inverts all the bits to show the ON/OFF of the buttons. 
  } //The result of this is a 16 bit value where each bit corresponds to the state of a particular button.











/*
class PicoRGBKeypad {
  private:
    static const uint8_t KEYPAD_ADDRESS = 0x20;
    static constexpr float DEFAULT_BRIGHTNESS = 0.5f;
  public:
    static const int WIDTH = 4;
    static const int HEIGHT = 4;
    static const int NUM_PADS = WIDTH * HEIGHT;

  private:
    uint8_t buffer[(NUM_PADS * 4) + 8];
    uint8_t *led_data;
  
  public:
    ~PicoRGBKeypad();
    void init();
    void update();
    void set_brightness(float brightness);
    void illuminate(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
    void illuminate(uint8_t i, uint8_t r, uint8_t g, uint8_t b);

    void clear();
    uint16_t get_button_states();
  };
*/

//Keypad Functions

 /* void PicoRGBKeypad() {
    clear();
    update();
  }

  void init() {
    memset(buffer, 0, sizeof(buffer));
    uint8_t *led_data;
    led_data = buffer + 4;
    float DEFAULT_BRIGHTNESS {0.5f};
    set_brightness(DEFAULT_BRIGHTNESS); //Must be called to init each LED frame

    // setup i2c interface
    i2c_init(i2c0, 400000);
    gpio_set_function(pin::SDA, GPIO_FUNC_I2C); gpio_pull_up(pin::SDA);
    gpio_set_function(pin::SCL, GPIO_FUNC_I2C); gpio_pull_up(pin::SCL);

    spi_init(spi0, 4 * 1024 * 1024);
    gpio_set_function(pin::CS, GPIO_FUNC_SIO);
    gpio_set_dir(pin::CS, GPIO_OUT);
    gpio_put(pin::CS, 1);
    gpio_set_function(pin::SCK, GPIO_FUNC_SPI);
    gpio_set_function(pin::MOSI, GPIO_FUNC_SPI);

    update();
  }

  void update() {
    gpio_put(pin::CS, 0);
    spi_write_blocking(spi0, buffer, sizeof(buffer));
    gpio_put(pin::CS, 1);
  }

  void set_brightness(float brightness) {
    if(brightness < 0.0f || brightness > 1.0f) {
      return;
    }

    for(uint16_t i = 0; i < NUM_PADS; i++)
        led_data[i * 4] = 0b11100000 | (uint8_t)(brightness * (float)0b11111);
  }

  void illuminate(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) {
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
      return;
    }

    uint16_t offset = (x + (y * WIDTH)) * 4;
    //led_data[offset + 0] = 0xff;  //Not needed as set at init
    led_data[offset + 1] = b;
    led_data[offset + 2] = g;
    led_data[offset + 3] = r;
  }

  void illuminate(uint8_t i, uint8_t r, uint8_t g, uint8_t b) {
    if(i < 0 || i >= NUM_PADS) {
      return;
    }

    uint16_t offset = i * 4;
    //led_data[offset + 0] = 0xff;  //Not needed as set at init
    led_data[offset + 1] = b;
    led_data[offset + 2] = g;
    led_data[offset + 3] = r;
  }

  void clear() {
    for(uint16_t i = 0; i < NUM_PADS; i++)
      illuminate(i, 0, 0, 0);
  }

}*/