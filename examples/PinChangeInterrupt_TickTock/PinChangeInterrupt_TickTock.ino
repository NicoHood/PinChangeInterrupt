/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  PinChangeInterrupt_TickTock
  Demonstrates how to use the library

  Connect a button/cable to pin 10/11 and ground.
  The value printed on the serial port will increase
  if pin 10 is rising and decrease if pin 11 is falling.

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

// choose a valid PinChangeInterrupt pin of your Arduino board
#define pinTick 10
#define pinTock 11

volatile long ticktocks = 0;

void setup()
{
  // start serial debug output
  Serial.begin(115200);
  Serial.println(F("Startup"));

  // set pins to input with a pullup
  pinMode(pinTick, INPUT_PULLUP);
  pinMode(pinTock, INPUT_PULLUP);

  // attach the new PinChangeInterrupts and enable event functions below
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTick), tick, RISING);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTock), tock, FALLING);
}

void loop() {
  // integer to count the number of prints
  static int i = 0;
  delay(1000);

  // print values
  Serial.print(i, DEC);
  Serial.print(F(" "));
  Serial.println(ticktocks);

  // abort if we printed 100 times
  if (i >= 100) {
    Serial.println(F("Detaching Interrupts."));
    detachPinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTick));
    detachPinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTock));
    return;
  }
  else
    i++;

  // Temporary pause interrupts
  if (ticktocks > 500) {
    Serial.println(F("Disabling Tick Interrupt."));
    disablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTick));
    enablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTock));
  }
  else if (ticktocks < -500) {
    Serial.println(F("Disabling Tock Interrupt."));
    disablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTock));
    enablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTick));
  }
  else {
    enablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTick));
    enablePinChangeInterrupt(digitalPinToPinChangeInterrupt(pinTock));
  }
}

void tick(void) {
  // increase value
  ticktocks++;
}

void tock(void) {
  // decrease value
  ticktocks--;
}
