/*
Copyright (c) 2014-2018 NicoHood
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

// Include Guard
#pragma once

// Software Version
#define PCINT_VERSION 126

#include <avr/io.h>
#include <avr/interrupt.h>

#ifdef ARDUINO
#include "Arduino.h"

#ifndef ARDUINO_ARCH_AVR
#error This library can only be used with AVR
#endif

#else

#ifndef LOW
#define LOW 0x0
#endif
#ifndef CHANGE
#define CHANGE 0x1
#endif
#ifndef FALLING
#define FALLING 0x2
#endif
#ifndef RISING
#define RISING 0x3
#endif

#endif

//================================================================================
// General Helper Definitions and Mappings
//================================================================================

// Settings and Board definitions are seperated to get an better overview.
// The order and position of the inclusion is important!
#include "PinChangeInterruptSettings.h"
#include "PinChangeInterruptBoards.h"
#include "PinChangeInterruptPins.h"

#if !PCINT_NUM_USED_PORTS
#error Please enable at least one PCINT port and pin!
#endif

// manually include cpp files to save flash if only 1 ISR is present
// it includes all ISR files but only the 1 available ISR will/can be compiled
#if (PCINT_NUM_USED_PORTS == 1)
#ifndef PCINT_COMPILE_ENABLED_ISR
#define PCINT_COMPILE_ENABLED_ISR
#endif
#endif

//================================================================================
// Makro Definitions
//================================================================================

// generates the callback for easier reordering in Settings
#define PCINT_MACRO_BRACKETS ()
#define PCINT_MACRO_TRUE == true)
#define PCINT_CALLBACK(bit, pcint) \
if (PCINT_USE_PCINT ## pcint PCINT_MACRO_TRUE \
if (trigger & (1 << bit)) \
PinChangeInterruptEventPCINT ## pcint PCINT_MACRO_BRACKETS

// definition used by the user to create custom LowLevel PCINT Events
#define PinChangeInterruptEvent_Wrapper(n) PinChangeInterruptEventPCINT ## n
#define PinChangeInterruptEvent(n) PinChangeInterruptEvent_Wrapper(n)

// missing 1.0.6 definition workaround
#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT -1
#endif

// convert a normal pin to its PCINT number (0 - max 23), used by the user
// calculates the pin by the Arduino definitions
#if defined(PCIE0)
#define digitalPinToPinChangeInterrupt(p) (digitalPinToPCICR(p) ? ((8 * (digitalPinToPCICRbit(p) - PCIE0)) + digitalPinToPCMSKbit(p)) : NOT_AN_INTERRUPT)
#elif defined(PCIE)
#define digitalPinToPinChangeInterrupt(p) (digitalPinToPCICR(p) ? ((8 * (digitalPinToPCICRbit(p) - PCIE)) + digitalPinToPCMSKbit(p)) : NOT_AN_INTERRUPT)
#else
#error MCU has no such a register
#endif

// alias for shorter writing
#define PCINTEvent(n) PinChangeInterruptEvent_Wrapper(n)
#define digitalPinToPCINT digitalPinToPinChangeInterrupt
#define attachPCINT attachPinChangeInterrupt
#define enablePCINT enablePinChangeInterrupt
#define detachPCINT detachPinChangeInterrupt
#define disablePCINT disablePinChangeInterrupt
#define getPCINTTrigger getPinChangeInterruptTrigger

//================================================================================
// Function Prototypes + Variables
//================================================================================

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions, extern c needed for the alias
#ifdef __cplusplus
extern "C" {
#endif
    void pcint_null_callback(void);
#ifdef __cplusplus
}
#endif

void PinChangeInterruptEventPCINT0(void);
void PinChangeInterruptEventPCINT1(void);
void PinChangeInterruptEventPCINT2(void);
void PinChangeInterruptEventPCINT3(void);
void PinChangeInterruptEventPCINT4(void);
void PinChangeInterruptEventPCINT5(void);
void PinChangeInterruptEventPCINT6(void);
void PinChangeInterruptEventPCINT7(void);
void PinChangeInterruptEventPCINT8(void);
void PinChangeInterruptEventPCINT9(void);
void PinChangeInterruptEventPCINT10(void);
void PinChangeInterruptEventPCINT11(void);
void PinChangeInterruptEventPCINT12(void);
void PinChangeInterruptEventPCINT13(void);
void PinChangeInterruptEventPCINT14(void);
void PinChangeInterruptEventPCINT15(void);
void PinChangeInterruptEventPCINT16(void);
void PinChangeInterruptEventPCINT17(void);
void PinChangeInterruptEventPCINT18(void);
void PinChangeInterruptEventPCINT19(void);
void PinChangeInterruptEventPCINT20(void);
void PinChangeInterruptEventPCINT21(void);
void PinChangeInterruptEventPCINT22(void);
void PinChangeInterruptEventPCINT23(void);
void PinChangeInterruptEventPCINT24(void);
void PinChangeInterruptEventPCINT25(void);
void PinChangeInterruptEventPCINT26(void);
void PinChangeInterruptEventPCINT27(void);
void PinChangeInterruptEventPCINT28(void);
void PinChangeInterruptEventPCINT29(void);
void PinChangeInterruptEventPCINT30(void);
void PinChangeInterruptEventPCINT31(void);

extern uint8_t oldPorts[PCINT_NUM_USED_PORTS];
extern uint8_t fallingPorts[PCINT_NUM_USED_PORTS];
extern uint8_t risingPorts[PCINT_NUM_USED_PORTS];


static inline uint8_t getArrayPosPCINT(uint8_t pcintPort) __attribute__((always_inline));
uint8_t getArrayPosPCINT(uint8_t pcintPort) {
	/*
	Maps the port to the array.
	This is needed since you can deactivate ports
	and the array will dynamically resize to save ram.

	The function does not need that much flash since the if and else
	are known at compile time, so the compiler removes all the complex logic.
	The return is is the input if all pins are activated for example.
	That's why the function is inline.
	*/

	if (PCINT_NUM_USED_PORTS == 1) {
		// only the first element is used for a single port
		return 0;
	}
	else if (PCINT_NUM_USED_PORTS == PCINT_NUM_PORTS) {
		// use all ports and down remap the array position.
		return pcintPort;
	}
	else if (PCINT_NUM_PORTS - PCINT_NUM_USED_PORTS == 1) {
		// one port is not used
		if (PCINT_USE_PORT0 == 0) {
			// first port is not used, decrease all port numbers
			return (pcintPort - 1);
		}
		else if (PCINT_HAS_PORT3 == 0) {
			// 3 ports (standard)
			if (PCINT_USE_PORT2 == 0) {
				// last port not used, no mapping needed
				return pcintPort;
			}
			else {
				// worst case, port in the middle not used, remap
				return ((pcintPort >> 1) & 0x01);
				//if (pcintPort == 0) return 0;
				//else return 1;
			}
		}
		else {
			// 4 ports (special case for a few AVRs)
			if (PCINT_USE_PORT3 == 0) {
				// last port not used, no mapping needed
				return pcintPort;
			}
			else {
				// worst case, one of two ports in the middle not used, remap
				if (PCINT_USE_PORT1 == 0) {
					// port1 not used, mapping needed
					if (pcintPort == 0)
						return 0;
					else
						return pcintPort - 1;
				}
				else if (PCINT_USE_PORT2 == 0) {
					// port2 not used, mapping needed
					if (pcintPort == 3)
						return 2;
					else
						return pcintPort;
				}
			}
		}

		// use all ports and down remap the array position.
		return pcintPort;
	}
	else if (PCINT_NUM_PORTS - PCINT_NUM_USED_PORTS == 2) {
		if (PCINT_USE_PORT2 == 0 && PCINT_USE_PORT3 == 0) {
			// no need for mapping
			return pcintPort;
		}
		else if (PCINT_USE_PORT0 == 0 && PCINT_USE_PORT3 == 0) {
			// 1 offset
			return (pcintPort - 1);
		}
		else if (PCINT_USE_PORT0 == 0 && PCINT_USE_PORT1 == 0) {
			// 2 offset
			return (pcintPort - 2);
		}
		else if (PCINT_USE_PORT0 == 0 && PCINT_USE_PORT2 == 0) {
			// 2 -> 1
			return (pcintPort >> 1);
		}
		else if (PCINT_USE_PORT1 == 0 && PCINT_USE_PORT2 == 0) {
			// 3 -> 1
			return (pcintPort >> 1);
		}
		else if (PCINT_USE_PORT1 == 0 && PCINT_USE_PORT3 == 0) {
			// 3 -> 1, 1 -> 0
			return (pcintPort >> 1);
		}
	}

	// error
	return 0;
}

//================================================================================
// Attach Function (partly inlined)
//================================================================================

void enablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask, const uint8_t arrayPos);
void attachPinChangeInterrupt0(void);
void attachPinChangeInterrupt1(void);
void attachPinChangeInterrupt2(void);
void attachPinChangeInterrupt3(void);

#if defined(PCINT_API)

/*
for (int i = 0; i < 32; i++) {
Serial.print("#if (PCINT_USE_PCINT");
Serial.print(i);
Serial.println(" == true)");
Serial.print("extern volatile callback callbackPCINT");
Serial.print(i);
Serial.println(";");
Serial.println("#endif");
}
*/
#if (PCINT_USE_PCINT0 == true)
extern volatile callback callbackPCINT0;
#endif
#if (PCINT_USE_PCINT1 == true)
extern volatile callback callbackPCINT1;
#endif
#if (PCINT_USE_PCINT2 == true)
extern volatile callback callbackPCINT2;
#endif
#if (PCINT_USE_PCINT3 == true)
extern volatile callback callbackPCINT3;
#endif
#if (PCINT_USE_PCINT4 == true)
extern volatile callback callbackPCINT4;
#endif
#if (PCINT_USE_PCINT5 == true)
extern volatile callback callbackPCINT5;
#endif
#if (PCINT_USE_PCINT6 == true)
extern volatile callback callbackPCINT6;
#endif
#if (PCINT_USE_PCINT7 == true)
extern volatile callback callbackPCINT7;
#endif
#if (PCINT_USE_PCINT8 == true)
extern volatile callback callbackPCINT8;
#endif
#if (PCINT_USE_PCINT9 == true)
extern volatile callback callbackPCINT9;
#endif
#if (PCINT_USE_PCINT10 == true)
extern volatile callback callbackPCINT10;
#endif
#if (PCINT_USE_PCINT11 == true)
extern volatile callback callbackPCINT11;
#endif
#if (PCINT_USE_PCINT12 == true)
extern volatile callback callbackPCINT12;
#endif
#if (PCINT_USE_PCINT13 == true)
extern volatile callback callbackPCINT13;
#endif
#if (PCINT_USE_PCINT14 == true)
extern volatile callback callbackPCINT14;
#endif
#if (PCINT_USE_PCINT15 == true)
extern volatile callback callbackPCINT15;
#endif
#if (PCINT_USE_PCINT16 == true)
extern volatile callback callbackPCINT16;
#endif
#if (PCINT_USE_PCINT17 == true)
extern volatile callback callbackPCINT17;
#endif
#if (PCINT_USE_PCINT18 == true)
extern volatile callback callbackPCINT18;
#endif
#if (PCINT_USE_PCINT19 == true)
extern volatile callback callbackPCINT19;
#endif
#if (PCINT_USE_PCINT20 == true)
extern volatile callback callbackPCINT20;
#endif
#if (PCINT_USE_PCINT21 == true)
extern volatile callback callbackPCINT21;
#endif
#if (PCINT_USE_PCINT22 == true)
extern volatile callback callbackPCINT22;
#endif
#if (PCINT_USE_PCINT23 == true)
extern volatile callback callbackPCINT23;
#endif
#if (PCINT_USE_PCINT24 == true)
extern volatile callback callbackPCINT24;
#endif
#if (PCINT_USE_PCINT25 == true)
extern volatile callback callbackPCINT25;
#endif
#if (PCINT_USE_PCINT26 == true)
extern volatile callback callbackPCINT26;
#endif
#if (PCINT_USE_PCINT27 == true)
extern volatile callback callbackPCINT27;
#endif
#if (PCINT_USE_PCINT28 == true)
extern volatile callback callbackPCINT28;
#endif
#if (PCINT_USE_PCINT29 == true)
extern volatile callback callbackPCINT29;
#endif
#if (PCINT_USE_PCINT30 == true)
extern volatile callback callbackPCINT30;
#endif
#if (PCINT_USE_PCINT31 == true)
extern volatile callback callbackPCINT31;
#endif

/*
for (int i = 0; i < 32; i++) {
Serial.print("#if (PCINT_USE_PCINT");
Serial.print(i);
Serial.println(" == true)");
Serial.print("if (pcintNum == ");
Serial.print(i);
Serial.println(")");
Serial.print("callbackPCINT");
Serial.print(i);
Serial.println(" = userFunc;");
Serial.println("#endif");
}
*/

// API attach function
static inline void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode) __attribute__((always_inline));
void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode) {
#else // no API attach function
static inline void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) __attribute__((always_inline));
void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) {
#endif // PCINT_API

	// check if pcint is a valid pcint, exclude deactivated ports
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// port 0
	if (pcintPort == 0 && PCINT_USE_PORT0 == true) {
		// use fake functions to make the ISRs compile with .a linkage
#if defined(PCINT_ALINKAGE) && !defined(PCINT_COMPILE_ENABLED_ISR)
		attachPinChangeInterrupt0();
#endif

		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT0 == true)
		if (pcintNum == 0)
			callbackPCINT0 = userFunc;
#endif
#if (PCINT_USE_PCINT1 == true)
		if (pcintNum == 1)
			callbackPCINT1 = userFunc;
#endif
#if (PCINT_USE_PCINT2 == true)
		if (pcintNum == 2)
			callbackPCINT2 = userFunc;
#endif
#if (PCINT_USE_PCINT3 == true)
		if (pcintNum == 3)
			callbackPCINT3 = userFunc;
#endif
#if (PCINT_USE_PCINT4 == true)
		if (pcintNum == 4)
			callbackPCINT4 = userFunc;
#endif
#if (PCINT_USE_PCINT5 == true)
		if (pcintNum == 5)
			callbackPCINT5 = userFunc;
#endif
#if (PCINT_USE_PCINT6 == true)
		if (pcintNum == 6)
			callbackPCINT6 = userFunc;
#endif
#if (PCINT_USE_PCINT7 == true)
		if (pcintNum == 7)
			callbackPCINT7 = userFunc;
#endif
#endif // PCINT_API
	}

	// port 1
	else if (pcintPort == 1 && PCINT_USE_PORT1 == true) {
		// use fake functions to make the ISRs compile with .a linkage
#if defined(PCINT_ALINKAGE) && !defined(PCINT_COMPILE_ENABLED_ISR)
		attachPinChangeInterrupt1();
#endif

		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT8 == true)
		if (pcintNum == 8)
			callbackPCINT8 = userFunc;
#endif
#if (PCINT_USE_PCINT9 == true)
		if (pcintNum == 9)
			callbackPCINT9 = userFunc;
#endif
#if (PCINT_USE_PCINT10 == true)
		if (pcintNum == 10)
			callbackPCINT10 = userFunc;
#endif
#if (PCINT_USE_PCINT11 == true)
		if (pcintNum == 11)
			callbackPCINT11 = userFunc;
#endif
#if (PCINT_USE_PCINT12 == true)
		if (pcintNum == 12)
			callbackPCINT12 = userFunc;
#endif
#if (PCINT_USE_PCINT13 == true)
		if (pcintNum == 13)
			callbackPCINT13 = userFunc;
#endif
#if (PCINT_USE_PCINT14 == true)
		if (pcintNum == 14)
			callbackPCINT14 = userFunc;
#endif
#if (PCINT_USE_PCINT15 == true)
		if (pcintNum == 15)
			callbackPCINT15 = userFunc;
#endif
#endif // PCINT_API
	}

	// port 2
	else if (pcintPort == 2 && PCINT_USE_PORT2 == true) {
		// use fake functions to make the ISRs compile with .a linkage
#if defined(PCINT_ALINKAGE) && !defined(PCINT_COMPILE_ENABLED_ISR)
		attachPinChangeInterrupt2();
#endif
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT16 == true)
		if (pcintNum == 16)
			callbackPCINT16 = userFunc;
#endif
#if (PCINT_USE_PCINT17 == true)
		if (pcintNum == 17)
			callbackPCINT17 = userFunc;
#endif
#if (PCINT_USE_PCINT18 == true)
		if (pcintNum == 18)
			callbackPCINT18 = userFunc;
#endif
#if (PCINT_USE_PCINT19 == true)
		if (pcintNum == 19)
			callbackPCINT19 = userFunc;
#endif
#if (PCINT_USE_PCINT20 == true)
		if (pcintNum == 20)
			callbackPCINT20 = userFunc;
#endif
#if (PCINT_USE_PCINT21 == true)
		if (pcintNum == 21)
			callbackPCINT21 = userFunc;
#endif
#if (PCINT_USE_PCINT22 == true)
		if (pcintNum == 22)
			callbackPCINT22 = userFunc;
#endif
#if (PCINT_USE_PCINT23 == true)
		if (pcintNum == 23)
			callbackPCINT23 = userFunc;
#endif
#endif // PCINT_API
	}

	// port 3
	else if (pcintPort == 3 && PCINT_USE_PORT3 == true) {
		// use fake functions to make the ISRs compile with .a linkage
#if defined(PCINT_ALINKAGE) && !defined(PCINT_COMPILE_ENABLED_ISR)
		attachPinChangeInterrupt3();
#endif
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT24 == true)
		if (pcintNum == 24)
			callbackPCINT24 = userFunc;
#endif
#if (PCINT_USE_PCINT25 == true)
		if (pcintNum == 25)
			callbackPCINT25 = userFunc;
#endif
#if (PCINT_USE_PCINT26 == true)
		if (pcintNum == 26)
			callbackPCINT26 = userFunc;
#endif
#if (PCINT_USE_PCINT27 == true)
		if (pcintNum == 27)
			callbackPCINT27 = userFunc;
#endif
#if (PCINT_USE_PCINT28 == true)
		if (pcintNum == 28)
			callbackPCINT28 = userFunc;
#endif
#if (PCINT_USE_PCINT29 == true)
		if (pcintNum == 29)
			callbackPCINT29 = userFunc;
#endif
#if (PCINT_USE_PCINT30 == true)
		if (pcintNum == 30)
			callbackPCINT30 = userFunc;
#endif
#if (PCINT_USE_PCINT31 == true)
		if (pcintNum == 31)
			callbackPCINT31 = userFunc;
#endif
#endif // PCINT_API
	}
	else return;

	// get bitmask and array position
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// save settings related to mode and registers
	if (mode == CHANGE || mode == RISING)
		risingPorts[arrayPos] |= pcintMask;
	if (mode == CHANGE || mode == FALLING)
		fallingPorts[arrayPos] |= pcintMask;

	// call the actual hardware attach function
	enablePinChangeInterruptHelper(pcintPort, pcintMask, arrayPos);
}

// enable interrupt again if temporary disabled
static inline void enablePinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));
void enablePinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0) {
		if (PCINT_USE_PORT0 == false)
			return;
	}
	else if (pcintPort == 1) {
		if (PCINT_USE_PORT1 == false)
			return;
	}
	else if (pcintPort == 2) {
		if (PCINT_USE_PORT2 == false)
			return;
	}
	else if (pcintPort == 3) {
		if (PCINT_USE_PORT3 == false)
			return;
	}
	else return;

	// call the actual hardware attach function
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);
	enablePinChangeInterruptHelper(pcintPort, pcintMask, arrayPos);
}


//================================================================================
// Detach Function (partly inlined)
//================================================================================

void disablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask);
static inline void detachPinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));

void detachPinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	// port 0
	if (pcintPort == 0 && PCINT_USE_PORT0 == true) {
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT0 == true)
		if (pcintNum == 0)
			callbackPCINT0 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT1 == true)
		if (pcintNum == 1)
			callbackPCINT1 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT2 == true)
		if (pcintNum == 2)
			callbackPCINT2 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT3 == true)
		if (pcintNum == 3)
			callbackPCINT3 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT4 == true)
		if (pcintNum == 4)
			callbackPCINT4 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT5 == true)
		if (pcintNum == 5)
			callbackPCINT5 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT6 == true)
		if (pcintNum == 6)
			callbackPCINT6 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT7 == true)
		if (pcintNum == 7)
			callbackPCINT7 = pcint_null_callback;
#endif
#endif // PCINT_API
	}

	// port 1
	else if (pcintPort == 1 && PCINT_USE_PORT1 == true) {
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT8 == true)
		if (pcintNum == 8)
			callbackPCINT8 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT9 == true)
		if (pcintNum == 9)
			callbackPCINT9 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT10 == true)
		if (pcintNum == 10)
			callbackPCINT10 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT11 == true)
		if (pcintNum == 11)
			callbackPCINT11 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT12 == true)
		if (pcintNum == 12)
			callbackPCINT12 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT13 == true)
		if (pcintNum == 13)
			callbackPCINT13 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT14 == true)
		if (pcintNum == 14)
			callbackPCINT14 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT15 == true)
		if (pcintNum == 15)
			callbackPCINT15 = pcint_null_callback;
#endif
#endif // PCINT_API
	}

	// port 2
	else if (pcintPort == 2 && PCINT_USE_PORT2 == true) {
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT16 == true)
		if (pcintNum == 16)
			callbackPCINT16 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT17 == true)
		if (pcintNum == 17)
			callbackPCINT17 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT18 == true)
		if (pcintNum == 18)
			callbackPCINT18 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT19 == true)
		if (pcintNum == 19)
			callbackPCINT19 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT20 == true)
		if (pcintNum == 20)
			callbackPCINT20 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT21 == true)
		if (pcintNum == 21)
			callbackPCINT21 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT22 == true)
		if (pcintNum == 22)
			callbackPCINT22 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT23 == true)
		if (pcintNum == 23)
			callbackPCINT23 = pcint_null_callback;
#endif
#endif // PCINT_API
	}

	// port 3
	else if (pcintPort == 3 && PCINT_USE_PORT3 == true) {
		//  attache the function pointers for the API
#if defined(PCINT_API)
#if (PCINT_USE_PCINT24 == true)
		if (pcintNum == 24)
			callbackPCINT24 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT25 == true)
		if (pcintNum == 25)
			callbackPCINT25 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT26 == true)
		if (pcintNum == 26)
			callbackPCINT26 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT27 == true)
		if (pcintNum == 27)
			callbackPCINT27 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT28 == true)
		if (pcintNum == 28)
			callbackPCINT28 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT29 == true)
		if (pcintNum == 29)
			callbackPCINT29 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT30 == true)
		if (pcintNum == 30)
			callbackPCINT30 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT31 == true)
		if (pcintNum == 31)
			callbackPCINT31 = pcint_null_callback;
#endif
#endif // PCINT_API
	}
	else return;

	// get bitmask and array position
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// delete setting
	risingPorts[arrayPos] &= ~pcintMask;
	fallingPorts[arrayPos] &= ~pcintMask;

	// call the actual hardware disable function
	disablePinChangeInterruptHelper(pcintPort, pcintMask);
}

static inline void disablePinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));
void disablePinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0) {
		if (PCINT_USE_PORT0 == false)
			return;
	}
	else if (pcintPort == 1) {
		if (PCINT_USE_PORT1 == false)
			return;
	}
	else if (pcintPort == 2) {
		if (PCINT_USE_PORT2 == false)
			return;
	}
	else if (pcintPort == 3) {
		if (PCINT_USE_PORT3 == false)
			return;
	}
	else return;

	// get bitmask
	uint8_t pcintMask = (1 << pcintBit);

	// Do not delete mode settings nor detach the user function
	// Just turn off interrupts

	// call the actual hardware disable function
	disablePinChangeInterruptHelper(pcintPort, pcintMask);
}

//================================================================================
// getTrigger Function (inlined)
//================================================================================

static inline uint8_t getPinChangeInterruptTrigger(const uint8_t pcintNum) __attribute__((always_inline));
uint8_t getPinChangeInterruptTrigger(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0) {
		if (PCINT_USE_PORT0 == false)
			return CHANGE;
	}
	else if (pcintPort == 1) {
		if (PCINT_USE_PORT1 == false)
			return CHANGE;
	}
	else if (pcintPort == 2) {
		if (PCINT_USE_PORT2 == false)
			return CHANGE;
	}
	else if (pcintPort == 3) {
		if (PCINT_USE_PORT3 == false)
			return CHANGE;
	}
	else return CHANGE;

	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// Check if no mode was set, return an error
	if(!(risingPorts[arrayPos] & (1 << pcintBit)) && !(fallingPorts[arrayPos] & (1 << pcintBit)))
		return CHANGE;

	// specify the CHANGE mode
	if (oldPorts[arrayPos] & (1 << pcintBit))
		return RISING;
	else
		return FALLING;
}
