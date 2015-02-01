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
// Progmem callbacks
//================================================================================

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions, extern c needed for the alias
extern "C" {
	static void pcint_null_callback(void) {
	}
}
// create all weak functions which are all (if not used) alias of the pcint_null_callback above
#define PCINT_WEAK_ALIAS(n) void pcint_callback_ptr_ ## n () __attribute__ ((weak, alias ("pcint_null_callback")))

#if defined(PCINT0_vect) && defined(PCINT_PORT0_ENABLED)
PCINT_WEAK_ALIAS(0);
PCINT_WEAK_ALIAS(1);
PCINT_WEAK_ALIAS(2);
PCINT_WEAK_ALIAS(3);
PCINT_WEAK_ALIAS(4);
PCINT_WEAK_ALIAS(5);
PCINT_WEAK_ALIAS(6);
PCINT_WEAK_ALIAS(7);
#endif
#if defined(PCINT1_vect) && defined(PCINT_PORT1_ENABLED)
PCINT_WEAK_ALIAS(8);
PCINT_WEAK_ALIAS(9);
PCINT_WEAK_ALIAS(10);
PCINT_WEAK_ALIAS(11);
PCINT_WEAK_ALIAS(12);
PCINT_WEAK_ALIAS(13);
PCINT_WEAK_ALIAS(14);
PCINT_WEAK_ALIAS(15);
#endif
#if defined(PCINT2_vect) && defined(PCINT_PORT2_ENABLED)
PCINT_WEAK_ALIAS(16);
PCINT_WEAK_ALIAS(17);
PCINT_WEAK_ALIAS(18);
PCINT_WEAK_ALIAS(19);
PCINT_WEAK_ALIAS(20);
PCINT_WEAK_ALIAS(21);
PCINT_WEAK_ALIAS(22);
PCINT_WEAK_ALIAS(23);
#endif

// create the function pointer of all functions in progmem to save ram
#define PCINT_CALLBACK(n) pcint_callback_ptr_ ## n

static const PROGMEM callback pcint_callback_arr[] = {
#if defined(PCINT0_vect) && defined(PCINT_PORT0_ENABLED)
	PCINT_CALLBACK(0),
	PCINT_CALLBACK(1),
	PCINT_CALLBACK(2),
	PCINT_CALLBACK(3),
	PCINT_CALLBACK(4),
	PCINT_CALLBACK(5),
	PCINT_CALLBACK(6),
	PCINT_CALLBACK(7),
#endif
#if defined(PCINT1_vect) && defined(PCINT_PORT1_ENABLED)
	PCINT_CALLBACK(8),
	PCINT_CALLBACK(9),
	PCINT_CALLBACK(10),
	PCINT_CALLBACK(11),
	PCINT_CALLBACK(12),
	PCINT_CALLBACK(13),
	PCINT_CALLBACK(14),
	PCINT_CALLBACK(15),
#endif
#if defined(PCINT2_vect) && defined(PCINT_PORT2_ENABLED)
	PCINT_CALLBACK(16),
	PCINT_CALLBACK(17),
	PCINT_CALLBACK(18),
	PCINT_CALLBACK(19),
	PCINT_CALLBACK(20),
	PCINT_CALLBACK(21),
	PCINT_CALLBACK(22),
	PCINT_CALLBACK(23),
#endif
};

//================================================================================
// PinChangeInterrupt
//================================================================================

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t fallingPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t risingPorts[PCINT_ENABLED_PORTS] = { 0 };

// pcint interrupt handler function
static inline void PCintPort(uint8_t port) {
	// get the new and old pin states for port
	uint8_t newPort = pinChangeInterruptPortToInput(port);

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = PCINT_ARRAY_POS(port);
	uint8_t change = newPort ^ oldPorts[arrayPos];
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[arrayPos];

	// check which pins are triggered, compared with the settings
	uint8_t trigger = (rising & risingPorts[arrayPos]) | (falling & fallingPorts[arrayPos]);

	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;

	// execute all functions that should be triggered
	uint8_t i = 0;
	while (trigger) {
		// if trigger is set, call the PCINT function with the specific port
		if (trigger & 0x01)
			((callback)pgm_read_word(pcint_callback_arr + ((arrayPos * 8) + i)))();

		trigger >>= 1;
		i++;
	}
}

// interrupt handlers
#if defined(PCINT0_vect) && defined(PCINT_PORT0_ENABLED)
ISR(PCINT0_vect) {
	PCintPort(0);
}
#endif

#if defined(PCINT1_vect) && defined(PCINT_PORT1_ENABLED)
ISR(PCINT1_vect) {
	PCintPort(1);
}
#endif

#if defined(PCINT2_vect) && defined(PCINT_PORT2_ENABLED)
ISR(PCINT2_vect) {
	PCintPort(2);
}
#endif

#if defined(PCINT3_vect) && defined(PCINT_PORT3_ENABLED)
ISR(PCINT3_vect) {
	PCintPort(3);
}
#endif
