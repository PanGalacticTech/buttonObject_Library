/* ---------------------- tinyButton Library ------------------

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
   18/10/2021

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

#include <ledObject.h>   // Only used for Example, not required for library function. Can be found
//                      @ https://github.com/PanGalacticTech/ledObject_library


ledObject led[4] = {2, 4, 6, 8};






// button Object



//#define BUTTON_PULL_HIGH 1    // These are defined in buttonObject.h file
//#define BUTTON_PULL_LOW 0




#define BUTTON_ADC_PIN A7


#include "tinyButton.h"

tinyButton buttons(BUTTON_ADC_PIN);


void setup() {

  Serial.begin(115200);

  startupLEDs();

 buttons.begin();


}



void loop() {

 int analogValue = buttons.deriveButton();

  Serial.println(analogValue);


  /*

    button.buttonLoop(750);   // long int passed controls the time required for a long press. (defaults to 1 second)

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

  */


}



void startupLEDs() {



  for (int i = 0; i < 4; i++) {

    led[i].begin();
    led[i].turnOff();
  }

  for (int i = 0; i < 4; i++) {

    led[i].begin();
    led[i].turnOn();

    delay(300);
  }

  for (int i = 0; i < 4; i++) {

    led[i].begin();
    led[i].turnOff();
  }

}
