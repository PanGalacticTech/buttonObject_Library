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



// Derived Class ------------// Base Class
class tinyButton: public buttonObject {

  public:

    // Could use #ifdef NUMBER_BUTTONS 4 to give different constructors for different numbers of buttong
    // for brevity, 4 will be hardcoded


// THIS IS THE WRONG WAY TO DO THIS!! LOOK AT HOW WE DID motorObject & Derived classes
// As each instance needs to use methods independently, this derived class needs to
//CONTAIN buttonObject, not be AN INSTANCE of it.

    // Constructor
    tinyButton(int analog_buttonPin):   // Note syntax and structure here: Important for implementing Derived Classes
      buttonA( buttonObject (buttonPin, buttonActiveState)),    // Not sure this is the correct way to make named instances but try it out                                              // BASE class is called without naming an instance, but passing any required values as arguments.
      buttonB( buttonObject (buttonPin, buttonActiveState)),    // would be better as an array
      buttonC( buttonObject (buttonPin, buttonActiveState)),
      buttonD( buttonObject (buttonPin, buttonActiveState)),    // Others have calls to redundant pins, Dont know if this matters or not
      buttonPin(analog_buttonPin)                               // Passes the
    {
    }


// Global Variables

  uint8_t buttonPin;   // Assigned a value in the constructor




    // Methods
    void begin();

    uint8_t sampleADC();       // returns the true analog state of the ADC

    uint8_t deriveButton();     // Derives which button has been pushed based on analog vaule

    void updateButtons();                             // Updates the history for the button that has been pushed


  private:



#endif
