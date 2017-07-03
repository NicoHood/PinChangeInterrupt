/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  PinChangeInterrupt_TickTock
  Demonstrates how to use the library

  Connect a button/cable to pin 7 and ground.
  The Led state will change if the pin state does.

  PinChangeInterrupts are different than normal Interrupts.
  See readme for more information.
  Dont use Serial or delay inside interrupts!
  This library is not compatible with SoftSerial.

  The following pins are usable for PinChangeInterrupt:
  Arduino Uno/Nano/Mini: All pins are usable
  Arduino Mega: 10, 11, 12, 13, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64),
              A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)
  Arduino Leonardo/Micro: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
  HoodLoader2: All (broken out 1-7) pins are usable
  Attiny 24/44/84: All pins are usable
  Attiny 25/45/85: All pins are usable
  Attiny 13: All pins are usable
  Attiny 441/841: All pins are usable
  ATmega644P/ATmega1284P: All pins are usable
*/

#include "PinChangeInterrupt.h"

// Choose a valid PinChangeInterrupt pin of your Arduino board
#define pinBlink 7

void setup() {
  // set pin to input with a pullup, led to output
  pinMode(pinBlink, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // Manually blink once to test if LED is functional
  blinkLed();
  delay(1000);
  blinkLed();

  // Attach the new PinChangeInterrupt and enable event function below
  attachPCINT(digitalPinToPCINT(pinBlink), blinkLed, CHANGE);
}

void blinkLed(void) {
  // Switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void loop() {
  // Nothing to do here
}
