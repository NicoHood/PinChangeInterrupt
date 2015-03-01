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

#ifndef PINCHANGEINTERRUPTPINS_H
#define PINCHANGEINTERRUPTPINS_H

//================================================================================
// Helper Macros
//================================================================================

/* Disable all pins on a port, if port is deactivated
We could then check every pin -> pcint definition
But that'd be a mess and doesnt help
Users who deactivate stuff should know
what the are doing. */
/*
for (int port = 0; port < 3; port++) {
Serial.print("#if !defined(PCINT_ENABLE_PORT");
Serial.print(port);
Serial.println(")");
for (int i = 0; i < 8; i++) {
Serial.print("#if defined(PCINT_ENABLE_PCINT");
Serial.print(port * 8 + i);
Serial.println(")");
Serial.print("#undef PCINT_ENABLE_PCINT");
Serial.println(port * 8 + i);
Serial.println("#endif");
}
Serial.println("#endif");
Serial.println();
}
*/
#if !defined(PCINT_ENABLE_PORT0)
#if defined(PCINT_ENABLE_PCINT0)
#undef PCINT_ENABLE_PCINT0
#endif
#if defined(PCINT_ENABLE_PCINT1)
#undef PCINT_ENABLE_PCINT1
#endif
#if defined(PCINT_ENABLE_PCINT2)
#undef PCINT_ENABLE_PCINT2
#endif
#if defined(PCINT_ENABLE_PCINT3)
#undef PCINT_ENABLE_PCINT3
#endif
#if defined(PCINT_ENABLE_PCINT4)
#undef PCINT_ENABLE_PCINT4
#endif
#if defined(PCINT_ENABLE_PCINT5)
#undef PCINT_ENABLE_PCINT5
#endif
#if defined(PCINT_ENABLE_PCINT6)
#undef PCINT_ENABLE_PCINT6
#endif
#if defined(PCINT_ENABLE_PCINT7)
#undef PCINT_ENABLE_PCINT7
#endif
#endif

#if !defined(PCINT_ENABLE_PORT1)
#if defined(PCINT_ENABLE_PCINT8)
#undef PCINT_ENABLE_PCINT8
#endif
#if defined(PCINT_ENABLE_PCINT9)
#undef PCINT_ENABLE_PCINT9
#endif
#if defined(PCINT_ENABLE_PCINT10)
#undef PCINT_ENABLE_PCINT10
#endif
#if defined(PCINT_ENABLE_PCINT11)
#undef PCINT_ENABLE_PCINT11
#endif
#if defined(PCINT_ENABLE_PCINT12)
#undef PCINT_ENABLE_PCINT12
#endif
#if defined(PCINT_ENABLE_PCINT13)
#undef PCINT_ENABLE_PCINT13
#endif
#if defined(PCINT_ENABLE_PCINT14)
#undef PCINT_ENABLE_PCINT14
#endif
#if defined(PCINT_ENABLE_PCINT15)
#undef PCINT_ENABLE_PCINT15
#endif
#endif

#if !defined(PCINT_ENABLE_PORT2)
#if defined(PCINT_ENABLE_PCINT16)
#undef PCINT_ENABLE_PCINT16
#endif
#if defined(PCINT_ENABLE_PCINT17)
#undef PCINT_ENABLE_PCINT17
#endif
#if defined(PCINT_ENABLE_PCINT18)
#undef PCINT_ENABLE_PCINT18
#endif
#if defined(PCINT_ENABLE_PCINT19)
#undef PCINT_ENABLE_PCINT19
#endif
#if defined(PCINT_ENABLE_PCINT20)
#undef PCINT_ENABLE_PCINT20
#endif
#if defined(PCINT_ENABLE_PCINT21)
#undef PCINT_ENABLE_PCINT21
#endif
#if defined(PCINT_ENABLE_PCINT22)
#undef PCINT_ENABLE_PCINT22
#endif
#if defined(PCINT_ENABLE_PCINT23)
#undef PCINT_ENABLE_PCINT23
#endif
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


/*
for (int i = 0; i < 24; i++) {
Serial.print("#ifdef PCINT");
Serial.println(i);
Serial.print("#define PCINT_HAS_PCINT");
Serial.print(i);
Serial.println(" true");
Serial.println("#else");
Serial.print("#define PCINT_HAS_PCINT");
Serial.print(i);
Serial.println(" false");
Serial.println("#endif");
}
*/
#ifdef PCINT0
#define PCINT_HAS_PCINT0 true
#else
#define PCINT_HAS_PCINT0 false
#endif
#ifdef PCINT1
#define PCINT_HAS_PCINT1 true
#else
#define PCINT_HAS_PCINT1 false
#endif
#ifdef PCINT2
#define PCINT_HAS_PCINT2 true
#else
#define PCINT_HAS_PCINT2 false
#endif
#ifdef PCINT3
#define PCINT_HAS_PCINT3 true
#else
#define PCINT_HAS_PCINT3 false
#endif
#ifdef PCINT4
#define PCINT_HAS_PCINT4 true
#else
#define PCINT_HAS_PCINT4 false
#endif
#ifdef PCINT5
#define PCINT_HAS_PCINT5 true
#else
#define PCINT_HAS_PCINT5 false
#endif
#ifdef PCINT6
#define PCINT_HAS_PCINT6 true
#else
#define PCINT_HAS_PCINT6 false
#endif
#ifdef PCINT7
#define PCINT_HAS_PCINT7 true
#else
#define PCINT_HAS_PCINT7 false
#endif
#ifdef PCINT8
#define PCINT_HAS_PCINT8 true
#else
#define PCINT_HAS_PCINT8 false
#endif
#ifdef PCINT9
#define PCINT_HAS_PCINT9 true
#else
#define PCINT_HAS_PCINT9 false
#endif
#ifdef PCINT10
#define PCINT_HAS_PCINT10 true
#else
#define PCINT_HAS_PCINT10 false
#endif
#ifdef PCINT11
#define PCINT_HAS_PCINT11 true
#else
#define PCINT_HAS_PCINT11 false
#endif
#ifdef PCINT12
#define PCINT_HAS_PCINT12 true
#else
#define PCINT_HAS_PCINT12 false
#endif
#ifdef PCINT13
#define PCINT_HAS_PCINT13 true
#else
#define PCINT_HAS_PCINT13 false
#endif
#ifdef PCINT14
#define PCINT_HAS_PCINT14 true
#else
#define PCINT_HAS_PCINT14 false
#endif
#ifdef PCINT15
#define PCINT_HAS_PCINT15 true
#else
#define PCINT_HAS_PCINT15 false
#endif
#ifdef PCINT16
#define PCINT_HAS_PCINT16 true
#else
#define PCINT_HAS_PCINT16 false
#endif
#ifdef PCINT17
#define PCINT_HAS_PCINT17 true
#else
#define PCINT_HAS_PCINT17 false
#endif
#ifdef PCINT18
#define PCINT_HAS_PCINT18 true
#else
#define PCINT_HAS_PCINT18 false
#endif
#ifdef PCINT19
#define PCINT_HAS_PCINT19 true
#else
#define PCINT_HAS_PCINT19 false
#endif
#ifdef PCINT20
#define PCINT_HAS_PCINT20 true
#else
#define PCINT_HAS_PCINT20 false
#endif
#ifdef PCINT21
#define PCINT_HAS_PCINT21 true
#else
#define PCINT_HAS_PCINT21 false
#endif
#ifdef PCINT22
#define PCINT_HAS_PCINT22 true
#else
#define PCINT_HAS_PCINT22 false
#endif
#ifdef PCINT23
#define PCINT_HAS_PCINT23 true
#else
#define PCINT_HAS_PCINT23 false
#endif// count numbers of available pins on each port/*for (int port = 0; port < 3; port++) {
Serial.print("#define PCINT_NUM_PINS_PORT");
Serial.print(port);
Serial.println(" ( \\");
for (int i = 0; i < 8; i++) {
Serial.print("PCINT_HAS_PCINT");
Serial.print(port * 8 + i);
if (i != 7)
Serial.println(" + \\");
}
Serial.println(")");
Serial.println();
}*/#define PCINT_NUM_PINS_PORT0 ( \
PCINT_HAS_PCINT0 + \
PCINT_HAS_PCINT1 + \
PCINT_HAS_PCINT2 + \
PCINT_HAS_PCINT3 + \
PCINT_HAS_PCINT4 + \
PCINT_HAS_PCINT5 + \
PCINT_HAS_PCINT6 + \
PCINT_HAS_PCINT7)

#define PCINT_NUM_PINS_PORT1 ( \
PCINT_HAS_PCINT8 + \
PCINT_HAS_PCINT9 + \
PCINT_HAS_PCINT10 + \
PCINT_HAS_PCINT11 + \
PCINT_HAS_PCINT12 + \
PCINT_HAS_PCINT13 + \
PCINT_HAS_PCINT14 + \
PCINT_HAS_PCINT15)

#define PCINT_NUM_PINS_PORT2 ( \
PCINT_HAS_PCINT16 + \
PCINT_HAS_PCINT17 + \
PCINT_HAS_PCINT18 + \
PCINT_HAS_PCINT19 + \
PCINT_HAS_PCINT20 + \
PCINT_HAS_PCINT21 + \
PCINT_HAS_PCINT22 + \
PCINT_HAS_PCINT23)// number of available hardware pins#define EXTERNAL_NUM_PINCHANGEINTERRUPT ( \PCINT_NUM_PINS_PORT0 + \PCINT_NUM_PINS_PORT1 + \PCINT_NUM_PINS_PORT2)// number of used hardware pins#define EXTERNAL_NUM_USED_PINCHANGEINTERRUPT ( \PCINT_NUM_USED_PINS_PORT0 + \PCINT_NUM_USED_PINS_PORT1 + \PCINT_NUM_USED_PINS_PORT2)
// check if pins are physically available and enabled
/*
for (int i = 0; i < 24; i++) {
Serial.print("#if (PCINT_HAS_PCINT");
Serial.print(i);
Serial.print(" == true) && defined(PCINT_ENABLE_PCINT");
Serial.print(i);
Serial.println(")");
Serial.print("#define PCINT_USE_PCINT");
Serial.print(i);
Serial.println(" true");
Serial.println("#else");
Serial.print("#define PCINT_USE_PCINT");
Serial.print(i);
Serial.println(" false");
Serial.println("#endif");
}
*/
#if (PCINT_HAS_PCINT0 == true) && defined(PCINT_ENABLE_PCINT0)
#define PCINT_USE_PCINT0 true
#else
#define PCINT_USE_PCINT0 false
#endif
#if (PCINT_HAS_PCINT1 == true) && defined(PCINT_ENABLE_PCINT1)
#define PCINT_USE_PCINT1 true
#else
#define PCINT_USE_PCINT1 false
#endif
#if (PCINT_HAS_PCINT2 == true) && defined(PCINT_ENABLE_PCINT2)
#define PCINT_USE_PCINT2 true
#else
#define PCINT_USE_PCINT2 false
#endif
#if (PCINT_HAS_PCINT3 == true) && defined(PCINT_ENABLE_PCINT3)
#define PCINT_USE_PCINT3 true
#else
#define PCINT_USE_PCINT3 false
#endif
#if (PCINT_HAS_PCINT4 == true) && defined(PCINT_ENABLE_PCINT4)
#define PCINT_USE_PCINT4 true
#else
#define PCINT_USE_PCINT4 false
#endif
#if (PCINT_HAS_PCINT5 == true) && defined(PCINT_ENABLE_PCINT5)
#define PCINT_USE_PCINT5 true
#else
#define PCINT_USE_PCINT5 false
#endif
#if (PCINT_HAS_PCINT6 == true) && defined(PCINT_ENABLE_PCINT6)
#define PCINT_USE_PCINT6 true
#else
#define PCINT_USE_PCINT6 false
#endif
#if (PCINT_HAS_PCINT7 == true) && defined(PCINT_ENABLE_PCINT7)
#define PCINT_USE_PCINT7 true
#else
#define PCINT_USE_PCINT7 false
#endif
#if (PCINT_HAS_PCINT8 == true) && defined(PCINT_ENABLE_PCINT8)
#define PCINT_USE_PCINT8 true
#else
#define PCINT_USE_PCINT8 false
#endif
#if (PCINT_HAS_PCINT9 == true) && defined(PCINT_ENABLE_PCINT9)
#define PCINT_USE_PCINT9 true
#else
#define PCINT_USE_PCINT9 false
#endif
#if (PCINT_HAS_PCINT10 == true) && defined(PCINT_ENABLE_PCINT10)
#define PCINT_USE_PCINT10 true
#else
#define PCINT_USE_PCINT10 false
#endif
#if (PCINT_HAS_PCINT11 == true) && defined(PCINT_ENABLE_PCINT11)
#define PCINT_USE_PCINT11 true
#else
#define PCINT_USE_PCINT11 false
#endif
#if (PCINT_HAS_PCINT12 == true) && defined(PCINT_ENABLE_PCINT12)
#define PCINT_USE_PCINT12 true
#else
#define PCINT_USE_PCINT12 false
#endif
#if (PCINT_HAS_PCINT13 == true) && defined(PCINT_ENABLE_PCINT13)
#define PCINT_USE_PCINT13 true
#else
#define PCINT_USE_PCINT13 false
#endif
#if (PCINT_HAS_PCINT14 == true) && defined(PCINT_ENABLE_PCINT14)
#define PCINT_USE_PCINT14 true
#else
#define PCINT_USE_PCINT14 false
#endif
#if (PCINT_HAS_PCINT15 == true) && defined(PCINT_ENABLE_PCINT15)
#define PCINT_USE_PCINT15 true
#else
#define PCINT_USE_PCINT15 false
#endif
#if (PCINT_HAS_PCINT16 == true) && defined(PCINT_ENABLE_PCINT16)
#define PCINT_USE_PCINT16 true
#else
#define PCINT_USE_PCINT16 false
#endif
#if (PCINT_HAS_PCINT17 == true) && defined(PCINT_ENABLE_PCINT17)
#define PCINT_USE_PCINT17 true
#else
#define PCINT_USE_PCINT17 false
#endif
#if (PCINT_HAS_PCINT18 == true) && defined(PCINT_ENABLE_PCINT18)
#define PCINT_USE_PCINT18 true
#else
#define PCINT_USE_PCINT18 false
#endif
#if (PCINT_HAS_PCINT19 == true) && defined(PCINT_ENABLE_PCINT19)
#define PCINT_USE_PCINT19 true
#else
#define PCINT_USE_PCINT19 false
#endif
#if (PCINT_HAS_PCINT20 == true) && defined(PCINT_ENABLE_PCINT20)
#define PCINT_USE_PCINT20 true
#else
#define PCINT_USE_PCINT20 false
#endif
#if (PCINT_HAS_PCINT21 == true) && defined(PCINT_ENABLE_PCINT21)
#define PCINT_USE_PCINT21 true
#else
#define PCINT_USE_PCINT21 false
#endif
#if (PCINT_HAS_PCINT22 == true) && defined(PCINT_ENABLE_PCINT22)
#define PCINT_USE_PCINT22 true
#else
#define PCINT_USE_PCINT22 false
#endif
#if (PCINT_HAS_PCINT23 == true) && defined(PCINT_ENABLE_PCINT23)
#define PCINT_USE_PCINT23 true
#else
#define PCINT_USE_PCINT23 false
#endif


// count numbers of used pins on each port/*for (int port = 0; port < 3; port++) {
Serial.print("#define PCINT_NUM_USED_PINS_PORT");
Serial.print(port);
Serial.println(" ( \\");
for (int i = 0; i < 8; i++) {
Serial.print("PCINT_USE_PCINT");
Serial.print(port * 8 + i);
if (i != 7)
Serial.println(" + \\");
}
Serial.println(")");
Serial.println();
}*/#define PCINT_NUM_USED_PINS_PORT0 ( \
PCINT_USE_PCINT0 + \
PCINT_USE_PCINT1 + \
PCINT_USE_PCINT2 + \
PCINT_USE_PCINT3 + \
PCINT_USE_PCINT4 + \
PCINT_USE_PCINT5 + \
PCINT_USE_PCINT6 + \
PCINT_USE_PCINT7)

#define PCINT_NUM_USED_PINS_PORT1 ( \
PCINT_USE_PCINT8 + \
PCINT_USE_PCINT9 + \
PCINT_USE_PCINT10 + \
PCINT_USE_PCINT11 + \
PCINT_USE_PCINT12 + \
PCINT_USE_PCINT13 + \
PCINT_USE_PCINT14 + \
PCINT_USE_PCINT15)

#define PCINT_NUM_USED_PINS_PORT2 ( \
PCINT_USE_PCINT16 + \
PCINT_USE_PCINT17 + \
PCINT_USE_PCINT18 + \
PCINT_USE_PCINT19 + \
PCINT_USE_PCINT20 + \
PCINT_USE_PCINT21 + \
PCINT_USE_PCINT22 + \
PCINT_USE_PCINT23)


// definitions passed by the preconfiguration
#if defined(PCINT0_vect)
#define PCINT_HAS_PORT0 true
#else
#define PCINT_HAS_PORT0 false
#endif
#if defined(PCINT1_vect)
#define PCINT_HAS_PORT1 true
#else
#define PCINT_HAS_PORT1 false
#endif
#if defined(PCINT2_vect)
#define PCINT_HAS_PORT2 true
#else
#define PCINT_HAS_PORT2 false
#endif
#if defined(PCINT3_vect)
#warning PCINT port 3 is not supported by this library
#endif


// check if ports are physically available and enabled
#if (PCINT_HAS_PORT0 == true) && PCINT_NUM_USED_PINS_PORT0 && defined(PCINT_ENABLE_PORT0)
#define PCINT_USE_PORT0 true
#else
#define PCINT_USE_PORT0 false
#endif
#if (PCINT_HAS_PORT1 == true) && PCINT_NUM_USED_PINS_PORT1 && defined(PCINT_ENABLE_PORT1)
#define PCINT_USE_PORT1 true
#else
#define PCINT_USE_PORT1 false
#endif
#if (PCINT_HAS_PORT2 == true) && PCINT_NUM_USED_PINS_PORT2 && defined(PCINT_ENABLE_PORT2)
#define PCINT_USE_PORT2 true
#else
#define PCINT_USE_PORT2 false
#endif


// number of available ports
#define PCINT_NUM_PORTS ( \
PCINT_HAS_PORT0 + \
PCINT_HAS_PORT1 + \
PCINT_HAS_PORT2)// number of used ports
#define PCINT_NUM_USED_PORTS ( \
PCINT_USE_PORT0 + \
PCINT_USE_PORT1 + \
PCINT_USE_PORT2)


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
