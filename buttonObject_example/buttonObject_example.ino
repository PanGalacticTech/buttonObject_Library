/* ---------------------- Button Object Library ------------------

    Library to simplify the implementation of buttons for inclusion with
    User Interfaces.


   Declan Heard
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

  -------------------------- Button Object Example ------------------------

  Shows method for using shortPress & longPress variables to control the function of an ledObject


*/






#include "buttonObject.h"

#include <ledObject.h>


ledObject led;






// button Object

#define buttonPin 4

buttonObject button;

//#define BUTTON_PULL_HIGH 1    // These are defined in buttonObject.h file
//#define BUTTON_PULL_LOW 0




void setup() {

  Serial.begin(115200);


  led.begin(13 , 1);

  button.begin(buttonPin, BUTTON_PULL_HIGH);     // Pass button pin & state indicating a "pushed" button. (defaults to HIGH)


}



void loop() {



  button.buttonMaster(750);   // long int passed controls the time required for a long press. (defaults to 1 second)

  // calling button master returns global variables:

  //pressCount
  //longPressCount
  //releaseCount
  //longPress - bool
  //shortPress - bool

  if (button.shortPress) {
    led.toggleLED();
    button.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken
  }

  if (button.longPress) {
    led.blinkEvent(10, 100, 200);
    button.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken
  }


  led.performBlink();    // Function from the LED library to perform blink events.

}
