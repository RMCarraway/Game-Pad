// Functions for Buttons
//int statusLED = 0;      // ----> UPDATE THIS CODE  --------->status led is not connected on this board
int batterySensor = 34; // Battery Sensor Connected to Pin 34
float bHigh = 905.0;    // Analog Value read at 5.0 volts
float bLow = 450.0;     // Analog Value read at 3.0 volts
float vHigh = 5.0;      // Test volts at 5.0 volts
float vLow = 3.0;       // Test volts at 3.0 volts
float chargeMax = 4.2;  // Fully Charged Battery
float chargeMin = 3.2;  // Fully Depleted Battery
int lastCharge = 100;   // Keep Track of Last Charge
int battThresh = 5;     // Only Update if Battery % has changed by 5%

//unsigned long startTime = millis();   ----------------->timer for the LED
//unsigned long endTime;
//long interval = 1000;

// initBattery() declares the battery sensor as an input and statusLED as an output
void initBattery(){
  pinMode(batterySensor, INPUT);
  
  // ----> UPDATE THIS CODE TO INITIALIZE THE STATUS LED
  
  //pinMode(stausLED, OUTPUT); ------------------------>led declaration
  
}

// updateBattery gets the current percent of charge remaining. It then compares that value to the last known % charge
// of the battery. If they have changed, it updates the last known charge as well as updates the bleKeyboard library
// using the bleKeyboard.setBatteryLevel(curCharge) function

// If the battery charge is more than 50%, it will keep the Status LED on. 
// If the battery charge is 50% or less, it will blink the Status led every 1000ms (without using a delay)

void updateBattery(){
  int curCharge = (int)percentBattery();
  if(abs(curCharge - lastCharge) > battThresh){
    bleGamepad.setBatteryLevel(curCharge);
    lastCharge = curCharge;
  }

  // ----> UPDATE THIS CODE TO FOR STATUS LED FUNCTIONS

  boolean statState = digitalRead(statusLED);
  
//  if(curCharge > 50){   ---------------> Code for status LED
//    statState= HIGH;
//  }
//  if(curCharge < 50){
//    if(endTime - startTime >= interval){
//      if(statusLED=LOW){
//      statusLed=HIGH;
//     }
//     if(statusLED=HIGH){
//      statusLed=LOW;
//     }
//    startTime=millis();
//  }
//  endTime=millis();
// }

}

// voltsBattery reads the battery sensor and returns the voltage of the battery
// This is accomplished reading the battery sensor and mapping its value (using the special mapFloat function) 
// that range from bHigh to bLow, to the new scale of vHigh to vLow. This mapped value is returned as a floating number
float voltsBattery(){
  float rawV = (float)analogRead(batterySensor);
  float voltage = mapFloat(rawV, bHigh, bLow, vHigh, vLow);
  return voltage;
}

// percentBattery reads the battery sensor and returns the % remaining in the battery
// This is accomplished calling the voltsBattery function and mapping its value (using the special mapFloat function) 
// that range from chargeMin to chargeMax, to the new scale of 0.0 to 100.0 (representing % charge). 
// This mapped value is returned as a floating number
float percentBattery(){
  float rawV = voltsBattery();
  float percent = mapFloat(rawV, chargeMin, chargeMax, 0.0, 100.0);
  return percent;
}

// The normal Arduino float( ) function only works with integers. 
// This special function works with floating numbers for more precision
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
