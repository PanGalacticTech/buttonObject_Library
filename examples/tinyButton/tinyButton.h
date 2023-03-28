/* ---------------------- Button Object Library ------------------

    Library to simplify the implementation of buttons for inclusion with
    User Interfaces.

  Bulds on buttonObject methods by providing the ability to
  sample multiple buttons using Analog to Digital Converter.

  Buttons should be wired with different voltage dividers
  to a single ADC capable pin. Voltage on this pin is sampled,
  the number of the button is calculated and passed into
  the normal buttonObject methods.

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

#ifndef tinyButton_h
#define tinyButton_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#include "buttonObject.h"

#define BUTTON_PIN A7

// Derived Class ------------// Base Class
class tinyButton {


  private:

    buttonObject buttonA, buttonB, buttonC, buttonD;

  public:

    // Could use #ifdef NUMBER_BUTTONS 4 to give different constructors for different numbers of buttong
    // for brevity, 4 will be hardcoded


    // THIS IS THE WRONG WAY TO DO THIS!! LOOK AT HOW WE DID motorObject & Derived classes
    // As each instance needs to use methods independently, this derived class needs to
    //CONTAIN buttonObject, not be AN INSTANCE of it.

    // Constructor
    tinyButton(int analog_buttonPin):   // Note syntax and structure here: Important for implementing Derived Classes
      buttonA(analog_buttonPin, HIGH),
      buttonB(analog_buttonPin, HIGH),
      buttonC(analog_buttonPin, HIGH),
      buttonD(analog_buttonPin, HIGH)
    {
     buttonObject buttons[4] = {buttonA, buttonB, buttonC, buttonD};
    }


    // Global Variables

    int buttonPin = A7;

  //  buttonObject buttons[4];


    // Methods
    void begin();

    uint8_t sampleADC();       // returns the true analog state of the ADC

    uint8_t deriveButton();     // Derives which button has been pushed based on analog vaule   // This replaces detectButton

    void updateHistory(uint8_t *buttonsHistory[4]) ;                             // Updates the history for all buttons, replacing 0s with 1s in the bitstream for the number of th ebutton that has been pushed


void buttonsLoop();


};

#endif
