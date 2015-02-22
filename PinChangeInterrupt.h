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


#ifndef PINCHANGEINTERRUPT_H
#define PINCHANGEINTERRUPT_H

#include "Arduino.h"

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

#define PCINT_ENABLE_PORT0
#define PCINT_ENABLE_PORT1
#define PCINT_ENABLE_PORT2

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

#if defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
// Port1 is connected to reset, crystal and Pin Interrupt 0
// deactivate it by default
#if defined(PCINT_ENABLE_PCINT1)
#undef PCINT_ENABLE_PCINT1
#endif
#endif

//================================================================================
// General Helper Definitions and Mappings
//================================================================================

// Board definitions are seperated to get an better overview.
#include "PinChangeInterruptBoards.h"

#if !PCINT_NUM_USED_PORTS
#error Please enable at least one PCINT port!
#endif

// map the port to the array position, depending on what ports are activated. this is only usable with port 0-2, not 3
#define PCINT_ARRAY_POS(p) ((PCINT_NUM_USED_PORTS == 3) ? p : (PCINT_NUM_USED_PORTS == 1) ? 0 : \
/*(PCINT_NUM_USED_PORTS == 2)*/ (PCINT_USE_PORT2 == 0) ? p : (PCINT_USE_PORT0 == 0) ? (p - 1) : \
/*(PCINT_USE_PORT1 == 0)*/ ((p >> 1) & 0x01))

// only check enabled + physically available ports. Always choose the port if its the last one that's possible with the current configuration
// not used anymore
#define pinChangeInterruptPortToInput(p) (((PCINT_USE_PORT0 == 1) && ((p == 0) || (PCINT_NUM_USED_PORTS == 1))) ?  PCINT_INPUT_PORT0 :\
	((PCINT_USE_PORT1 == 1) && ((p == 1) || (PCINT_USE_PORT2 == 0))) ?  PCINT_INPUT_PORT1 :\
	((PCINT_USE_PORT2 == 1) /*&& ((p == 2) || (PCINT_NUM_USED_PORTS == 1))*/) ?  PCINT_INPUT_PORT2 : 0)

// generates the callback for easier reordering
#define PCINT_MACRO_BRACKETS ()
#define PCINT_MACRO_TRUE == true)
#define PCINT_CALLBACK(bit, pcint) \
if (PCINT_USE_PCINT ## pcint PCINT_MACRO_TRUE \
if (trigger & (1 << bit)) \
pcint_callback_ptr_ ## pcint PCINT_MACRO_BRACKETS

// missing 1.0.6 definition workaround
#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT -1
#endif

//================================================================================
// User Definitions
//================================================================================

// definition used by the user to create his custom PCINT functions
#define PinChangeInterruptEvent_Wrapper(n) pcint_callback_ptr_ ## n
#define PinChangeInterruptEvent(n) PinChangeInterruptEvent_Wrapper(n)

// convert a normal pin to its PCINT number (0 - max 23), used by the user
// newer version, to work with the event definition above.
#define digitalPinToPinChangeInterruptWrapper(p) PIN_TO_PCINT_ ## p
#define digitalPinToPinChangeInterrupt(p) digitalPinToPinChangeInterruptWrapper(p)
// old version, calculates the pin by the Arduino definitions
#define digitalPinToPinChangeInterruptOld(p) (digitalPinToPCICR(p) ? ((8 * digitalPinToPCICRbit(p)) + digitalPinToPCMSKbit(p)) : NOT_AN_INTERRUPT)

//================================================================================
// Function Prototypes
//================================================================================

void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode);
void detachPinChangeInterrupt(const uint8_t pcintNum);

#endif // include guard
