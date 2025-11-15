#include "Arduino_LED_Matrix.h"
#include <Modulino.h>

// Initialize LED matrix and knob instances
ArduinoLEDMatrix matrix;
ModulinoKnob knob;

// Pixel position (range 0-11)
int pixelPos = 5;

// 8x12 LED frame buffer
uint8_t frame[8][12] = {0};

void setup() {
  // Initialize LED matrix
  matrix.begin();
  
  // Initialize Modulino knob
  Modulino.begin();
  knob.begin();
}

void loop() {
  // Handle knob input
  handleKnob();
  
  // Clear the display
  clearFrame();
  
  // Draw the pixel
  drawPixel();
  
  delay(10);
}

void handleKnob() {
  // Get the rotation direction from knob
  int8_t direction = knob.getDirection();
  
  // Clockwise rotation - move pixel right
  if (direction == 1) {
    if (pixelPos < 11) {
      pixelPos++;
    }
  } 
  // Counter-clockwise rotation - move pixel left
  else if (direction == -1) {
    if (pixelPos > 0) {
      pixelPos--;
    }
  }
}

void clearFrame() {
  // Turn off all LEDs
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 12; x++) {
      frame[y][x] = 0;
    }
  }
}

void drawPixel() {
  // Turn on one pixel at the bottom row
  frame[7][pixelPos] = 1;
  
  // Show the frame on LED matrix
  matrix.renderBitmap(frame, 8, 12);
}
