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


#ifndef PINCHANGEINTERRUPT_H
#define PINCHANGEINTERRUPT_H

#include "Arduino.h"

//================================================================================
// Settings
//================================================================================

// Settings to de/activate ports
// This will only save you some flash but no ram because of the arrays.
// Arrays are just the smallest and clearest implementation if every port is enabled, that's why we use arrays.
#define PCINT_PORT0_ENABLED
#define PCINT_PORT1_ENABLED
#define PCINT_PORT2_ENABLED
// ISR 3 not used in this lib: http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
//#define PCINT_PORT3_ENABLED

//================================================================================
// Definitions
//================================================================================

// Microcontroller specific definitions
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 24
#define pinChangeInterruptPortToInput(p) ((p == 0) ? PINB : (port == 1) ? PINC : PIND)

#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega640__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 24
#define pinChangeInterruptPortToInput(p) ((p == 0) ? PINB : (port == 1) ? (PINE & (1 << 0)) | ((PINJ & 0x7F) << 1) : PINK)

#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 7
#define pinChangeInterruptPortToInput(p) (PINB & 0x7F)

#elif defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 13
// u2 Series has crappy pin mappings for port 1
#define pinChangeInterruptPortToInput(p) ((p == 0) ? PINB : \
((PINC >> 6) & (1 << 0)) | ((PINC >> 4) & (1 << 1)) | ((PINC >> 2) & (1 << 2)) | ((PINC << 1) & (1 << 3)) | ((PIND >> 1) & (1 << 4)))

#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 6
#define pinChangeInterruptPortToInput(p) (PINB & 0x3F)

#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 10
#define pinChangeInterruptPortToInput(p) ((p == 0) ? PINA : (PINB & 0x0F))

#else // Microcontroller not supported
#error PinChangeInterrupt library doesnt support this MCU yet.
#endif

// missing 1.0.6 definition workaround
#if ARDUINO == 106 && not defined(NOT_AN_INTERRUPT)
#define NOT_AN_INTERRUPT -1
#endif

// convert a normal pin to its PCINT number (0 - max 23)
#define digitalPinToPinChangeInterrupt(p) (digitalPinToPCICR(p) ? ((8 * digitalPinToPCICRbit(p)) + digitalPinToPCMSKbit(p)) : NOT_AN_INTERRUPT)

// define maximum number of PCINTs (0 - max 23)
#define PCINT_PORTS (((EXTERNAL_NUM_PINCHANGEINTERRUPT - 1) / 8) + 1)

//================================================================================
// PinChangeInterrupt
//================================================================================

// function prototypes
inline void attachPinChangeInterrupt(const uint8_t pin, const uint8_t mode);
inline void detachPinChangeInterrupt(const uint8_t pin);
inline void PCintPort(uint8_t port);
void PinChangeInterruptEvent(uint8_t pcintNum);

// variables to save the last port states and the interrupt settings
extern uint8_t oldPorts[PCINT_PORTS];
extern uint8_t fallingPorts[PCINT_PORTS];
extern uint8_t risingPorts[PCINT_PORTS];

void attachPinChangeInterrupt(const uint8_t pcintNum, const uint8_t mode) {
	// get PCINT registers and bitmask
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintMask = (1 << (pcintNum % 8));

	// check if pcint is a valid pcint, exclude deactivated ports
	if (!(pcintNum < EXTERNAL_NUM_PINCHANGEINTERRUPT))
		return;
#if defined(PCINT0_vect) && !defined(PCINT_PORT0_ENABLED)
	if (pcintPort == 0) return;
#endif
#if defined(PCINT1_vect) && !defined(PCINT_PORT1_ENABLED)
	if (pcintPort == 1) return;
#endif
#if defined(PCINT2_vect) && !defined(PCINT_PORT2_ENABLED)
	if (pcintPort == 2) return;
#endif

	// save settings related to mode and registers
	if (mode == CHANGE || mode == RISING)
		risingPorts[pcintPort] |= pcintMask;
	if (mode == CHANGE || mode == FALLING)
		fallingPorts[pcintPort] |= pcintMask;

	// update the old state to the actual state
	oldPorts[pcintPort] = *portInputRegister(digitalPinToPort(pcintNum));

	// pin change mask registers decide which pins are enabled as triggers
	*(&PCMSK0 + pcintPort) |= pcintMask;

	// PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
	PCICR |= (1 << pcintPort);
}

void detachPinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers and bitmask
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintMask = (1 << (pcintNum % 8));

	// check if pcint is a valid pcint, exclude deactivated ports
	if (!(pcintNum < EXTERNAL_NUM_PINCHANGEINTERRUPT))
		return;
#if defined(PCINT0_vect) && !defined(PCINT_PORT0_ENABLED)
	if (pcintPort == 0) return;
#endif
#if defined(PCINT1_vect) && !defined(PCINT_PORT1_ENABLED)
	if (pcintPort == 1) return;
#endif
#if defined(PCINT2_vect) && !defined(PCINT_PORT2_ENABLED)
	if (pcintPort == 2) return;
#endif

	// delete setting
	risingPorts[pcintPort] &= ~pcintMask;
	fallingPorts[pcintPort] &= ~pcintMask;

	// disable the mask.
	*(&PCMSK0 + pcintPort) &= ~pcintMask;

	// if that's the last one, disable the interrupt.
	if (*(&PCMSK0 + pcintPort) == 0)
		PCICR &= ~(1 << pcintPort);
}

void PCintPort(uint8_t port) {
	// get the new and old pin states for port
	uint8_t newPort = pinChangeInterruptPortToInput(port);

	// compare with the old value to detect a rising or falling
	uint8_t change = newPort ^ oldPorts[port];
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[port];

	// check which pins are triggered, compared with the settings
	uint8_t trigger = (rising & risingPorts[port]) | (falling & fallingPorts[port]);

	// execute all functions that should be triggered
	uint8_t i = 0;
	while (trigger) {
		// if trigger is set, call the PCINT function with the specific port
		if (trigger & 0x01)
			PinChangeInterruptEvent((8 * port) + i);

		trigger >>= 1;
		i++;
	}

	// save the new state for next comparison
	oldPorts[port] = newPort;
}

#endif

