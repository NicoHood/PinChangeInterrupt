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

// manually include cpp files here to save flash if only 1 ISR is present
// or if the user knows he just wants to compile all enabled ports.
#if defined(PCINT_ALINKAGE) && defined(PCINT_COMPILE_ENABLED_ISR)
#define PCINT_INCLUDE_FROM_CPP
#include "PinChangeInterrupt0.cpp"
#include "PinChangeInterrupt1.cpp"
#include "PinChangeInterrupt2.cpp"
#include "PinChangeInterrupt3.cpp"
#else

//================================================================================
// Weak Callbacks
//================================================================================

// create all weak functions which are all (if not used) alias of the pcint_null_callback above
/*
for (int i = 0; i < 32; i++) {
Serial.print("void PinChangeInterruptEventPCINT");
Serial.print(i);
Serial.println("(void) __attribute__((weak, alias(\"pcint_null_callback\")));");
}
*/
void PinChangeInterruptEventPCINT0(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT1(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT2(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT3(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT4(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT5(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT6(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT7(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT8(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT9(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT10(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT11(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT12(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT13(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT14(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT15(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT16(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT17(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT18(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT19(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT20(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT21(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT22(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT23(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT24(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT25(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT26(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT27(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT28(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT29(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT30(void) __attribute__((weak, alias("pcint_null_callback")));
void PinChangeInterruptEventPCINT31(void) __attribute__((weak, alias("pcint_null_callback")));

#endif // PCINT_INCLUDE_FROM_CPP

// useless function for weak implemented/not used functions, extern c needed for the alias
extern "C" {
	void pcint_null_callback(void) {
		// useless
	}
}

//================================================================================
// PinChangeInterrupt User Functions
//================================================================================

// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_NUM_USED_PORTS] = { 0 };
uint8_t fallingPorts[PCINT_NUM_USED_PORTS] = { 0 };
uint8_t risingPorts[PCINT_NUM_USED_PORTS] = { 0 };

void enablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask, const uint8_t arrayPos){
	// Update the old state to the actual state
	switch(pcintPort){
#ifdef PCINT_INPUT_PORT0_USED
		case 0:
			oldPorts[arrayPos] = PCINT_INPUT_PORT0;
		break;
#endif
#ifdef PCINT_INPUT_PORT1_USED
		case 1:
			oldPorts[arrayPos] = PCINT_INPUT_PORT1;
		break;
#endif
#ifdef PCINT_INPUT_PORT2_USED
		case 2:
			oldPorts[arrayPos] = PCINT_INPUT_PORT2;
		break;
#endif
#ifdef PCINT_INPUT_PORT3_USED
		case 3:
			oldPorts[arrayPos] = PCINT_INPUT_PORT3;
		break;
#endif
	}

	// Pin change mask registers decide which pins are ENABLE as triggers
#ifdef PCMSK0
#ifdef PCMSK1
#ifdef PCMSK3
	// Special case for ATmega1284P where PCMSK3 is not directly after PCMSK2
	if(false){
#else
	// Special case for Attinyx4 where PCMSK1 and PCMSK0 are not next to each other
	if(&PCMSK1 - &PCMSK0 == 1){
#endif
#endif
		*(&PCMSK0 + pcintPort) |= pcintMask;
#ifdef PCMSK1
	}
	else{
		switch(pcintPort){
			case 0:
				PCMSK0 |= pcintMask;
			break;
			case 1:
				PCMSK1 |= pcintMask;
			break;
#ifdef PCMSK2
			case 2:
				PCMSK2 |= pcintMask;
			break;
#endif
#ifdef PCMSK3
			case 3:
				PCMSK3 |= pcintMask;
			break;
#endif
		}
	}
#endif
#elif defined(PCMSK)
	*(&PCMSK + pcintPort) |= pcintMask;
#endif

	// PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
#ifdef PCICR
	PCICR |= (1  << (pcintPort + PCIE0));
#elif defined(GIMSK) && defined(PCIE0) /* e.g. ATtiny X4 */
	GIMSK |= (1  << (pcintPort + PCIE0));
#elif defined(GIMSK) && defined(PCIE) /* e.g. ATtiny X5 */
	GIMSK |= (1  << (pcintPort + PCIE));
#else
#error MCU has no such a register
#endif
}

void disablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask) {
	bool disable = false;
#ifdef PCMSK0
#ifdef PCMSK1
	// Special case for Attinyx4 where PCMSK1 and PCMSK0 are not next to each other
	if(&PCMSK1 - &PCMSK0 == 1){
#endif
		// disable the mask.
		*(&PCMSK0 + pcintPort) &= ~pcintMask;

		// if that's the last one, disable the interrupt.
		if (*(&PCMSK0 + pcintPort) == 0)
			disable = true;
#ifdef PCMSK1
	}
	else{
		switch(pcintPort){
			case 0:
				// disable the mask.
				PCMSK0 &= ~pcintMask;

				// if that's the last one, disable the interrupt.
				if (!PCMSK0)
					disable = true;
			break;
			case 1:
				// disable the mask.
				PCMSK1 &= ~pcintMask;

				// if that's the last one, disable the interrupt.
				if (!PCMSK1)
					disable = true;
			break;
#ifdef PCMSK2
			case 2:
				// disable the mask.
				PCMSK2 &= ~pcintMask;

				// if that's the last one, disable the interrupt.
				if (!PCMSK2)
					disable = true;
			break;
#endif
#ifdef PCMSK3
			case 3:
				// disable the mask.
				PCMSK3 &= ~pcintMask;

				// if that's the last one, disable the interrupt.
				if (!PCMSK3)
					disable = true;
			break;
#endif
		}
	}
#endif
#elif defined(PCMSK)
	// disable the mask.
	*(&PCMSK + pcintPort) &= ~pcintMask;

	// if that's the last one, disable the interrupt.
	if (*(&PCMSK + pcintPort) == 0)
		disable = true;
#endif
	if(disable)
	{
#ifdef PCICR
		PCICR &= ~(1  << (pcintPort + PCIE0));
#elif defined(GIMSK) && defined(PCIE0) /* e.g. ATtiny X4 */
		GIMSK &= ~(1  << (pcintPort + PCIE0));
#elif defined(GIMSK) && defined(PCIE) /* e.g. ATtiny X5 */
		GIMSK &= ~(1  << (pcintPort + PCIE));
#else
#error MCU has no such a register
#endif
	}
}

/*
asm output (nothing to optimize here)

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
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>
sbrc r28, 1
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>
sbrc r28, 2
call 0x318 ; 0x318 <_Z20PinChangeInterruptEventPCINT2v>
sbrc r28, 3
call 0x340 ; 0x340 <_Z20PinChangeInterruptEventPCINT3v>
sbrc r28, 4
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>
sbrc r28, 5
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>
sbrc r28, 6
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>
sbrc r28, 7
call 0x37c ; 0x37c <_Z20PinChangeInterruptEventPCINT0v>

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
