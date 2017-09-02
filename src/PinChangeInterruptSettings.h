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
// General Settings
//================================================================================

/* Settings to de/activate ports/pins
This will save you flash and ram because the arrays
are managed dynamically with the definitions below.
Make sure you still have all needed ports activated.
Each deactivated port saves 3 bytes of ram.
If you deactivate the whole port,
you dont need to deactivate the pins.
Same for the port if you deactivate all 8 pins.
You dont have to deactivate pins/ports that dont exist.
That is done by the macros. */

#ifndef PCINT_ENABLE_MANUAL

#define PCINT_ENABLE_PORT0
#define PCINT_ENABLE_PORT1
#define PCINT_ENABLE_PORT2
#define PCINT_ENABLE_PORT3

#define PCINT_ENABLE_PCINT0
#define PCINT_ENABLE_PCINT1
#define PCINT_ENABLE_PCINT2
#define PCINT_ENABLE_PCINT3
#define PCINT_ENABLE_PCINT4
#define PCINT_ENABLE_PCINT5
#define PCINT_ENABLE_PCINT6
#define PCINT_ENABLE_PCINT7
#define PCINT_ENABLE_PCINT8
#define PCINT_ENABLE_PCINT9
#define PCINT_ENABLE_PCINT10
#define PCINT_ENABLE_PCINT11
#define PCINT_ENABLE_PCINT12
#define PCINT_ENABLE_PCINT13
#define PCINT_ENABLE_PCINT14
#define PCINT_ENABLE_PCINT15
#define PCINT_ENABLE_PCINT16
#define PCINT_ENABLE_PCINT17
#define PCINT_ENABLE_PCINT18
#define PCINT_ENABLE_PCINT19
#define PCINT_ENABLE_PCINT20
#define PCINT_ENABLE_PCINT21
#define PCINT_ENABLE_PCINT22
#define PCINT_ENABLE_PCINT23
#define PCINT_ENABLE_PCINT24
#define PCINT_ENABLE_PCINT25
#define PCINT_ENABLE_PCINT26
#define PCINT_ENABLE_PCINT27
#define PCINT_ENABLE_PCINT28
#define PCINT_ENABLE_PCINT29
#define PCINT_ENABLE_PCINT30
#define PCINT_ENABLE_PCINT31

#endif

#ifdef ARDUINO
// use API with function pointers (better optimized with .a linkage)
#define PCINT_API

// is the library compiled via .a file?
// see readme for more information
#define PCINT_ALINKAGE

// force compile all enabled port ISRs (with .a linkage)
//#define PCINT_COMPILE_ENABLED_ISR

#endif

//================================================================================
// Suggested Settings
//================================================================================

// Arduino Uno (328)
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
/* Reordering interrupt callbacks priority
Port0 has SPI on higher pins, ordering is fine
Port1 has I2C on higher pins, ordering is fine
Port2 has USART and Pin Interrupt on lower pins,
move the priority down
Its more likely the user will use pin 4-7
*/
#if !defined(PCINT_CALLBACK_PORT2)
#define PCINT_CALLBACK_PORT2 \
PCINT_CALLBACK(4, 20); \
PCINT_CALLBACK(5, 21); \
PCINT_CALLBACK(6, 22); \
PCINT_CALLBACK(7, 23); \
PCINT_CALLBACK(0, 16); /* USART RX */ \
PCINT_CALLBACK(1, 17); /* USART TX */ \
PCINT_CALLBACK(2, 18); /* Pin Interrupt 0 */ \
PCINT_CALLBACK(3, 19); /* Pin Interrupt 1 */
#endif

// deactivate crystal and reset pins by default
#if defined(PCINT_ENABLE_PCINT6)
#undef PCINT_ENABLE_PCINT6 // crystal
#endif
#if defined(PCINT_ENABLE_PCINT7)
#undef PCINT_ENABLE_PCINT7 // crystal
#endif
#if defined(PCINT_ENABLE_PCINT14)
#undef PCINT_ENABLE_PCINT14 // reset
#endif
#endif

// Arduino Mega (2560)
#if defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MEGA)
/* Port1 is structured a bit more complicated
Also only 3 pins are connected on standard boards
Seeeduino Mega has these pins optional!
Disabling Port1 gives more speed and uses less flash
Pins: 0(RX0), 14(TX3), 15(RX3) */
#if defined(PCINT_ENABLE_PORT1)
#undef PCINT_ENABLE_PORT1 // better performence
#endif

/* Reordering interrupt callbacks priority
Port2 has SPI on lower pins, move the priority down
Its more likely the user will use pin 10-13
Port1 by default deactivated, ordering is fine
Port2 only has ADCs, ordering is fine
*/
#if !defined(PCINT_CALLBACK_PORT0)
#define PCINT_CALLBACK_PORT0 \
PCINT_CALLBACK(4, 4); \
PCINT_CALLBACK(5, 5); \
PCINT_CALLBACK(6, 6); \
PCINT_CALLBACK(7, 7); \
PCINT_CALLBACK(0, 0); /* SPI SS */ \
PCINT_CALLBACK(1, 1); /* SPI SCK */ \
PCINT_CALLBACK(2, 2); /* SPI MISO */ \
PCINT_CALLBACK(3, 3); /* SPI MOSI */
#endif
#endif

// Arduino Leonardo/Micro (32u4)
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
/* Reordering interrupt callbacks priority
Port0 has SPI on lower pins, move the priority down
Its more likely the user will use pin 8-11 */
#if !defined(PCINT_CALLBACK_PORT0)
#define PCINT_CALLBACK_PORT0 \
PCINT_CALLBACK(4, 4); \
PCINT_CALLBACK(5, 5); \
PCINT_CALLBACK(6, 6); \
PCINT_CALLBACK(7, 7); \
PCINT_CALLBACK(0, 0); /* SPI SS / RX LED */ \
PCINT_CALLBACK(1, 1); /* SPI SCK */ \
PCINT_CALLBACK(2, 2); /* SPI MISO */ \
PCINT_CALLBACK(3, 3); /* SPI MOSI */
#endif

// RX LED on normal leonardo/micro
#if defined(PCINT_ENABLE_PCINT0) && (defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_MICRO))
#undef PCINT_ENABLE_PCINT0
#endif
#endif

// Hoodloader2 (u2 Series)
#if defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
#if defined(ARDUINO_HOODLOADER2)
// on HoodLoader2 Arduino boards only PB1-7 (port0) is broken out, save this flash
#if defined(PCINT_ENABLE_PORT1)
#undef PCINT_ENABLE_PORT1
#endif

// SS (PB0) is not connected on normal Arduino boards
#if defined(PCINT_ENABLE_PCINT0)
#undef PCINT_ENABLE_PCINT0
#endif

/* Reordering interrupt callbacks priority
Port0 has SPI on lower pins, move the priority down
Its more likely the user will use PB4-7
Pretend the User has not soldered the 4 Pinheader
so only do this for non Arduino boards. */
#else
#if !defined(PCINT_CALLBACK_PORT0)
#define PCINT_CALLBACK_PORT0 \
PCINT_CALLBACK(4, 4); \
PCINT_CALLBACK(5, 5); \
PCINT_CALLBACK(6, 6); \
PCINT_CALLBACK(7, 7); \
PCINT_CALLBACK(0, 0); /* SPI SS */ \
PCINT_CALLBACK(1, 1); /* SPI SCK */ \
PCINT_CALLBACK(2, 2); /* SPI MISO */ \
PCINT_CALLBACK(3, 3); /* SPI MOSI */
#endif
#endif
#endif

/* Attiny 25/45/85 only has a very few pins
activate all by default
The order is also okay. */

#if defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
// Port1 is connected to reset, crystal and Pin Interrupt 0
// Deactivate it by default
#if defined(PCINT_ENABLE_PORT1)
#undef PCINT_ENABLE_PORT1
#endif
#endif
