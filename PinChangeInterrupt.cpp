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
#define PCINT_WEAK_ALIAS(n) void pcint_callback_ptr_ ## n () __attribute__ ((weak, alias ("pcint_null_callback")))

PCINT_WEAK_ALIAS(0);
PCINT_WEAK_ALIAS(1);
PCINT_WEAK_ALIAS(2);
PCINT_WEAK_ALIAS(3);
PCINT_WEAK_ALIAS(4);
PCINT_WEAK_ALIAS(5);
PCINT_WEAK_ALIAS(6);
PCINT_WEAK_ALIAS(7);
PCINT_WEAK_ALIAS(8);
PCINT_WEAK_ALIAS(9);
PCINT_WEAK_ALIAS(10);
PCINT_WEAK_ALIAS(11);
PCINT_WEAK_ALIAS(12);
PCINT_WEAK_ALIAS(13);
PCINT_WEAK_ALIAS(14);
PCINT_WEAK_ALIAS(15);
PCINT_WEAK_ALIAS(16);
PCINT_WEAK_ALIAS(17);
PCINT_WEAK_ALIAS(18);
PCINT_WEAK_ALIAS(19);
PCINT_WEAK_ALIAS(20);
PCINT_WEAK_ALIAS(21);
PCINT_WEAK_ALIAS(22);
PCINT_WEAK_ALIAS(23);

//================================================================================
// Interrupt Handlers
//================================================================================

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t fallingPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t risingPorts[PCINT_ENABLED_PORTS] = { 0 };


#if defined(PCINT0_vect) && defined(PCINT_PORT0_ENABLED)
ISR(PCINT0_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT0;

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
	if (trigger & (1 << 0))
		pcint_callback_ptr_0();
	if (trigger & (1 << 1))
		pcint_callback_ptr_1();
	if (trigger & (1 << 2))
		pcint_callback_ptr_2();
	if (trigger & (1 << 3))
		pcint_callback_ptr_3();
	if (trigger & (1 << 4))
		pcint_callback_ptr_4();
	if (trigger & (1 << 5))
		pcint_callback_ptr_5();
	if (trigger & (1 << 6))
		pcint_callback_ptr_6();
	if (trigger & (1 << 7))
		pcint_callback_ptr_7();
}
#endif


#if defined(PCINT1_vect) && defined(PCINT_PORT1_ENABLED)
ISR(PCINT1_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT1;

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
	if (trigger & (1 << 0))
		pcint_callback_ptr_8();
	if (trigger & (1 << 1))
		pcint_callback_ptr_9();
	if (trigger & (1 << 2))
		pcint_callback_ptr_10();
	if (trigger & (1 << 3))
		pcint_callback_ptr_11();
	if (trigger & (1 << 4))
		pcint_callback_ptr_12();
	if (trigger & (1 << 5))
		pcint_callback_ptr_13();
	if (trigger & (1 << 6))
		pcint_callback_ptr_14();
	if (trigger & (1 << 7))
		pcint_callback_ptr_15();
}
#endif


#if defined(PCINT2_vect) && defined(PCINT_PORT2_ENABLED)
ISR(PCINT2_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT2;

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
	if (trigger & (1 << 0))
		pcint_callback_ptr_16();
	if (trigger & (1 << 1))
		pcint_callback_ptr_17();
	if (trigger & (1 << 2))
		pcint_callback_ptr_18();
	if (trigger & (1 << 3))
		pcint_callback_ptr_19();
	if (trigger & (1 << 4))
		pcint_callback_ptr_20();
	if (trigger & (1 << 5))
		pcint_callback_ptr_21();
	if (trigger & (1 << 6))
		pcint_callback_ptr_22();
	if (trigger & (1 << 7))
		pcint_callback_ptr_23();
}
#endif


#if defined(PCINT3_vect) && defined(PCINT_PORT3_ENABLED)
ISR(PCINT3_vect) {
	// not supported
}
#endif


/*
// asm output
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