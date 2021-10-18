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


    // Constructor
    tinyButton(int pinA, int pinB, int pinC, int pinD):   // Note syntax and structure here: Important for implementing Derived Classes
      buttonA( buttonObject (pinA, buttonActiveState)),    // Not sure this is the correct way to make named instances but try it out                                              // BASE class is called without naming an instance, but passing any required values as arguments.
      buttonB( buttonObject (pinB, buttonActiveState)),
      buttonC( buttonObject (pinC, buttonActiveState)),
      buttonD( buttonObject (pinD, buttonActiveState)),
      int buttonPins 
    {
    }







    // Methods
    void begin();

    uint8_t sampleADC();       // returns the true analog state of the ADC  

    uint8_t deriveButton(uint16_t analogValue);     // Derives which button has been pushed based on analog vaule

    void updateButtons();                             // Updates the history for the button that has been pushed






#endif
