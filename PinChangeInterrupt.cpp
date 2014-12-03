/*
Copyright (c) 2014 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "PinChangeInterrupt.h"

//================================================================================
// PinChangeInterrupt
//================================================================================

void __attribute__((weak)) PinChangeInterruptEvent(uint8_t port) {
  // PinChangeInterrupt weak event handler
  // The user has to overwrite this function!
}

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[3] = {0};
uint8_t fallingPorts[3] = {0};
uint8_t risingPorts[3] = {0};

// interrupt handlers
#if defined(PCINT0_vect)
ISR(PCINT0_vect) {
  PCintPort(0);
}
#endif

#if defined(PCINT1_vect)
ISR(PCINT1_vect) {
  PCintPort(1);
}
#endif

#if defined(PCINT2_vect)
ISR(PCINT2_vect) {
  PCintPort(2);
}
#endif

#if defined(PCINT3_vect)
ISR(PCINT2_vect) {
  //TODO currently not supported. which avr has 3 PCINT?
  //PCintPort(3);
}
#endif
