#ifndef PINCHANGEINTERRUPTBOARDS_H
#define PINCHANGEINTERRUPTBOARDS_H

//================================================================================
// Board Definitions
//================================================================================

// Microcontroller specific definitions
// digital pin -> pcint number definitions
// even if MISO etc are not PCINTs we have to map them to the pin and then refuse to a NOT_AN_INTERRUPT

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
// some pins are not useable, we wont check this, since it doesnt matter as long as the user doesn't try to attach the individual PCINTs
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 24 // 4 not available, see below
#define PCINT_INPUT0 (PINB & 0x3F) // 6, 7 Crystal
#define PCINT_INPUT1 (PINC & 0x3F) // 14 Reset, 15 NC
#define PCINT_INPUT2 PIND

// Arduino Uno
#define PIN_TO_PCINT_0 16
#define PIN_TO_PCINT_1 17
#define PIN_TO_PCINT_2 18
#define PIN_TO_PCINT_3 19
#define PIN_TO_PCINT_4 20
#define PIN_TO_PCINT_5 21
#define PIN_TO_PCINT_6 22
#define PIN_TO_PCINT_7 23
#define PIN_TO_PCINT_8 0
#define PIN_TO_PCINT_9 1
#define PIN_TO_PCINT_10 2
#define PIN_TO_PCINT_11 3
#define PIN_TO_PCINT_12 4
#define PIN_TO_PCINT_13 5
#define PIN_TO_PCINT_14 8
#define PIN_TO_PCINT_15 9
#define PIN_TO_PCINT_16 10
#define PIN_TO_PCINT_17 11
#define PIN_TO_PCINT_18 12
#define PIN_TO_PCINT_19 13
//#define PIN_TO_PCINT_20 NC
//#define PIN_TO_PCINT_21 NC
#define PIN_TO_PCINT_A0 PIN_TO_PCINT_14
#define PIN_TO_PCINT_A1 PIN_TO_PCINT_15
#define PIN_TO_PCINT_A2 PIN_TO_PCINT_16
#define PIN_TO_PCINT_A3 PIN_TO_PCINT_17
#define PIN_TO_PCINT_A4 PIN_TO_PCINT_18
#define PIN_TO_PCINT_A5 PIN_TO_PCINT_19
#define PIN_TO_PCINT_A6 PIN_TO_PCINT_20
#define PIN_TO_PCINT_A7 PIN_TO_PCINT_21
#define PIN_TO_PCINT_SS PIN_TO_PCINT_10
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_11
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_12
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_13
#define PIN_TO_PCINT_SDA PIN_TO_PCINT_18
#define PIN_TO_PCINT_SCL PIN_TO_PCINT_19

#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_21 NOT_AN_INTERRUPT

#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega640__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 24
#define PCINT_INPUT0 PINB
#define PCINT_INPUT1 ((PINE & (1 << 0)) | ((PINJ & 0x7F) << 1))
#define PCINT_INPUT2 PINK

#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 8
#define PCINT_INPUT0 PINB

#elif defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 13
#define PCINT_INPUT0 PINB
// u2 Series has crappy pin mappings for port 1
#define PCINT_INPUT1 (((PINC >> 6) & (1 << 0)) | ((PINC >> 4) & (1 << 1)) | ((PINC >> 2) & (1 << 2)) | ((PINC << 1) & (1 << 3)) | ((PIND >> 1) & (1 << 4)))

#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 6
#define PCINT_INPUT0 (PINB & 0x3F)

#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
#define EXTERNAL_NUM_PINCHANGEINTERRUPT 10
#define PCINT_INPUT0 PINA
#define PCINT_INPUT1 (PINB & 0x0F)

#else // Microcontroller not supported
#error PinChangeInterrupt library does not support this MCU yet.
#endif

#endif // include guard

