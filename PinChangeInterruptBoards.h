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

#ifndef PINCHANGEINTERRUPTBOARDS_H
#define PINCHANGEINTERRUPTBOARDS_H

//================================================================================
// Board Definitions
//================================================================================

/*
Microcontroller specific definitions

digital pin -> pcint number definitions
Even if A0, MISO etc are not PCINTs we have to map them to the pin number
and then refuse to a NOT_AN_INTERRUPT (definitions at the very end)
*/

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__)
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT1 PINC
#define PCINT_INPUT_PORT2 PIND

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
#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_21 NOT_AN_INTERRUPT
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


#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega640__)
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT2 PINK

#if defined(PCINT_ENABLE_PCINT16)
#if defined(PCINT_ENABLE_PCINT17) || defined(PCINT_ENABLE_PCINT18) \
|| defined(PCINT_ENABLE_PCINT19) || defined(PCINT_ENABLE_PCINT20) \
|| defined(PCINT_ENABLE_PCINT21) || defined(PCINT_ENABLE_PCINT22) \
|| defined(PCINT_ENABLE_PCINT23)
// PortE and PortJ selected
#define PCINT_INPUT_PORT1 ((PINE & (1 << 0)) | (PINJ << 1))
#else
// PortE only selected
#define PCINT_INPUT_PORT1 PINE
#endif
#else
// PortJ only selected
// we still have to do the shift because the attach
// function is not designed for this optimization
#define PCINT_INPUT_PORT1 (PINJ << 1)
#endif

// Arduino Mega/Mega2560
#define PIN_TO_PCINT_0 8
#define PIN_TO_PCINT_1 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_2 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_3 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_4 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_5 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_6 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_7 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_8 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_9 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_10 4
#define PIN_TO_PCINT_11 5
#define PIN_TO_PCINT_12 6
#define PIN_TO_PCINT_13 7
#define PIN_TO_PCINT_14 10
#define PIN_TO_PCINT_15 9
#define PIN_TO_PCINT_16 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_17 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_18 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_19 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_21 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_22 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_23 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_24 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_25 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_26 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_27 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_28 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_29 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_30 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_31 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_32 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_33 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_34 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_35 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_36 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_37 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_38 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_39 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_40 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_41 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_42 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_43 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_44 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_45 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_46 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_47 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_48 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_49 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_50 3
#define PIN_TO_PCINT_51 2
#define PIN_TO_PCINT_52 1
#define PIN_TO_PCINT_53 0
#define PIN_TO_PCINT_54 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_55 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_56 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_57 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_58 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_59 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_60 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_61 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_62 16
#define PIN_TO_PCINT_63 17
#define PIN_TO_PCINT_64 18
#define PIN_TO_PCINT_65 19
#define PIN_TO_PCINT_66 20
#define PIN_TO_PCINT_67 21
#define PIN_TO_PCINT_68 22
#define PIN_TO_PCINT_69 23#define PIN_TO_PCINT_A0 PIN_TO_PCINT_54
#define PIN_TO_PCINT_A1 PIN_TO_PCINT_55
#define PIN_TO_PCINT_A2 PIN_TO_PCINT_56
#define PIN_TO_PCINT_A3 PIN_TO_PCINT_57
#define PIN_TO_PCINT_A4 PIN_TO_PCINT_58
#define PIN_TO_PCINT_A5 PIN_TO_PCINT_59
#define PIN_TO_PCINT_A6 PIN_TO_PCINT_60
#define PIN_TO_PCINT_A7 PIN_TO_PCINT_61
#define PIN_TO_PCINT_A8 PIN_TO_PCINT_62
#define PIN_TO_PCINT_A9 PIN_TO_PCINT_63
#define PIN_TO_PCINT_A10 PIN_TO_PCINT_64
#define PIN_TO_PCINT_A11 PIN_TO_PCINT_65
#define PIN_TO_PCINT_A12 PIN_TO_PCINT_66
#define PIN_TO_PCINT_A13 PIN_TO_PCINT_67
#define PIN_TO_PCINT_A14 PIN_TO_PCINT_68
#define PIN_TO_PCINT_A15 PIN_TO_PCINT_69
#define PIN_TO_PCINT_SS PIN_TO_PCINT_53
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_51
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_50
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_52
#define PIN_TO_PCINT_SDA PIN_TO_PCINT_20
#define PIN_TO_PCINT_SCL PIN_TO_PCINT_21


#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#define PCINT_INPUT_PORT0 PINB

// Arduino Leonardo/Micro
#define PIN_TO_PCINT_0 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_1 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_2 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_3 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_4 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_5 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_6 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_7 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_8 4
#define PIN_TO_PCINT_9 5
#define PIN_TO_PCINT_10 6
#define PIN_TO_PCINT_11 7
#define PIN_TO_PCINT_12 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_13 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_14 3
#define PIN_TO_PCINT_15 1
#define PIN_TO_PCINT_16 2
#define PIN_TO_PCINT_17 0 // LED, but should work on Teensy2
#define PIN_TO_PCINT_18 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_19 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_21 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_22 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_23 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_24 PIN_TO_PCINT_4
#define PIN_TO_PCINT_25 PIN_TO_PCINT_6
#define PIN_TO_PCINT_26 PIN_TO_PCINT_8
#define PIN_TO_PCINT_27 PIN_TO_PCINT_9
#define PIN_TO_PCINT_28 PIN_TO_PCINT_10
#define PIN_TO_PCINT_29 PIN_TO_PCINT_12
#define PIN_TO_PCINT_A0 PIN_TO_PCINT_18
#define PIN_TO_PCINT_A1 PIN_TO_PCINT_19
#define PIN_TO_PCINT_A2 PIN_TO_PCINT_20
#define PIN_TO_PCINT_A3 PIN_TO_PCINT_21
#define PIN_TO_PCINT_A4 PIN_TO_PCINT_22
#define PIN_TO_PCINT_A5 PIN_TO_PCINT_23
#define PIN_TO_PCINT_A6 PIN_TO_PCINT_24
#define PIN_TO_PCINT_A7 PIN_TO_PCINT_25
#define PIN_TO_PCINT_A8 PIN_TO_PCINT_26
#define PIN_TO_PCINT_A9 PIN_TO_PCINT_27
#define PIN_TO_PCINT_A10 PIN_TO_PCINT_28
#define PIN_TO_PCINT_A11 PIN_TO_PCINT_29
#define PIN_TO_PCINT_SS PIN_TO_PCINT_17
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_16
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_14
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_15
#define PIN_TO_PCINT_SDA PIN_TO_PCINT_2
#define PIN_TO_PCINT_SCL PIN_TO_PCINT_3


#elif defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
// u2 Series has crappy pin mappings for port 1
#define PCINT_INPUT_PORT0 PINB
#define PCINT_INPUT_PORT1 (((PINC >> 6) & (1 << 0)) | ((PINC >> 4) & (1 << 1)) | ((PINC >> 2) & (1 << 2)) | ((PINC << 1) & (1 << 3)) | ((PIND >> 1) & (1 << 4)))

// u2 Series/HoodLoader2
// On Arduino boards only pins 0-7 are broken out
#define PIN_TO_PCINT_0 0 // NC
#define PIN_TO_PCINT_1 1
#define PIN_TO_PCINT_2 2
#define PIN_TO_PCINT_3 3
#define PIN_TO_PCINT_4 4
#define PIN_TO_PCINT_5 5
#define PIN_TO_PCINT_6 6
#define PIN_TO_PCINT_7 7
#define PIN_TO_PCINT_8 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_9 8 // NC
#define PIN_TO_PCINT_10 9 // NC
#define PIN_TO_PCINT_11 10 // NC
#define PIN_TO_PCINT_12 11 // NC
#define PIN_TO_PCINT_13 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_14 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_15 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_16 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_17 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_18 12 // LED
#define PIN_TO_PCINT_19 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#define PIN_TO_PCINT_SS PIN_TO_PCINT_0
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_2
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_3
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_1

#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define PCINT_INPUT_PORT0 PINB

#define PIN_TO_PCINT_0 0
#define PIN_TO_PCINT_1 1
#define PIN_TO_PCINT_2 2
#define PIN_TO_PCINT_3 3
#define PIN_TO_PCINT_4 4
#define PIN_TO_PCINT_5 5
#define PIN_TO_PCINT_A0 PIN_TO_PCINT_5
#define PIN_TO_PCINT_A1 PIN_TO_PCINT_2
#define PIN_TO_PCINT_A2 PIN_TO_PCINT_4
#define PIN_TO_PCINT_A3 PIN_TO_PCINT_3
// no SS pin available
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_0
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_1
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_2
#define PIN_TO_PCINT_SDA PIN_TO_PCINT_0
#define PIN_TO_PCINT_SCL PIN_TO_PCINT_2

#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
#define PCINT_INPUT_PORT0 PINA
#define PCINT_INPUT_PORT1 PINB

#define PIN_TO_PCINT_0 0
#define PIN_TO_PCINT_1 1
#define PIN_TO_PCINT_2 2
#define PIN_TO_PCINT_3 3
#define PIN_TO_PCINT_4 4
#define PIN_TO_PCINT_5 5
#define PIN_TO_PCINT_6 6
#define PIN_TO_PCINT_7 7
#define PIN_TO_PCINT_8 10
#define PIN_TO_PCINT_9 9
#define PIN_TO_PCINT_10 8
#define PIN_TO_PCINT_A0 PIN_TO_PCINT_0
#define PIN_TO_PCINT_A1 PIN_TO_PCINT_1
#define PIN_TO_PCINT_A2 PIN_TO_PCINT_2
#define PIN_TO_PCINT_A3 PIN_TO_PCINT_3
#define PIN_TO_PCINT_A4 PIN_TO_PCINT_4
#define PIN_TO_PCINT_A5 PIN_TO_PCINT_5
#define PIN_TO_PCINT_A6 PIN_TO_PCINT_6
#define PIN_TO_PCINT_A7 PIN_TO_PCINT_7
// no SS pin available
#define PIN_TO_PCINT_MOSI PIN_TO_PCINT_6
#define PIN_TO_PCINT_MISO PIN_TO_PCINT_5
#define PIN_TO_PCINT_SCK PIN_TO_PCINT_4
#define PIN_TO_PCINT_SDA PIN_TO_PCINT_6
#define PIN_TO_PCINT_SCL PIN_TO_PCINT_4

#else // Microcontroller not supported
#error PinChangeInterrupt library does not support this MCU.
#endif

//================================================================================
// Add missing definitions
//================================================================================

// add fakes if ports are not used
#ifndef PCINT_INPUT_PORT0
#define PCINT_INPUT_PORT0 0
#endif
#ifndef PCINT_INPUT_PORT1
#define PCINT_INPUT_PORT1 0
#endif
#ifndef PCINT_INPUT_PORT2
#define PCINT_INPUT_PORT2 0
#endif

// not defined pins will result in an error
/*
for (int i = 0; i < 100; i++) {
Serial.print("#ifndef PIN_TO_PCINT_");
Serial.println(i);
Serial.print("#define PIN_TO_PCINT_");
Serial.print(i);
Serial.println(" NOT_AN_INTERRUPT");
Serial.println("#endif");
}
*/
#ifndef PIN_TO_PCINT_0
#define PIN_TO_PCINT_0 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_1
#define PIN_TO_PCINT_1 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_2
#define PIN_TO_PCINT_2 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_3
#define PIN_TO_PCINT_3 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_4
#define PIN_TO_PCINT_4 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_5
#define PIN_TO_PCINT_5 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_6
#define PIN_TO_PCINT_6 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_7
#define PIN_TO_PCINT_7 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_8
#define PIN_TO_PCINT_8 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_9
#define PIN_TO_PCINT_9 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_10
#define PIN_TO_PCINT_10 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_11
#define PIN_TO_PCINT_11 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_12
#define PIN_TO_PCINT_12 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_13
#define PIN_TO_PCINT_13 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_14
#define PIN_TO_PCINT_14 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_15
#define PIN_TO_PCINT_15 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_16
#define PIN_TO_PCINT_16 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_17
#define PIN_TO_PCINT_17 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_18
#define PIN_TO_PCINT_18 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_19
#define PIN_TO_PCINT_19 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_20
#define PIN_TO_PCINT_20 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_21
#define PIN_TO_PCINT_21 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_22
#define PIN_TO_PCINT_22 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_23
#define PIN_TO_PCINT_23 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_24
#define PIN_TO_PCINT_24 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_25
#define PIN_TO_PCINT_25 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_26
#define PIN_TO_PCINT_26 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_27
#define PIN_TO_PCINT_27 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_28
#define PIN_TO_PCINT_28 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_29
#define PIN_TO_PCINT_29 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_30
#define PIN_TO_PCINT_30 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_31
#define PIN_TO_PCINT_31 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_32
#define PIN_TO_PCINT_32 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_33
#define PIN_TO_PCINT_33 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_34
#define PIN_TO_PCINT_34 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_35
#define PIN_TO_PCINT_35 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_36
#define PIN_TO_PCINT_36 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_37
#define PIN_TO_PCINT_37 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_38
#define PIN_TO_PCINT_38 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_39
#define PIN_TO_PCINT_39 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_40
#define PIN_TO_PCINT_40 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_41
#define PIN_TO_PCINT_41 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_42
#define PIN_TO_PCINT_42 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_43
#define PIN_TO_PCINT_43 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_44
#define PIN_TO_PCINT_44 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_45
#define PIN_TO_PCINT_45 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_46
#define PIN_TO_PCINT_46 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_47
#define PIN_TO_PCINT_47 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_48
#define PIN_TO_PCINT_48 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_49
#define PIN_TO_PCINT_49 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_50
#define PIN_TO_PCINT_50 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_51
#define PIN_TO_PCINT_51 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_52
#define PIN_TO_PCINT_52 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_53
#define PIN_TO_PCINT_53 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_54
#define PIN_TO_PCINT_54 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_55
#define PIN_TO_PCINT_55 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_56
#define PIN_TO_PCINT_56 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_57
#define PIN_TO_PCINT_57 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_58
#define PIN_TO_PCINT_58 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_59
#define PIN_TO_PCINT_59 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_60
#define PIN_TO_PCINT_60 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_61
#define PIN_TO_PCINT_61 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_62
#define PIN_TO_PCINT_62 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_63
#define PIN_TO_PCINT_63 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_64
#define PIN_TO_PCINT_64 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_65
#define PIN_TO_PCINT_65 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_66
#define PIN_TO_PCINT_66 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_67
#define PIN_TO_PCINT_67 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_68
#define PIN_TO_PCINT_68 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_69
#define PIN_TO_PCINT_69 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_70
#define PIN_TO_PCINT_70 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_71
#define PIN_TO_PCINT_71 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_72
#define PIN_TO_PCINT_72 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_73
#define PIN_TO_PCINT_73 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_74
#define PIN_TO_PCINT_74 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_75
#define PIN_TO_PCINT_75 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_76
#define PIN_TO_PCINT_76 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_77
#define PIN_TO_PCINT_77 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_78
#define PIN_TO_PCINT_78 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_79
#define PIN_TO_PCINT_79 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_80
#define PIN_TO_PCINT_80 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_81
#define PIN_TO_PCINT_81 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_82
#define PIN_TO_PCINT_82 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_83
#define PIN_TO_PCINT_83 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_84
#define PIN_TO_PCINT_84 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_85
#define PIN_TO_PCINT_85 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_86
#define PIN_TO_PCINT_86 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_87
#define PIN_TO_PCINT_87 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_88
#define PIN_TO_PCINT_88 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_89
#define PIN_TO_PCINT_89 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_90
#define PIN_TO_PCINT_90 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_91
#define PIN_TO_PCINT_91 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_92
#define PIN_TO_PCINT_92 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_93
#define PIN_TO_PCINT_93 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_94
#define PIN_TO_PCINT_94 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_95
#define PIN_TO_PCINT_95 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_96
#define PIN_TO_PCINT_96 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_97
#define PIN_TO_PCINT_97 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_98
#define PIN_TO_PCINT_98 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_99
#define PIN_TO_PCINT_99 NOT_AN_INTERRUPT
#endif

#ifndef PIN_TO_PCINT_A0
#define PIN_TO_PCINT_A0 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A1
#define PIN_TO_PCINT_A1 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A2
#define PIN_TO_PCINT_A2 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A3
#define PIN_TO_PCINT_A3 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A4
#define PIN_TO_PCINT_A4 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A5
#define PIN_TO_PCINT_A5 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A6
#define PIN_TO_PCINT_A6 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A7
#define PIN_TO_PCINT_A7 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A8
#define PIN_TO_PCINT_A8 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A9
#define PIN_TO_PCINT_A9 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A10
#define PIN_TO_PCINT_A10 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A11
#define PIN_TO_PCINT_A11 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A12
#define PIN_TO_PCINT_A12 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A13
#define PIN_TO_PCINT_A13 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A14
#define PIN_TO_PCINT_A14 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A15
#define PIN_TO_PCINT_A15 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A16
#define PIN_TO_PCINT_A16 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A17
#define PIN_TO_PCINT_A17 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A18
#define PIN_TO_PCINT_A18 NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_A19
#define PIN_TO_PCINT_A19 NOT_AN_INTERRUPT
#endif

#ifndef PIN_TO_PCINT_SS
#define PIN_TO_PCINT_SS NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_MOSI
#define PIN_TO_PCINT_MOSI NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_MISO
#define PIN_TO_PCINT_MISO NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_SCK
#define PIN_TO_PCINT_SCK NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_SDA
#define PIN_TO_PCINT_SDA NOT_AN_INTERRUPT
#endif
#ifndef PIN_TO_PCINT_SCL
#define PIN_TO_PCINT_SCL NOT_AN_INTERRUPT
#endif

#endif // include guard
