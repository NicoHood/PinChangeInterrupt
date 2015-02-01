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


#ifndef PINCHANGEINTERRUPT_H
#define PINCHANGEINTERRUPT_H

#include "Arduino.h"

//================================================================================
// Settings
//================================================================================

// Settings to de/activate ports
// This will save you flash and ram because the arrays are managed dynamically with the definitions below.
// Make sure you still have all needed ports activated. Each deactivated port saves 3 bytes ram.
#define PCINT_PORT0_ENABLED
#define PCINT_PORT1_ENABLED
#define PCINT_PORT2_ENABLED
// ISR 3 not implemented in this library
//#define PCINT_PORT3_ENABLED

//================================================================================
// Disable Definitions
//================================================================================

// on HoodLoader2 Arduino boards only PB (port0) is broken out, save this flash
#if defined(ARDUINO_HOODLOADER2)
#define PCINT_PORT1_DISABLED
#endif

// ISR 3 not implemented in this library
#define PCINT_PORT3_DISABLED

// disabling ports is stronger than enabling
#if defined(PCINT_PORT0_DISABLED)
#undef PCINT_PORT0_ENABLED
#endif
#if defined(PCINT_PORT1_DISABLED)
#undef PCINT_PORT1_ENABLED
#endif
#if defined(PCINT_PORT2_DISABLED)
#undef PCINT_PORT2_ENABLED
#endif
#if defined(PCINT_PORT3_DISABLED)
#undef PCINT_PORT3_ENABLED
#endif

//================================================================================
// Board Definitions
//================================================================================

/*
Board definitions are seperated to get an better overview.

These values are defined here:
EXTERNAL_NUM_PINCHANGEINTERRUPT
PCINT_INPUT0-2
PIN_TO_PCINT_0-23
*/
#include "PinChangeInterruptBoards.h"

//================================================================================
// General Definitions and Mappings
//================================================================================

// add fakes if ports are not used
#ifndef PCINT_INPUT0
#define PCINT_INPUT0 0
#endif
#ifndef PCINT_INPUT1
#define PCINT_INPUT1 0
#endif
#ifndef PCINT_INPUT2
#define PCINT_INPUT2 0
#endif
#ifndef PCINT_INPUT3
#define PCINT_INPUT3 0
#endif

// if ports are enabled and physically available add them together so we can calculate some fancy stuff below
#if defined(PCINT0_vect) && defined(PCINT_PORT0_ENABLED)
#define PCINT_PORT0 1
#else
#define PCINT_PORT0 0
#endif
#if defined(PCINT1_vect) && defined(PCINT_PORT1_ENABLED)
#define PCINT_PORT1 1
#else
#define PCINT_PORT1 0
#endif
#if defined(PCINT2_vect) && defined(PCINT_PORT2_ENABLED)
#define PCINT_PORT2 1
#else
#define PCINT_PORT2 0
#endif
#if defined(PCINT3_vect) && defined(PCINT_PORT3_ENABLED)
// you have to change the PCINT_ARRAY_POS(p) and pinChangeInterruptPortToInput(p) definition if you want to use port3
#error Please do not enable PCINT port3, it is not supported! If you still try to remove this error the library wont work.
#define PCINT_PORT3 1
#else
#define PCINT_PORT3 0
#endif

// calculate the number of ports used
#define PCINT_ENABLED_PORTS (PCINT_PORT0 + PCINT_PORT1 + PCINT_PORT2 + PCINT_PORT3)
#if (PCINT_ENABLED_PORTS == 0)
#error Please enable at least one PCINT port!
#endif

// map the port to the array position, depending on what ports are activated. this is only usable with port 0-2, not 3
#define PCINT_ARRAY_POS(p) ((PCINT_ENABLED_PORTS == 3) ? p : (PCINT_ENABLED_PORTS == 1) ? 0 : \
/*(PCINT_ENABLED_PORTS == 2)*/ (PCINT_PORT2 == 0) ? p : (PCINT_PORT0 == 0) ? (p - 1) : \
/*(PCINT_PORT1 == 0)*/ ((p >> 1) & 0x01))

// only check enabled + physically available ports. Always choose the port if its the last one that's possible with the current configuration
#define pinChangeInterruptPortToInput(p) (((PCINT_PORT0 == 1) && ((p == 0) || (PCINT_ENABLED_PORTS == 1))) ?  PCINT_INPUT0 :\
	((PCINT_PORT1 == 1) && ((p == 1) || (PCINT_PORT2 == 0))) ?  PCINT_INPUT1 :\
	((PCINT_PORT2 == 1) /*&& ((p == 2) || (PCINT_ENABLED_PORTS == 1))*/) ?  PCINT_INPUT2 : 0)

// define maximum number of PCINT ports (1-3)
#define PCINT_PORTS (((EXTERNAL_NUM_PINCHANGEINTERRUPT - 1) / 8) + 1)

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
// PinChangeInterrupt User Functions
//================================================================================

// variables to save the last port states and the interrupt settings
extern uint8_t oldPorts[PCINT_ENABLED_PORTS];
extern uint8_t fallingPorts[PCINT_ENABLED_PORTS];
extern uint8_t risingPorts[PCINT_ENABLED_PORTS];

inline void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) {
	// get PCINT registers and bitmask
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintMask = (1 << (pcintNum % 8));

	// check if pcint is a valid pcint, exclude deactivated ports
	if (!(pcintNum < EXTERNAL_NUM_PINCHANGEINTERRUPT))
		return;
#if defined(PCINT0_vect) && !defined(PCINT_PORT0_ENABLED)
	if (pcintPort == 0) return;
#endif
#if defined(PCINT1_vect) && !defined(PCINT_PORT1_ENABLED)
	if (pcintPort == 1) return;
#endif
#if defined(PCINT2_vect) && !defined(PCINT_PORT2_ENABLED)
	if (pcintPort == 2) return;
#endif

	// save settings related to mode and registers
	if (mode == CHANGE || mode == RISING)
		risingPorts[pcintPort] |= pcintMask;
	if (mode == CHANGE || mode == FALLING)
		fallingPorts[pcintPort] |= pcintMask;

	// update the old state to the actual state
	oldPorts[pcintPort] = *portInputRegister(digitalPinToPort(pcintNum));

	// pin change mask registers decide which pins are enabled as triggers
	*(&PCMSK0 + pcintPort) |= pcintMask;

	// PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
	PCICR |= (1 << pcintPort);
}

inline void detachPinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers and bitmask
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintMask = (1 << (pcintNum % 8));

	// check if pcint is a valid pcint, exclude deactivated ports
	if (!(pcintNum < EXTERNAL_NUM_PINCHANGEINTERRUPT))
		return;
#if defined(PCINT0_vect) && !defined(PCINT_PORT0_ENABLED)
	if (pcintPort == 0) return;
#endif
#if defined(PCINT1_vect) && !defined(PCINT_PORT1_ENABLED)
	if (pcintPort == 1) return;
#endif
#if defined(PCINT2_vect) && !defined(PCINT_PORT2_ENABLED)
	if (pcintPort == 2) return;
#endif

	// delete setting
	risingPorts[pcintPort] &= ~pcintMask;
	fallingPorts[pcintPort] &= ~pcintMask;

	// disable the mask.
	*(&PCMSK0 + pcintPort) &= ~pcintMask;

	// if that's the last one, disable the interrupt.
	if (*(&PCMSK0 + pcintPort) == 0)
		PCICR &= ~(1 << pcintPort);
}

#endif // include guard

