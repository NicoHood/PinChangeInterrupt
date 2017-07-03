/*
Copyright (c) 2014-2015 NicoHood
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

// include guard
#pragma once

//================================================================================
// Board Definitions
//================================================================================

// Microcontroller specific definitions

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
// Arduino Uno
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT1 PINC
#define PCINT_INPUT_PORT2 PIND

#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega640__)
// Arduino Mega/Mega2560
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT2 PINK

// special Port1 case, pins are on 2 HW Pin Ports (E,J)
#if defined(PCINT_ENABLE_PCINT16) // PortE
#if defined(PCINT_ENABLE_PCINT17) || defined(PCINT_ENABLE_PCINT18) \
   || defined(PCINT_ENABLE_PCINT19) || defined(PCINT_ENABLE_PCINT20) \
|| defined(PCINT_ENABLE_PCINT21) || defined(PCINT_ENABLE_PCINT22) \
|| defined(PCINT_ENABLE_PCINT23) // PortJ
// PortE and PortJ selected
#define PCINT_INPUT_PORT1 ((PINE & 0x01) | (PINJ << 1))
#else
// PortE only selected
#define PCINT_INPUT_PORT1 PINE
#endif
#else
// PortJ only selected
// we still have to do the shift because the attach
// function is not designed for this optimization
#define PCINT_INPUT_PORT1 (PINJ << 1)
#endif

#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
// Arduino Leonardo/Micro
#define PCINT_INPUT_PORT0 PINB

#elif defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
// u2 Series/HoodLoader2
// u2 Series has crappy pin mappings for port 1
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT1 (((PINC >> 6) & (1 << 0)) | ((PINC >> 4) & (1 << 1)) | ((PINC >> 2) & (1 << 2)) | ((PINC << 1) & (1 << 3)) | ((PIND >> 1) & (1 << 4)))

#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
// Attiny x5
#define PCINT_INPUT_PORT0 PINB

#elif defined(__AVR_ATtiny13__)
// Attiny 13A
#define PCINT_INPUT_PORT0 PINB
#ifndef portInputRegister
#define portInputRegister(P) ( (volatile uint8_t *)(PINB) )
#endif

#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
// Attiny x4
#define PCINT_INPUT_PORT0 PINA
#define PCINT_INPUT_PORT1 PINB

#elif defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644P__)
// 1284p and 644p, special 4 port case
#define PCINT_INPUT_PORT0 PINA
#define PCINT_INPUT_PORT1 PINB
#define PCINT_INPUT_PORT2 PINC
#define PCINT_INPUT_PORT3 PIND

#elif defined(__AVR_ATtinyX41__) || defined(__AVR_ATtiny441__) || defined(__AVR_ATtiny841__)
// Attiny x41
#define PCINT_INPUT_PORT0 PINA
#define PCINT_INPUT_PORT1 PINB

// "iotn841.h" is missing those definitions, so we add them here
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3

#elif defined(__AVR_ATtinyX313__)
// ATtiny x313, PORT A is almost useless, left out here
#define PCINT_INPUT_PORT1 PINB
#define PCINT_INPUT_PORT2 PIND

#else // Microcontroller not supported
#error PinChangeInterrupt library does not support this MCU.
#endif

//================================================================================
// Add missing definitions
//================================================================================

// add fakes if ports are not used
#ifndef PCINT_INPUT_PORT0
#define PCINT_INPUT_PORT0 0
#else
#define PCINT_INPUT_PORT0_USED
#endif
#ifndef PCINT_INPUT_PORT1
#define PCINT_INPUT_PORT1 0
#else
#define PCINT_INPUT_PORT1_USED
#endif
#ifndef PCINT_INPUT_PORT2
#define PCINT_INPUT_PORT2 0
#else
#define PCINT_INPUT_PORT2_USED
#endif
#ifndef PCINT_INPUT_PORT3
#define PCINT_INPUT_PORT3 0
#else
#define PCINT_INPUT_PORT3_USED
#endif
