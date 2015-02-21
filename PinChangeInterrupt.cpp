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
// Weak Callbacks
//================================================================================

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions, extern c needed for the alias
extern "C" {
	static void pcint_null_callback(void) {	}
}

// create all weak functions which are all (if not used) alias of the pcint_null_callback above
/*
for (int i = 0; i < 24; i++) {
Serial.print("void pcint_callback_ptr_");
Serial.print(i);
Serial.println("() __attribute__((weak, alias(\"pcint_null_callback\")));");
}
*/
void pcint_callback_ptr_0() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_1() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_2() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_3() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_4() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_5() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_6() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_7() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_8() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_9() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_10() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_11() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_12() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_13() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_14() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_15() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_16() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_17() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_18() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_19() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_20() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_21() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_22() __attribute__((weak, alias("pcint_null_callback")));
void pcint_callback_ptr_23() __attribute__((weak, alias("pcint_null_callback")));

//================================================================================
// Interrupt Handlers
//================================================================================

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_NUM_USED_PORTS] = { 0 };
uint8_t fallingPorts[PCINT_NUM_USED_PORTS] = { 0 };
uint8_t risingPorts[PCINT_NUM_USED_PORTS] = { 0 };


#if (PCINT_USE_PORT0 == true)
ISR(PCINT0_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT0;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = PCINT_ARRAY_POS(0);
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
#if (PCINT_USE_PCINT0 == true)
	if (trigger & (1 << 0))
		pcint_callback_ptr_0();
#endif
#if (PCINT_USE_PCINT1 == true)
	if (trigger & (1 << 1))
		pcint_callback_ptr_1();
#endif
#if (PCINT_USE_PCINT2 == true)
	if (trigger & (1 << 2))
		pcint_callback_ptr_2();
#endif
#if (PCINT_USE_PCINT3 == true)
	if (trigger & (1 << 3))
		pcint_callback_ptr_3();
#endif
#if (PCINT_USE_PCINT4 == true)
	if (trigger & (1 << 4))
		pcint_callback_ptr_4();
#endif
#if (PCINT_USE_PCINT5 == true)
	if (trigger & (1 << 5))
		pcint_callback_ptr_5();
#endif
#if (PCINT_USE_PCINT6 == true)
	if (trigger & (1 << 6))
		pcint_callback_ptr_6();
#endif
#if (PCINT_USE_PCINT7 == true)
	if (trigger & (1 << 7))
		pcint_callback_ptr_7();
#endif
}
#endif


#if (PCINT_USE_PORT1 == true)
ISR(PCINT1_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT1;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = PCINT_ARRAY_POS(1);
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
#if (PCINT_USE_PCINT8 == true)
	if (trigger & (1 << 0))
		pcint_callback_ptr_8();
#endif
#if (PCINT_USE_PCINT9 == true)
	if (trigger & (1 << 1))
		pcint_callback_ptr_9();
#endif
#if (PCINT_USE_PCINT10 == true)
	if (trigger & (1 << 2))
		pcint_callback_ptr_10();
#endif
#if (PCINT_USE_PCINT11 == true)
	if (trigger & (1 << 3))
		pcint_callback_ptr_11();
#endif
#if (PCINT_USE_PCINT12 == true)
	if (trigger & (1 << 4))
		pcint_callback_ptr_12();
#endif
#if (PCINT_USE_PCINT13 == true)
	if (trigger & (1 << 5))
		pcint_callback_ptr_13();
#endif
#if (PCINT_USE_PCINT14 == true)
	if (trigger & (1 << 6))
		pcint_callback_ptr_14();
#endif
#if (PCINT_USE_PCINT15 == true)
	if (trigger & (1 << 7))
		pcint_callback_ptr_15();
#endif
}
#endif


#if (PCINT_USE_PORT2 == true)
ISR(PCINT2_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT2;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = PCINT_ARRAY_POS(2);
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
#if (PCINT_USE_PCINT16 == true)
	if (trigger & (1 << 0))
		pcint_callback_ptr_16();
#endif
#if (PCINT_USE_PCINT17 == true)
	if (trigger & (1 << 1))
		pcint_callback_ptr_17();
#endif
#if (PCINT_USE_PCINT18 == true)
	if (trigger & (1 << 2))
		pcint_callback_ptr_18();
#endif
#if (PCINT_USE_PCINT19 == true)
	if (trigger & (1 << 3))
		pcint_callback_ptr_19();
#endif
#if (PCINT_USE_PCINT20 == true)
	if (trigger & (1 << 4))
		pcint_callback_ptr_20();
#endif
#if (PCINT_USE_PCINT21 == true)
	if (trigger & (1 << 5))
		pcint_callback_ptr_21();
#endif
#if (PCINT_USE_PCINT22 == true)
	if (trigger & (1 << 6))
		pcint_callback_ptr_22();
#endif
#if (PCINT_USE_PCINT23 == true)
	if (trigger & (1 << 7))
		pcint_callback_ptr_23();
#endif
}
#endif

// asm output (nothing to optimize here)
/*
ISR(PCINT0_vect) {
push r1
push r0
in r0, 0x3f ; 63
push r0
eor r1, r1
push r18
push r19
push r20
push r21
push r22
push r23
push r24
push r25
push r26
push r27
push r28
push r30
push r31

// get the new and old pin states for port
// uint8_t newPort = pinChangeInterruptPortToInput(port);
in r24, 0x03; 3 //(1) loads byte into newPort from I/O register

// loads old port and high + low setting
lds r18, 0x011E //(1 or 2) loads oldPorts into register
lds r28, 0x011B //(1 or 2) loads fallingPorts into register
lds r25, 0x0118 //(1 or 2) loads risingPorts into register

and	r28, r18 // oldPorts & fallingPorts
and	r25, r24 // newPort & risingPorts
or	r28, r25 // (oldPorts & fallingPorts) | (newPort & risingPorts)
eor r18, r24 // oldPorts^newPort
and	r28, r18 // ((oldPorts & fallingPorts) | (newPort & risingPorts)) & (oldPorts^newPort)

// save the new state for next comparison
// oldPorts[arrayPos] = newPort;
sts 0x011E, r24

// Execute all functions that should be triggered
sbrc r28, 0
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>
sbrc r28, 1
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>
sbrc r28, 2
call 0x318 ; 0x318 <_Z20pcint_callback_ptr_2v>
sbrc r28, 3
call 0x340 ; 0x340 <_Z20pcint_callback_ptr_3v>
sbrc r28, 4
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>
sbrc r28, 5
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>
sbrc r28, 6
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>
sbrc r28, 7
call 0x37c ; 0x37c <_Z20pcint_callback_ptr_0v>

pop r31
pop r30
pop r28
pop r27
pop r26
pop r25
pop r24
pop r23
pop r22
pop r21
pop r20
pop r19
pop r18
pop r0
out 0x3f, r0 ; 63
pop r0
pop r1
reti
}
*/