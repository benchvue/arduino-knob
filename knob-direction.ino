#include <Modulino.h>

// Create Modulino object
ModulinoKnob knob;

void setup() {
  Serial.begin(9600);
  
  // Initialize Modulino I2C communication
  Modulino.begin();
  
  // Detect and connect to knob
  knob.begin();
  
  Serial.println("Knob Control Started!");
  Serial.println("Turn the knob to see direction");
}

void loop() {
  // Get the rotation direction from knob
  int8_t direction = knob.getDirection();
  
  // Check if knob was rotated
  if (direction == 1) {
    Serial.println("Clockwise");
  } 
  else if (direction == -1) {
    Serial.println("Counter-clockwise");
  }
  
  delay(10);  // Small delay to reduce processing overhead
}
