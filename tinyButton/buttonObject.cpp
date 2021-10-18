/* ---------------------- Button Object Library ------------------

    Library to simplify the implementation of buttons for inclusion with
    User Interfaces.


   Imogen Heard
   Pan Galactic Tech
   09/08/2020

   Released for public use


  // buttonObject::buttonMaster Function >
  
  This method calls all methods required to return global variables:

  //pressCount
  //longPressCount
  //releaseCount
  //longPress - bool
  //shortPress - bool

    Which can be used for reliable user interfaces.

    Other methods can be used individually for more specific functions


*/

#include "buttonObject.h"



void buttonObject::begin() {    // Pass the number of the pin the button is attached to, and the "active" state (is the button pulled up, or pulled down? // specify default values in HEADER not .cpp!!!

  if (onState) {                                            // if 1 then button is active PULL HIGH, so input it left floating and should be pulled down externally with 1 - 10k resistor
    pinMode(buttonPin, INPUT);
  } else {
    pinMode(buttonPin, INPUT_PULLUP);                           // else if onState is 0, then button is active PULL LOW, therefore input is pulled high. External pullup resistors can also be used.
  }

}




//  Basic Method to sample the true state of the buttonPin

uint8_t buttonObject::sampleButton() {

  uint8_t buttonRead = digitalRead(buttonPin);     // Read the button

  return buttonRead;

}



// Ultra Debounce method
//https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/#more-180185


// First method to check for a button press

uint8_t buttonObject::detectButton() {                           // Function returns true if button sample matches the predefined onState  < Use this fucntion to pass true when pressed to ultra debounce function

  uint8_t detectedState = sampleButton();

  if (detectedState == onState) {
    return 1;
  } else {
    return 0;
  }
}




// Second method to save the results from detectButton into a history for this button

void buttonObject::updateButton(uint8_t *buttonHistory) {

  *buttonHistory = *buttonHistory << 1;

  *buttonHistory |= detectButton();

}



// Following Methods to detect what kind of event is saved in the button history

// This function tests for a button press

#define MASK   0b11000111                                             // This shows the binary mask. Increase the number of 1s at end of mask to increase robustness, and noise deflection, but increase time taken to
                                                                                                           // detect the rising or falling edge.

uint8_t buttonObject::buttonPressed(uint8_t *buttonHistory) {
  uint8_t pressed = 0;
  if ((*buttonHistory & MASK) == 0b00000111) {                  //                  bitwise AND mask:    so if button history is   00000000     11111111  |  00001111  |  11110000
    pressed = 1;                                                                                          // AND mask is           11000111     11000111  |  11000111  |  11000111
    *buttonHistory = 0b11111111;                                                                          //   bitwise& is         00000000     11000111  |  00000111  |  11000000
  }
  return pressed;                                                                                                                                             // This is the only pattern that returns true
}





uint8_t buttonObject::buttonReleased(uint8_t *buttonHistory) {                  // Has button been released?   Method same as above
  uint8_t released = 0;
  if ((*buttonHistory & MASK) == 0b11000000) {
    released = 1;
    *buttonHistory = 0b00000000;
  }
  return released;
}



uint8_t buttonObject::buttonDown(uint8_t *buttonHistory) {                     // is button Held down?
  return (*buttonHistory == 0b11111111);
}




uint8_t buttonObject::buttonUp(uint8_t *buttonHistory) {                         // is button not pressed?
  return (*buttonHistory == 0b00000000);
}




// buttonHold Function > This method calls all methods required to return:

//pressCount
//longPressCount
//releaseCount
//longPress - bool
//shortPress - bool

bool buttonObject::buttonLoop(uint32_t holdTime) {                                  // Method that performs all the functions nessissary to return a bool buttonTap & buttonHold


  buttonObject::updateButton( & buttonHistory);             // updates the history of the button by calling function detectButton and saving the result into the bitstream



  if (!buttonLockout) {                  // If button has not been locked out


    if ( buttonObject::buttonReleased( & buttonHistory)) {
      shortPress = true;
      releaseCount++;                                                                                                          // Function here to sort a short tap from a long hold - This comes first because of where button lockout happens
    }


    if ( buttonObject::buttonPressed( & buttonHistory)) {   //if button has been pressed (rising edge) //   ( & buttonHistory) could also be written by declairing the variable uint8_t buttonHistory externally to the library. code might be neater.
      pressTime = millis();                                    // start timer
      pressCount++;                                             // increment pressCount
    }


    if (buttonObject::buttonDown(& buttonHistory)) {                            // If the button is being held down - use timing function to measure for a long press

      if (millis() - pressTime >= holdTime) {                                  // If holdTime has elapsed (defaults to 1500ms)                                                   //Output   11000111     11000111

        longPress = true;                                                     // longpress is true
        longPressCount++;
        buttonLockout = true;
        return true;
      }
    }

  } else {                                                                       // if button has been locked out test to see if button is released now to unlock lockout
    if (buttonObject::buttonUp(& buttonHistory)) {
      buttonLockout = false;
    }
  }
  
}



void buttonObject::buttonReset(){    // Resets latching variables after their function has been fulfilled.
  
shortPress = false;
longPress = false;

  
}
