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

ISR(PCINT0_vect) {
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

#endif // PCINT_API

#endif // PCINT_USE_PORT0

#endif // PCINT_INCLUDE_FROM_CPP
