
// Button Control
                   //{23,22,21,19,4,2,18,14,15,5,17,16,13,35,27} original assignment
int buttonPins[15] = {23,22,21,19,4,2,35,27,15,5,17,16,13,18,14}; // Fill in { } with list of Button pins
int buttonNums[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // Store Button Number Assignments (1 - 15) 
                                                            //(This can be used to adjust button mapping in game later on)
Bounce * buttons = new Bounce[15];  // Creates an array of Bounce objects 

// initButtons loops through the array of Bounce2 buttons and attaches them as inputs.
// It also sets an interval of 5ms for responsiveness
void initButtons(){

 

  for (int i = 0; i < 15; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(5);
  }


}

// updateButtons loops through the array of Bounce2 buttons and updates them.
// If the buttons rose, then the respective button is pressed in the bleGamepad library
// If the buttons fell, then the respective button is released in the bleGamepad library
void updateButtons(){
    
    for (int i = 0; i < 15; i++) {
    buttons[i].update();
    
   
    if (buttons[i].rose()) {
      bleGamepad.press(i);
      Serial.println("pressed!");
    } 
    if (buttons[i].fell()){
      bleGamepad.release(i);
      }
    
  }

}
