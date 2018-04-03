// Sparkfun Pro micro (clone)
// ATmega32U4 (5V, 16MHz)

//#include "Keyboard.h"
#include "HID-Project.h"

#define KEY_PAUSE 4

const int Button = 2;
const int led = 3;

int val = 0;
int prevVal = 0;

void setup() { // initialize the buttons' inputs:
  
  pinMode(Button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  //  Keyboard.begin();      // Standard arduino library (crappy)
  Consumer.begin();
  BootKeyboard.begin();
  //  System.begin();        // For System functions
  //  Gamepad.begin();       // For gamepad functions
  //  Mouse.begin();         // For mouse functions
  //  AbsoluteMouse.begin(); // For the Absolute Mouse
}

void loop() {
  prevVal = val;
  val = digitalRead(Button);
  
  if (val < prevVal) {
    //Keyboard.write('u');
    Consumer.write(MEDIA_PLAY_PAUSE);
  }
  
  if (BootKeyboard.getLeds() & LED_SCROLL_LOCK){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(1);
}
