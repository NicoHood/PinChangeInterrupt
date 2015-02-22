/*
 Copyright (c) 2014 NicoHood
 See the readme for credit to other people.

 PinChangeInterrupt_Led
 Demonstrates how to use the library

 Connect a button/cable to pin 10 and ground.
 The Led state will change if the pin state does.

 PCINT is useful if you are running out of normal INTs or if you are using HoodLoader2.
 PCINT has some delay because of the pin determination overhead.
 Dont use Serial or delay inside the interrupt!
 Keep in mind that this PCINT is not compatible with SoftSerial (at the moment).

 The following pins are usable for PinChangeInterrupt:
 Arduino Uno: All pins are usable  
 Arduino Mega: 10, 11, 12, 13, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)
 Arduino Leonardo: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
 HoodLoader2: All (broken out 1-7) pins are usable
 Attiny 24/44/84: All pins are usable  
 Attiny 25/45/85: All pins are usable  
 */

#include "PinChangeInterrupt.h"

// see note above to choose the right pin (with a pin change interrupt!) for your Arduino board
// you have to use defines here, const int won't work
#define pinBlink 10
#define interruptBlink digitalPinToPinChangeInterrupt(pinBlink)

void setup() {
  // set pin to input with a pullup, led to output
  pinMode(pinBlink, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // attach the new PinChangeInterrupt and enable event function below
  attachPinChangeInterrupt(interruptBlink, CHANGE);
}

void PinChangeInterruptEvent(interruptBlink)(void) {
  // switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void loop() {
  // nothing to do here
}

