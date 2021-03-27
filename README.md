# buttonObject_Library *(v1.0.0)*
#### Built and maintained by [Declan Heard](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Libaray to handle and debounce button inputs using OOP topology.
* Button is sampled periodically and history saved into a bitstream.
* Bitmasks used to compare bitstream to a rising edge or falling edge over a number of samples.
* This method is great at rejecting noise from dirty contacts or cheap buttons.
* Button defined as a Pull Up or Pull Down button in constructor.
* Method can differentiate between long press & short press.
* Adjustable long press duration.
* Returns total number of button presses.
* Returns total number of button releases.
* Returns total number of button longPresses (In resting state: releaseCount + longPressCount = pressCount).
* Ultra fast and low overhead method.
* Each buttonObject controls one input, add a new constructer for each button required.

### Based On: [Embed with Elliot: Ultimate Debounce method](https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/#more-180185)
___________________________________________________________________________________________________________

## Getting Started
### Deployment
1. Clone or Download library folder into Arduino IDE libraries folder.
2. Extract files from zipped folder if required.
3. Open Arduino IDE and select example program.

### Dependencies
No dependency for library function, however examples have the following dependencies:
* ledObject_library available from [here](https://github.com/PanGalacticTech/ledObject_library) - written by PanGalacticTech
___________________________________________________________________________________________________________

## Use

### Precompiler Requirements<br>

`#include <buttonObject.h>   // Libary include`  <br> <br>

Button Pin Declaration<br>

`#define BUTTON_PIN 4                     // Select Button input pin`   <br>

Long Press Time Declaration<br>

`#define LONG_PRESS_TIME 750                // time in milliseconds` <br>
 <br>

___________________________________________________________________________________________________________

### Object Constructors

Declaring a button object:

`buttonObject button(BUTTON_PIN, BUTTON_PULL_HIGH);` <br>

If button is LOW pulled HIGH on press, use: <br>
`BUTTON_PULL_HIGH` <br>

Else If button is HIGH pulled LOW on press, use: <br>
`BUTTON_PULL_LOW` <br><br>

<br>

___________________________________________________________________________________________________________

### Setup Functions:

`button.begin();`<br> <br>

.begin() Function sets up button input pin into input mode, and sets INPUT_PULLUP, if button is specified<br>
BUTTON_PULL_LOW

<br><br>

___________________________________________________________________________________________________________

### Loop Functions:

Loop function must be called in every loop & as often as possible. Delays between loop executions will affect 
function.

`button.buttonLoop(LONG_PRESS_TIME);   // long int controls the time required for a long press. (defaults to 1000 mS)`<br>

This function will record the bitstream and return boolean flags when button states are detected.



<br>


___________________________________________________________________________________________________________

### Detecting Button Press:
#### Short Press

A short press is detected when the user releases the button in a time shorter than LONG_PRESS_TIME.

`button.shortPress` <br>

bool is set true on button release.<br>

#### Long Press

A long press is detected when the user keeps button depressed longer than LONG_PRESS_TIME

`button.longPress`<br>

bool is set true while button is depressed and button will not trigger short press untill
it is released and reset.

### Resetting the Triggers

button.shortPress & button.longPress bools act as triggers and must be reset after triggering associated 
behaviour.

`button.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken` <br><br>

### Example Loop Using Reset Behaviour

`button.buttonLoop();   // long int passed controls the time required for a long press. (defaults to 1 second)`

`  if (button.shortPress) {`
`    led.toggleLED();`
`    button.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken`
`  }`







___________________________________________________________________________________________________________

### Advanced Uses:



<br>
<br>

___________________________________________________________________________________________________________
___________________________________________________________________________________________________________

### Limitations:



<br>

### Known Issues V1.0.0
  - Please report any bugs or issues found.

<br>

### Features to be Added 

<br>
<br>

## About
### Built With
* [Arduino IDE](https://www.arduino.cc/) - Default IDE


### Author
#### Declan Heard
* [LinkedIn](https://www.linkedin.com/in/declan-heard-91103b58/)
* Email: [Personal](mailto:dec.h38@gmail.com "dec.h38@gmail.com") | [Company](mailto:PanGalacticTech@gmail.com "PanGalacticTech@gmail.com")
* [Github Profile](https://github.com/PanGalacticTech)
