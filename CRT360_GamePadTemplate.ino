// GamePad Code Template
// ESP32-Enabled GamePad
// Ruth Carraway || 10/4/22                                                 <------ UPDATE THIS

// Libraries & Definitions
#define BOUNCE_WITH_PROMPT_DETECTION                            // Provides faster debouncing for precise gameplay
#include <Bounce2.h>                                            // Bounce2 Library
#include <Arduino.h>                                            // Arduino Library
#include <BleGamepad.h>                                         // Bluetooth Gamepad Library
BleGamepad bleGamepad("Starboard", "Ruth Carraway", 100);      // Replace Device Name / Manufacturer w/ your info

void setup() {
  Serial.begin(115200);
  initButtons();                                                // Initialize All Buttons
  initJoysticks();                                              // Initialize All Joysticks
  initBattery();                                                // Initialize Battery

  BleGamepadConfiguration bleGamepadConfig;                     // Create a GamePad Configuration
  bleGamepadConfig.setButtonCount(15);                          // Declare the Button Count (15)
  bleGamepad.begin(&bleGamepadConfig);                          // Begin Bluetooth Communication  bleGamepad.begin(&bleGamepadConfig); 
}

void loop() {
  if (bleGamepad.isConnected()) {                               // If the GamePad is connected to the Computer
    //Serial.println("Connected!");
    updateBattery();                                            // Update Battery Status
    updateButtons();                                            // Update Button States
    updateJoysticks();                                          // Update Joystick Status
  }
}
