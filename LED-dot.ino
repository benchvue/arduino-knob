#include <Modulino.h>

// Create Modulino objects
ModulinoPixels leds;

int brightness = 10;
int currentLED = 3;  // Track which LED is currently on (0-7)

void setup() {

  // Initialize Modulino I2C communication
  Modulino.begin();
  // Detect and connect to modules
  leds.begin();
}

void loop() {
  // Turn on the first LED
  updateLEDs();
}

// Function to update LEDs - turn off all except current position
void updateLEDs() {
  leds.set(currentLED, GREEN, brightness);  // Turn on current LED
  leds.show();
}
