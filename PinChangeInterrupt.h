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
// General Helper Definitions and Mappings
//================================================================================

// Settings and Board definitions are seperated to get an better overview.
// The order and position of the inclusion is important!
#include "PinChangeInterruptSettings.h"
#include "PinChangeInterruptBoards.h"
#include "PinChangeInterruptPins.h"

#if !PCINT_NUM_USED_PORTS
#error Please enable at least one PCINT port!
#endif

// manually include cpp files to save flash if only 1 ISR is present
// it includes all ISR files but only the 1 available ISR will/can be compiled
#if (PCINT_NUM_USED_PORTS == 1)
#ifndef PCINT_COMPILE_ENABLED_ISR
#define PCINT_COMPILE_ENABLED_ISR
#endif
#endif

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions, extern c needed for the alias
extern "C" {
	void pcint_null_callback(void);
}

// map the port to the array position, depending on what ports are activated. this is only usable with port 0-2, not 3
#define PCINT_ARRAY_POS(p) ((PCINT_NUM_USED_PORTS == 3) ? p : (PCINT_NUM_USED_PORTS == 1) ? 0 : \
/*(PCINT_NUM_USED_PORTS == 2)*/ (PCINT_USE_PORT2 == 0) ? p : (PCINT_USE_PORT0 == 0) ? (p - 1) : \
/*(PCINT_USE_PORT1 == 0)*/ ((p >> 1) & 0x01))

// only check enabled + physically available ports. Always choose the port if its the last one that's possible with the current configuration
// not used anymore TODO
#define pinChangeInterruptPortToInput(p) (((PCINT_USE_PORT0 == 1) && ((p == 0) || (PCINT_NUM_USED_PORTS == 1))) ?  PCINT_INPUT_PORT0 :\
	((PCINT_USE_PORT1 == 1) && ((p == 1) || (PCINT_USE_PORT2 == 0))) ?  PCINT_INPUT_PORT1 :\
	((PCINT_USE_PORT2 == 1) /*&& ((p == 2) || (PCINT_NUM_USED_PORTS == 1))*/) ?  PCINT_INPUT_PORT2 : 0)

// generates the callback for easier reordering
#define PCINT_MACRO_BRACKETS ()
#define PCINT_MACRO_TRUE == true)
#define PCINT_CALLBACK(bit, pcint) \
if (PCINT_USE_PCINT ## pcint PCINT_MACRO_TRUE \
if (trigger & (1 << bit)) \
PinChangeInterruptEventPCINT ## pcint PCINT_MACRO_BRACKETS

// missing 1.0.6 definition workaround
#ifndef NOT_AN_INTERRUPT
#define NOT_AN_INTERRUPT -1
#endif

//================================================================================
// User Definitions
//================================================================================

// definition used by the user to create his custom PCINT functions
#define PinChangeInterruptEvent_Wrapper(n) PinChangeInterruptEventPCINT ## n
#define PinChangeInterruptEvent(n) PinChangeInterruptEvent_Wrapper(n)

// convert a normal pin to its PCINT number (0 - max 23), used by the user
// newer version, to work with the event definition above.
#define digitalPinToPinChangeInterruptWrapper(p) PIN_TO_PCINT_ ## p
#define digitalPinToPinChangeInterrupt(p) digitalPinToPinChangeInterruptWrapper(p)
// old version, calculates the pin by the Arduino definitions
#define digitalPinToPinChangeInterruptOld(p) (digitalPinToPCICR(p) ? ((8 * digitalPinToPCICRbit(p)) + digitalPinToPCMSKbit(p)) : NOT_AN_INTERRUPT)

//================================================================================
// Function Prototypes + Variables
//================================================================================

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

extern uint8_t oldPorts[PCINT_NUM_USED_PORTS];
extern uint8_t fallingPorts[PCINT_NUM_USED_PORTS];
extern uint8_t risingPorts[PCINT_NUM_USED_PORTS];

//================================================================================
// Attach Function (partly inlined)
//================================================================================

void attachPinChangeInterruptHelper(const uint8_t pcintNum, const uint8_t mode);
void attachPinChangeInterrupt0(void);
void attachPinChangeInterrupt1(void);
void attachPinChangeInterrupt2(void);

#if defined(PCINT_API)

/*
for (int i = 0; i < 24; i++) {
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

/*
for (int i = 0; i < 24; i++) {
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
static void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode) __attribute__((always_inline));
void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode) {
#else // no API attach function
static void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) __attribute__((always_inline));
void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) {
#endif // PCINT_API

	// check if pcint is a valid pcint, exclude deactivated ports
	// call the fake functions to compile the .cpp files with the ISR
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// port 0
	if (pcintPort == 0 && PCINT_USE_PORT0 == true){
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
	else if (pcintPort == 1 && PCINT_USE_PORT1 == true){
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
	else if (pcintPort == 2 && PCINT_USE_PORT2 == true){
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
	else return;

	// call the actual hardware attach function
	attachPinChangeInterruptHelper(pcintNum, mode);
}
//================================================================================
// Detach Function (partly inlined)
//================================================================================

void detachPinChangeInterruptHelper(const uint8_t pcintNum);
static void detachPinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));

void detachPinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0){
		if (PCINT_USE_PORT0 == false)
			return;
	}
	else if (pcintPort == 1){
		if (PCINT_USE_PORT1 == false)
			return;
	}
	else if (pcintPort == 2){
		if (PCINT_USE_PORT2 == false)
			return;
	}
	else return;

	// call the actual hardware detach function
	detachPinChangeInterruptHelper(pcintNum);
}

#endif // include guard
