/*
 Copyright (c) 2014 NicoHood
 See the readme for credit to other people.

 PinChangeInterrupt_LowLevel
 Demonstrates how to use the library without the API

 Make sure to comment "//#define PCINT_API" in the settings file.

 To maximize speed and size also uncomment all not used pins above.
 Then you could also uncomment "#define PCINT_COMPILE_ENABLED_ISR"
 to get away if the .a linkage overhead.

 Notice the new digitalPinToPinChangeInterruptLowLevel(pin) makro (see ticktock).
 You may also pass the PCINt number directly without this makro (see blink).
 Strong overwritten callback functions are called when an interrupt occurs.

 Connect a button/cable to pin 10/11/7 and ground (Uno).
 The value printed on the serial port will increase if pin 10 is rising and decrease if pin 11 is falling.
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
#define pinTick 10
#define pinTock 11
#define interruptTick digitalPinToPinChangeInterruptLowLevel(pinTick)
#define interruptTock digitalPinToPinChangeInterruptLowLevel(pinTock)

// manually defined pcint number
#define pinBlink 7
#define interruptBlink 23

volatile long ticktocks = 0;

void setup()
{
  // start serial debug output
  Serial.begin(115200);
  Serial.println(F("Startup"));

  // set pin to input with a pullup, led to output
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