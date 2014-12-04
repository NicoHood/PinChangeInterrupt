/*
 Copyright (c) 2014 NicoHood
 See the readme for credit to other people.

 PinChangeInterrupt_Api_Basic
 Demonstrates how to use the library

 Connect a button/cable to pin 4/5 on Arduino Uno (change pins for different boards)
 The value printed on the serial port will increase if pin 4 is changing and decrease if pin 5 is changing.

 PCINT is useful if you are running out of normal INTs or if you are using HoodLoader2.
 Dont use Serial inside the interrupt!
 Keep in mind that this PCINT is not compatible with SoftSerial (at the moment).

 On Arduino Uno you can use any pin for receiving.
 On Arduino Mega you can use 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).
 On Arduino Leonardo you can use 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 With HoodLoader2 you can use pin 1-7 and some other pins which are normally not connected.

 */

#include "PinChangeInterrupt.h"

// see readme to choose the right pin (with a pin change interrupt!) for your Arduino board
const int pinTick = 4;
const int pinTock = 5;
const int interruptTick = digitalPinToPinChangeInterrupt(pinTick);
const int interruptTock = digitalPinToPinChangeInterrupt(pinTock);

volatile long ticktocks = 0;

void setup()
{
  // start serial debug output
  Serial.begin(115200);
  Serial.println(F("Startup"));

  // set pins to input, no pullup set for this example
  pinMode(pinTick, INPUT);
  pinMode(pinTock, INPUT);

  // attach the new PinChangeInterrupts and enable Event function below
  attachPinChangeInterrupt(interruptTick, CHANGE);
  attachPinChangeInterrupt(interruptTock, CHANGE);
}

void loop() {
  static long i = 0;
  i++;
  delay(1000);
  Serial.print(i, DEC);
  Serial.print(" ");
  Serial.println(ticktocks);
  if (i > 256) {
    detachPinChangeInterrupt(interruptTick);
    detachPinChangeInterrupt(interruptTock);
  }
}

void tick(void) {
  ticktocks++;
}

void tock(void) {
  ticktocks--;
}

void PinChangeInterruptEvent(uint8_t pcintNum) {
  // PinChangeInterrupt weak event handler
  // Do not use any Serial or long function calls here!
  if (pcintNum == interruptTick)
    tick();
  else if (pcintNum == interruptTock)
    tock();
}
