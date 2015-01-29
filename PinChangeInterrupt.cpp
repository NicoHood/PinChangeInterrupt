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

#include "PinChangeInterrupt.h"

//================================================================================
// PinChangeInterrupt
//================================================================================

void __attribute__((weak)) PinChangeInterruptEvent(uint8_t pcintNum) {
	// PinChangeInterrupt weak event handler
	// The user has to overwrite this function!
}

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t fallingPorts[PCINT_ENABLED_PORTS] = { 0 };
uint8_t risingPorts[PCINT_ENABLED_PORTS] = { 0 };

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

//================================================================================
// Progmem callbacks
//================================================================================

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions
extern "C" void pcint_null_callback(void) {
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

// create the function pointer of all functions in progmem to save ram
#define PCINT_CALLBACK(n) pcint_callback_ptr_ ## n

static const PROGMEM callback pcint_callback_arr[] = {
	PCINT_CALLBACK(0),
	PCINT_CALLBACK(1),
	PCINT_CALLBACK(2),
	PCINT_CALLBACK(3),
	PCINT_CALLBACK(4),
	PCINT_CALLBACK(5),
	PCINT_CALLBACK(6),
	PCINT_CALLBACK(7),
};

// number of items in an array
#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0]))) 

// calls all functions (for testing)
void call_all_callbacks(void) {
	int i;
	for (i = 0; i < NUMITEMS(pcint_callback_arr); ++i) {
#ifndef __AVR
		pcint_callback_arr[i]();
#else
		((callback)pgm_read_word(pcint_callback_arr + i))();
#endif
	}
}