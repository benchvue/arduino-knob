#include <Modulino.h>

// Create Modulino objects
ModulinoPixels leds;
ModulinoKnob knob;

int brightness = 10;
int currentLED = 0;  // Track which LED is currently on (0-7)

void setup() {
  
  // Initialize Modulino I2C communication
  Modulino.begin();
  
  // Detect and connect to modules
  leds.begin();
  knob.begin();
  
  // Turn on the first LED
  updateLEDs();
}

void loop() {
  // Get the rotation direction from knob
  int8_t direction = knob.getDirection();
  
  // Check if knob was rotated
  if (direction == 1) {
    // Clockwise rotation - move LED to the right (bottom)
    if (currentLED < 7) {  // Don't go past the last LED
      currentLED++;
      updateLEDs();
    }
  } 
  else if (direction == -1) {
    // Counter-clockwise rotation - move LED to the left (top)
    if (currentLED > 0) {  // Don't go past the first LED
      currentLED--;
      updateLEDs();
    }
  }
  
  delay(10);  // Small delay to reduce processing overhead
}

// Function to update LEDs - turn off all except current position
void updateLEDs() {
  for (int i = 0; i < 8; i++) {
    if (i == currentLED) {
      leds.set(i, GREEN, brightness);  // Turn on current LED
    } else {
      leds.set(i, GREEN, 0);  // Turn off LED by setting brightness to 0
    }
  }
  leds.show();
}
