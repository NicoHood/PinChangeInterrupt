/*
Copyright (c) 2014-2021 NicoHood
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
// Interrupt Handler
//================================================================================

// prevent compilation twice if included from the .cpp to force compile all ISRs
#if defined(PCINT_ALINKAGE) && defined(PCINT_COMPILE_ENABLED_ISR) && defined(PCINT_INCLUDE_FROM_CPP) \
	|| !defined(PCINT_ALINKAGE) || !defined(PCINT_COMPILE_ENABLED_ISR)

#if (PCINT_USE_PORT0 == true)

void attachPinChangeInterrupt0(void) {
	// fake function to make the IDE link this file
}
#ifdef PCINT_COMBINE_PORT0_PORT1
void attachPinChangeInterrupt1(void) {
	// fake function to make the IDE link this file
}
#endif

#ifdef PCINT_COMBINE_PORT0_PORT1
ISR(PCINT_vect) {
#else
ISR(PCINT0_vect) {
#endif
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT0;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = getArrayPosPCINT(0);
	uint8_t change = newPort ^ oldPorts[arrayPos];
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[arrayPos];

	// check which pins are triggered, compared with the settings
	uint8_t risingTrigger = rising & risingPorts[arrayPos];
	uint8_t fallingTrigger = falling & fallingPorts[arrayPos];
	uint8_t trigger = risingTrigger | fallingTrigger;

	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;

	// Execute all functions that should be triggered
	// This way we can exclude a single function
	// and the calling is also much faster
	// We may also reorder the pins for different priority
#if !defined(PCINT_CALLBACK_PORT0)
	PCINT_CALLBACK(0, 0);
	PCINT_CALLBACK(1, 1);
	PCINT_CALLBACK(2, 2);
	PCINT_CALLBACK(3, 3);
	PCINT_CALLBACK(4, 4);
	PCINT_CALLBACK(5, 5);
	PCINT_CALLBACK(6, 6);
	PCINT_CALLBACK(7, 7);
#else
	PCINT_CALLBACK_PORT0
#endif

#if defined(PCINT_COMBINE_PORT0_PORT1) && (PCINT_USE_PORT1 == true)
	// get the new and old pin states for port
	newPort = PCINT_INPUT_PORT1;

	// compare with the old value to detect a rising or falling
	arrayPos = getArrayPosPCINT(1);
	change = newPort ^ oldPorts[arrayPos];
	rising = change & newPort;
	falling = change & oldPorts[arrayPos];

	// check which pins are triggered, compared with the settings
	risingTrigger = rising & risingPorts[arrayPos];
	fallingTrigger = falling & fallingPorts[arrayPos];
	trigger = risingTrigger | fallingTrigger;

	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;

	// Execute all functions that should be triggered
	// This way we can exclude a single function
	// and the calling is also much faster
	// We may also reorder the pins for different priority
#if !defined(PCINT_CALLBACK_PORT1)
	PCINT_CALLBACK(0, 8);
	PCINT_CALLBACK(1, 9);
	PCINT_CALLBACK(2, 10);
	PCINT_CALLBACK(3, 11);
	PCINT_CALLBACK(4, 12);
	PCINT_CALLBACK(5, 13);
	PCINT_CALLBACK(6, 14);
	PCINT_CALLBACK(7, 15);
#else
	PCINT_CALLBACK_PORT1
#endif
#endif // defined(PCINT_COMBINE_PORT0_PORT1) && (PCINT_USE_PORT1 == true)
}

#if defined(PCINT_API)

/*
for (int i = 0; i < 32; i++) {
Serial.print("#if (PCINT_USE_PCINT");
Serial.print(i);
Serial.println(" == true)");
Serial.print("volatile callback callbackPCINT");
Serial.print(i);
Serial.println(" = pcint_null_callback;");
Serial.print("void PinChangeInterruptEventPCINT");
Serial.print(i);
Serial.println("(void){");
Serial.print("	callbackPCINT");
Serial.print(i);
Serial.println("();");
Serial.println("}");
Serial.println("#endif");
}
*/
#if (PCINT_USE_PCINT0 == true)
volatile callback callbackPCINT0 = pcint_null_callback;
void PinChangeInterruptEventPCINT0(void) {
	callbackPCINT0();
}
#endif
#if (PCINT_USE_PCINT1 == true)
volatile callback callbackPCINT1 = pcint_null_callback;
void PinChangeInterruptEventPCINT1(void) {
	callbackPCINT1();
}
#endif
#if (PCINT_USE_PCINT2 == true)
volatile callback callbackPCINT2 = pcint_null_callback;
void PinChangeInterruptEventPCINT2(void) {
	callbackPCINT2();
}
#endif
#if (PCINT_USE_PCINT3 == true)
volatile callback callbackPCINT3 = pcint_null_callback;
void PinChangeInterruptEventPCINT3(void) {
	callbackPCINT3();
}
#endif
#if (PCINT_USE_PCINT4 == true)
volatile callback callbackPCINT4 = pcint_null_callback;
void PinChangeInterruptEventPCINT4(void) {
	callbackPCINT4();
}
#endif
#if (PCINT_USE_PCINT5 == true)
volatile callback callbackPCINT5 = pcint_null_callback;
void PinChangeInterruptEventPCINT5(void) {
	callbackPCINT5();
}
#endif
#if (PCINT_USE_PCINT6 == true)
volatile callback callbackPCINT6 = pcint_null_callback;
void PinChangeInterruptEventPCINT6(void) {
	callbackPCINT6();
}
#endif
#if (PCINT_USE_PCINT7 == true)
volatile callback callbackPCINT7 = pcint_null_callback;
void PinChangeInterruptEventPCINT7(void) {
	callbackPCINT7();
}
#endif

#ifdef PCINT_COMBINE_PORT0_PORT1
#if (PCINT_USE_PCINT8 == true)
volatile callback callbackPCINT8 = pcint_null_callback;
void PinChangeInterruptEventPCINT8(void) {
	callbackPCINT8();
}
#endif
#if (PCINT_USE_PCINT9 == true)
volatile callback callbackPCINT9 = pcint_null_callback;
void PinChangeInterruptEventPCINT9(void) {
	callbackPCINT9();
}
#endif
#if (PCINT_USE_PCINT10 == true)
volatile callback callbackPCINT10 = pcint_null_callback;
void PinChangeInterruptEventPCINT10(void) {
	callbackPCINT10();
}
#endif
#if (PCINT_USE_PCINT11 == true)
volatile callback callbackPCINT11 = pcint_null_callback;
void PinChangeInterruptEventPCINT11(void) {
	callbackPCINT11();
}
#endif
#if (PCINT_USE_PCINT12 == true)
volatile callback callbackPCINT12 = pcint_null_callback;
void PinChangeInterruptEventPCINT12(void) {
	callbackPCINT12();
}
#endif
#if (PCINT_USE_PCINT13 == true)
volatile callback callbackPCINT13 = pcint_null_callback;
void PinChangeInterruptEventPCINT13(void) {
	callbackPCINT13();
}
#endif
#if (PCINT_USE_PCINT14 == true)
volatile callback callbackPCINT14 = pcint_null_callback;
void PinChangeInterruptEventPCINT14(void) {
	callbackPCINT14();
}
#endif
#if (PCINT_USE_PCINT15 == true)
volatile callback callbackPCINT15 = pcint_null_callback;
void PinChangeInterruptEventPCINT15(void) {
	callbackPCINT15();
}
#endif
#endif // PCINT_COMBINE_PORT0_PORT1

#endif // PCINT_API

#endif // PCINT_USE_PORT0

#endif // PCINT_INCLUDE_FROM_CPP
