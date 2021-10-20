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


#inclue "tinyButton.h"



 uint8_t tinyButton::sampleADC(){       // returns the true analog state of the ADC 

 buttonSample = analogRead(buttonPin);

 return buttonSample

 }

// define boundaries between analog reads

#define NULL_BOUNDARY 100
//#define BOUNDARY_0 0
#define BOUNDARY_1 256
#define BOUNDARY_2 512
#define BOUNDARY_3 768
#define BOUNDARY_4 1024



 uint8_t tinyButton::deriveButton(){    // Returns integers 1 - 4 depending on button pressed 0 = NULL or no button pressed

  buttonSample = sampleADC();

  if (buttonSample <= NULL_BOUNDARY){
    return 0;
  } else if (buttonSample > NULL_BOUNDARY && buttonSample <= BOUNDARY_1){
    return 1;
  } else if (buttonSample > BOUNDARY_1 && buttonSample <= BOUNDARY_2){
    return 2;
  } else if (buttonSample > BOUNDARY_2 && buttonSample <= BOUNDARY_3){
    return 3;
  } else if((buttonSample > BOUNDARY_3){
    return 4;
  } else {
    return false;
  }
 }

void buttonsHistory(){

  
}

 
