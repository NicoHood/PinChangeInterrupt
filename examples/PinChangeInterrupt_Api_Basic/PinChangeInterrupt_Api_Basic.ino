/*
 Copyright (c) 2014 NicoHood
 See the readme for credit to other people.

 PinChangeInterrupt_Api_Basic
 Demonstrates how to use the library

 Connect a button/cable to pin 10/11/14 and ground.
 The value printed on the serial port will increase if pin 10 is rising and decrease if pin 11 is falling.
 The led will change its state if pin 14 changes.

 PCINT is useful if you are running out of normal INTs or if you are using HoodLoader2.
 PCINT has some delay because of the pin determination overhead.
 Dont use Serial or delay inside the interrupt!
 Keep in mind that this PCINT is not compatible with SoftSerial (at the moment).

 On Arduino Uno you can use any pin for PinChangeInterrupt.
 On Arduino Mega you can use 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).
 On Arduino Leonardo you can use 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 With HoodLoader2 you can use pin 1-7 and some other pins which are normally not connected.
 */

#include "PinChangeInterrupt.h"

// see note above to choose the right pin (with a pin change interrupt!) for your Arduino board
// you have to use defines here, const int won't work
#define pinTick 10
#define pinTock 11
#define pinBlink 14 // A0 on Arduino Uno
#define interruptTick digitalPinToPinChangeInterrupt(pinTick)
#define interruptTock digitalPinToPinChangeInterrupt(pinTock)
#define interruptBlink digitalPinToPinChangeInterrupt(pinBlink)

volatile long ticktocks = 0;

void setup()
{
  // start serial debug output
  Serial.begin(115200);
  Serial.println(F("Startup"));

  // set pins to input with a pullup, led to output
  pinMode(pinTick, INPUT_PULLUP);
  pinMode(pinTock, INPUT_PULLUP);
  pinMode(pinBlink, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // attach the new PinChangeInterrupts and enable event functions below
  attachPinChangeInterrupt(interruptTick, RISING);
  attachPinChangeInterrupt(interruptTock, FALLING);
  attachPinChangeInterrupt(interruptBlink, CHANGE);
}

void loop() {
  // integer to count the number of prints
  static int i = 0;
  delay(1000);

  // print values
  Serial.print(i, DEC);
  Serial.print(" ");
  Serial.println(ticktocks);

  // abort if we printed 100 times
  if (i >= 100) {
    detachPinChangeInterrupt(interruptTick);
    detachPinChangeInterrupt(interruptTock);
    detachPinChangeInterrupt(interruptBlink);
  }
  else
    i++;
}

void PinChangeInterruptEvent(interruptTick)(void) {
  // increase value
  ticktocks++;
}

void PinChangeInterruptEvent(interruptTock)(void) {
  // decrease value
  ticktocks--;
}

void PinChangeInterruptEvent(interruptBlink)(void) {
  // switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}