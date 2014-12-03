/*
 Copyright (c) 2014 NicoHood
 See the readme for credit to other people.

 IRL Receive_PinChangeInterrupt_Api
 Receives IR signals with custom Pin Change Interrupt Api.

 This is the PCINT version with an easy to use Api on almost any pin for the IRLremote.
 PCINT is usefull if you are running out of normal INTs or if you are using HoodLoader2.
 Keep in mind that this PCINT is not compatible with SoftSerial (at the moment).

 On Arduino Uno you can use any pin for receiving.
 On Arduino Mega you can use 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).
 On Arduino Leonardo you can use 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 With HoodLoader2 you can use pin 1-7 and some other pins which are normally not connected.

 */

#include "IRLremote.h"
#include "PinChangeInterrupt.h"

void setup()
{
  // start serial debug output
  Serial.begin(115200);
  Serial.println(F("Startup"));

  // attach the new PinChangeInterrupt function above
  // 3966 - 217 (mega) - 3640 (uno)
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(11), CHANGE);

  // 5126 - 233 (mega) - 4090 (uno)
  //attachInterrupt(digitalPinToPinChangeInterrupt(2), IRLinterrupt<IR_ALL>, CHANGE);
}

void loop() {
  // this will get the first valid input, and blocks until you reset below
  if (IRLavailable()) {
    // print as much as you want in this function
    // see source to terminate what number is for each protocol
    Serial.println();
    Serial.print(F("Protocol:"));
    Serial.println(IRLgetProtocol());
    Serial.print(F("Address:"));
    Serial.println(IRLgetAddress(), HEX);
    Serial.print(F("Command:"));
    Serial.println(IRLgetCommand(), HEX);

    // resume reading to get new values
    IRLreset();
  }
}

void PinChangeInterruptEvent(uint8_t port) {
  // PinChangeInterrupt weak event handler
  // Do not use any Serial or long function calls here!
  if (port == digitalPinToPinChangeInterrupt(11))
    IRLinterrupt<IR_ALL>();
}
