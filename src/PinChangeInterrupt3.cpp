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

#if (PCINT_USE_PORT3 == true)

void attachPinChangeInterrupt3(void) {
	// fake function to make the IDE link this file
}

ISR(PCINT3_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT3;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = getArrayPosPCINT(3);
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
#if !defined(PCINT_CALLBACK_PORT3)
	PCINT_CALLBACK(0, 24);
	PCINT_CALLBACK(1, 25);
	PCINT_CALLBACK(2, 26);
	PCINT_CALLBACK(3, 27);
	PCINT_CALLBACK(4, 28);
	PCINT_CALLBACK(5, 29);
	PCINT_CALLBACK(6, 30);
	PCINT_CALLBACK(7, 31);
#else
	PCINT_CALLBACK_PORT3
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
#if (PCINT_USE_PCINT24 == true)
volatile callback callbackPCINT24 = pcint_null_callback;
void PinChangeInterruptEventPCINT24(void) {
	callbackPCINT24();
}
#endif
#if (PCINT_USE_PCINT25 == true)
volatile callback callbackPCINT25 = pcint_null_callback;
void PinChangeInterruptEventPCINT25(void) {
	callbackPCINT25();
}
#endif
#if (PCINT_USE_PCINT26 == true)
volatile callback callbackPCINT26 = pcint_null_callback;
void PinChangeInterruptEventPCINT26(void) {
	callbackPCINT26();
}
#endif
#if (PCINT_USE_PCINT27 == true)
volatile callback callbackPCINT27 = pcint_null_callback;
void PinChangeInterruptEventPCINT27(void) {
	callbackPCINT27();
}
#endif
#if (PCINT_USE_PCINT28 == true)
volatile callback callbackPCINT28 = pcint_null_callback;
void PinChangeInterruptEventPCINT28(void) {
	callbackPCINT28();
}
#endif
#if (PCINT_USE_PCINT29 == true)
volatile callback callbackPCINT29 = pcint_null_callback;
void PinChangeInterruptEventPCINT29(void) {
	callbackPCINT29();
}
#endif
#if (PCINT_USE_PCINT30 == true)
volatile callback callbackPCINT30 = pcint_null_callback;
void PinChangeInterruptEventPCINT30(void) {
	callbackPCINT30();
}
#endif
#if (PCINT_USE_PCINT31 == true)
volatile callback callbackPCINT31 = pcint_null_callback;
void PinChangeInterruptEventPCINT31(void) {
	callbackPCINT31();
}
#endif

#endif // PCINT_API

#endif // PCINT_USE_PORT3

#endif // PCINT_INCLUDE_FROM_CPP