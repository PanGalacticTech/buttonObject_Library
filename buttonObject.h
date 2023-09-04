/* ---------------------- Button Object Library ------------------

    Library to simplify the implementation of buttons for inclusion with
    User Interfaces.


   Imogen Wren
   Pan Galactic Tech
   09/08/2020

   Released for public use


  // buttonObject::buttonMaster(long holdTime)

  > Function >

  This method calls all methods required to return global variables:

  // pressCount
  // longPressCount
  // releaseCount
  // longPress - bool
  // shortPress - bool

    Which can be used for reliable user interfaces.

    Other methods can be used individually for more specific functions


*/




#ifndef buttonObject_h
#define buttonObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#define BUTTON_PULL_HIGH 1
#define BUTTON_PULL_LOW 0


#define buttonMaster buttonLoop                 // Sets up Synonym for buttonHold : buttonMaster
#define buttonHold   buttonLoop                 // Alternative Synonyms for

class buttonObject {
    // Constants
    // These varaibles are set in the .begin function:

    int buttonPin;          // global variable to hold the number of the button pin

    int onState;            // global variable to hold the active state of the button (pull HIGH or pull LOW)


  public:

    // Constructor

    buttonObject(int attachTo, int activeState):              // Alternative way of setting out constructor. Will allow the use of further constructors
      buttonPin(attachTo),
      onState(activeState)
    {
    }



    // Begin Method

    void begin();


    // Basic Methods

    uint8_t sampleButton();      // Samples the button and returns true state of the button

    uint8_t detectButton();      // Calls method to sample the button, compares this to the predefined active/onState (PULL_HIGH or PULL_LOW)



    // Ultra Debounce Button Methods:
    //Based on:
    //https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/#more-180185


    void updateButton(uint8_t *buttonHistory);      // Updates buttonHistory bitstream

    uint8_t buttonPressed(uint8_t *buttonHistory);    // Returns true if button has been pressed (Rising Edge Detected)

    uint8_t buttonReleased(uint8_t *buttonHistory);    // Returns true if button has been released (Falling Edge Detected)

    uint8_t buttonDown(uint8_t *buttonHistory);        // Returns true if the button is held down (Constant High detected)

    uint8_t buttonUp(uint8_t *buttonHistory);            // Returns ture if button is not pressed (Constant Low detected)

    bool buttonLoop(uint32_t holdTime = 1000);           // - Aliased with buttonMaster & buttonHold Method // Variable passed is required millis value for a long press - Defaults to 1 second

    void buttonReset();                                   // Method for resetting shortPress & longPress bools once software has performed the required action
	
	void buttonStats();                                   // Method to print button stats


    // buttonMaster Method

    //> This method calls all methods required to return:

    //pressCount
    //longPressCount
    //releaseCount

    //shortPress - bool
    //longPress - bool

    // as global public variables


    // Variables

    // Variables to count the different actions of the button.
    // More useful for testing than interfacting with other functions

    uint8_t pressCount;                   // Counts the total number of button presses

    uint8_t releaseCount;                         // counts the total number of times the button is released after pressing.

    uint8_t longPressCount;                         // Counts the total number of times the button has detected a long press.

    //N.B. release count + longPressCount = pressCount

    // Bool functions for directly interfacing with other functions

    bool shortPress;                           // variable to return true when button is short tapped (turns true on release) (latching, must be reset)

    bool longPress;                            // variable returns true on long press (returns true on hold)       (latching, must be reset)




  private:

    //Variables

    uint8_t buttonHistory = 0;            // Stores the recent history of the button - Private as no need to access this outside of library (hmmmm)

    uint32_t pressTime;     // Stores the time at which the button was first pressed in order to time long presses.

    bool buttonLockout;   // when true button functions are locked, to allow for correct operation after long presses





};

#endif
