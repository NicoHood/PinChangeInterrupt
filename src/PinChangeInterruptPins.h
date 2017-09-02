/*
Copyright (c) 2014-2017 NicoHood
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

// include guard
#pragma once

/*
The strategy in this file:

0. Makefile optimization:
   To disable PCINT/PORTs via makefile use -DPCINT_DISABLE_PORT0 etc.
   This will undef a previously defined PCINT_ENABLE_PORT0.

1. Reduce the user settings to the enabled pins.
   If the whole port is deactivated, also disable all pins on this port.

2. Define the hardware available pins/ports.

3. Compare the hardware definition with the enabled pin definitions.
   If the pin is available and enabled, create a makro to use the pin.

4. Count all used pins (for each port).

5. If there are no pins used on a port, do not use the port

6. Finally we have a clear defintion of the used pins/ports like this:
PCINT_USE_PCINT0 (true/false)
PCINT_USE_PORT0 (true/false)

Other definitions that can be used:
PCINT_HAS_PORT0 (true/false)
PCINT_HAS_PCINT0 (true/false)
PCINT_NUM_PINS_PORT0 (0-8)
PCINT_NUM_USED_PINS_PORT0 (0-8)
EXTERNAL_NUM_PINCHANGEINTERRUPT (0-24)
EXTERNAL_NUM_USED_PINCHANGEINTERRUPT (0-24)
PCINT_NUM_PORTS (0-3)
PCINT_NUM_USED_PORTS (0-3)
*/

//================================================================================
// Disabled Pins
//================================================================================
/*
for (int port = 0; port < 4; port++) {
  Serial.print("#if defined(PCINT_ENABLE_PORT");
  Serial.print(port);
  Serial.print(") && defined(PCINT_DISABLE_PORT");
  Serial.print(port);
  Serial.println(")");
  Serial.print("#undef PCINT_ENABLE_PORT");
  Serial.println(port);
  Serial.println("#endif");
  Serial.println();
}

for (int i = 0; i < 32; i++) {
  Serial.print("#if defined(PCINT_ENABLE_PCINT");
  Serial.print(i);
  Serial.print(") && defined(PCINT_DISABLE_PCINT");
  Serial.print(i);
  Serial.println(")");
  Serial.print("#undef PCINT_ENABLE_PCINT");
  Serial.println(i);
  Serial.println("#endif");
  Serial.println();
}
*/
#if defined(PCINT_ENABLE_PORT0) && defined(PCINT_DISABLE_PORT0)
#undef PCINT_ENABLE_PORT0
#endif

#if defined(PCINT_ENABLE_PORT1) && defined(PCINT_DISABLE_PORT1)
#undef PCINT_ENABLE_PORT1
#endif

#if defined(PCINT_ENABLE_PORT2) && defined(PCINT_DISABLE_PORT2)
#undef PCINT_ENABLE_PORT2
#endif

#if defined(PCINT_ENABLE_PORT3) && defined(PCINT_DISABLE_PORT3)
#undef PCINT_ENABLE_PORT3
#endif

#if defined(PCINT_ENABLE_PCINT0) && defined(PCINT_DISABLE_PCINT0)
#undef PCINT_ENABLE_PCINT0
#endif

#if defined(PCINT_ENABLE_PCINT1) && defined(PCINT_DISABLE_PCINT1)
#undef PCINT_ENABLE_PCINT1
#endif

#if defined(PCINT_ENABLE_PCINT2) && defined(PCINT_DISABLE_PCINT2)
#undef PCINT_ENABLE_PCINT2
#endif

#if defined(PCINT_ENABLE_PCINT3) && defined(PCINT_DISABLE_PCINT3)
#undef PCINT_ENABLE_PCINT3
#endif

#if defined(PCINT_ENABLE_PCINT4) && defined(PCINT_DISABLE_PCINT4)
#undef PCINT_ENABLE_PCINT4
#endif

#if defined(PCINT_ENABLE_PCINT5) && defined(PCINT_DISABLE_PCINT5)
#undef PCINT_ENABLE_PCINT5
#endif

#if defined(PCINT_ENABLE_PCINT6) && defined(PCINT_DISABLE_PCINT6)
#undef PCINT_ENABLE_PCINT6
#endif

#if defined(PCINT_ENABLE_PCINT7) && defined(PCINT_DISABLE_PCINT7)
#undef PCINT_ENABLE_PCINT7
#endif

#if defined(PCINT_ENABLE_PCINT8) && defined(PCINT_DISABLE_PCINT8)
#undef PCINT_ENABLE_PCINT8
#endif

#if defined(PCINT_ENABLE_PCINT9) && defined(PCINT_DISABLE_PCINT9)
#undef PCINT_ENABLE_PCINT9
#endif

#if defined(PCINT_ENABLE_PCINT10) && defined(PCINT_DISABLE_PCINT10)
#undef PCINT_ENABLE_PCINT10
#endif

#if defined(PCINT_ENABLE_PCINT11) && defined(PCINT_DISABLE_PCINT11)
#undef PCINT_ENABLE_PCINT11
#endif

#if defined(PCINT_ENABLE_PCINT12) && defined(PCINT_DISABLE_PCINT12)
#undef PCINT_ENABLE_PCINT12
#endif

#if defined(PCINT_ENABLE_PCINT13) && defined(PCINT_DISABLE_PCINT13)
#undef PCINT_ENABLE_PCINT13
#endif

#if defined(PCINT_ENABLE_PCINT14) && defined(PCINT_DISABLE_PCINT14)
#undef PCINT_ENABLE_PCINT14
#endif

#if defined(PCINT_ENABLE_PCINT15) && defined(PCINT_DISABLE_PCINT15)
#undef PCINT_ENABLE_PCINT15
#endif

#if defined(PCINT_ENABLE_PCINT16) && defined(PCINT_DISABLE_PCINT16)
#undef PCINT_ENABLE_PCINT16
#endif

#if defined(PCINT_ENABLE_PCINT17) && defined(PCINT_DISABLE_PCINT17)
#undef PCINT_ENABLE_PCINT17
#endif

#if defined(PCINT_ENABLE_PCINT18) && defined(PCINT_DISABLE_PCINT18)
#undef PCINT_ENABLE_PCINT18
#endif

#if defined(PCINT_ENABLE_PCINT19) && defined(PCINT_DISABLE_PCINT19)
#undef PCINT_ENABLE_PCINT19
#endif

#if defined(PCINT_ENABLE_PCINT20) && defined(PCINT_DISABLE_PCINT20)
#undef PCINT_ENABLE_PCINT20
#endif

#if defined(PCINT_ENABLE_PCINT21) && defined(PCINT_DISABLE_PCINT21)
#undef PCINT_ENABLE_PCINT21
#endif

#if defined(PCINT_ENABLE_PCINT22) && defined(PCINT_DISABLE_PCINT22)
#undef PCINT_ENABLE_PCINT22
#endif

#if defined(PCINT_ENABLE_PCINT23) && defined(PCINT_DISABLE_PCINT23)
#undef PCINT_ENABLE_PCINT23
#endif

#if defined(PCINT_ENABLE_PCINT24) && defined(PCINT_DISABLE_PCINT24)
#undef PCINT_ENABLE_PCINT24
#endif

#if defined(PCINT_ENABLE_PCINT25) && defined(PCINT_DISABLE_PCINT25)
#undef PCINT_ENABLE_PCINT25
#endif

#if defined(PCINT_ENABLE_PCINT26) && defined(PCINT_DISABLE_PCINT26)
#undef PCINT_ENABLE_PCINT26
#endif

#if defined(PCINT_ENABLE_PCINT27) && defined(PCINT_DISABLE_PCINT27)
#undef PCINT_ENABLE_PCINT27
#endif

#if defined(PCINT_ENABLE_PCINT28) && defined(PCINT_DISABLE_PCINT28)
#undef PCINT_ENABLE_PCINT28
#endif

#if defined(PCINT_ENABLE_PCINT29) && defined(PCINT_DISABLE_PCINT29)
#undef PCINT_ENABLE_PCINT29
#endif

#if defined(PCINT_ENABLE_PCINT30) && defined(PCINT_DISABLE_PCINT30)
#undef PCINT_ENABLE_PCINT30
#endif

#if defined(PCINT_ENABLE_PCINT31) && defined(PCINT_DISABLE_PCINT31)
#undef PCINT_ENABLE_PCINT31
#endif


//================================================================================
// Enabled Pins
//================================================================================

/* Disable all pins on a port, if port is deactivated
We could then check every pin -> port definition
But that'd be a mess and doesnt help
Users who deactivate stuff should know
what the are doing.
So we use the enabled pins for all next definitions*/
/*
for (int port = 0; port < 4; port++) {
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

#if !defined(PCINT_ENABLE_PORT3)
#if defined(PCINT_ENABLE_PCINT24)
#undef PCINT_ENABLE_PCINT24
#endif
#if defined(PCINT_ENABLE_PCINT25)
#undef PCINT_ENABLE_PCINT25
#endif
#if defined(PCINT_ENABLE_PCINT26)
#undef PCINT_ENABLE_PCINT26
#endif
#if defined(PCINT_ENABLE_PCINT27)
#undef PCINT_ENABLE_PCINT27
#endif
#if defined(PCINT_ENABLE_PCINT28)
#undef PCINT_ENABLE_PCINT28
#endif
#if defined(PCINT_ENABLE_PCINT29)
#undef PCINT_ENABLE_PCINT29
#endif
#if defined(PCINT_ENABLE_PCINT30)
#undef PCINT_ENABLE_PCINT30
#endif
#if defined(PCINT_ENABLE_PCINT31)
#undef PCINT_ENABLE_PCINT31
#endif
#endif


//================================================================================
// Hardware Definitions
//================================================================================

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
#define PCINT_HAS_PORT3 true
#else
#define PCINT_HAS_PORT3 false
#endif

// number of available ports
#define PCINT_NUM_PORTS ( \
PCINT_HAS_PORT0 + \
PCINT_HAS_PORT1 + \
PCINT_HAS_PORT2 + \
PCINT_HAS_PORT3)

/*
for (int i = 0; i < 32; i++) {
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
#endif
#ifdef PCINT24
#define PCINT_HAS_PCINT24 true
#else
#define PCINT_HAS_PCINT24 false
#endif
#ifdef PCINT25
#define PCINT_HAS_PCINT25 true
#else
#define PCINT_HAS_PCINT25 false
#endif
#ifdef PCINT26
#define PCINT_HAS_PCINT26 true
#else
#define PCINT_HAS_PCINT26 false
#endif
#ifdef PCINT27
#define PCINT_HAS_PCINT27 true
#else
#define PCINT_HAS_PCINT27 false
#endif
#ifdef PCINT28
#define PCINT_HAS_PCINT28 true
#else
#define PCINT_HAS_PCINT28 false
#endif
#ifdef PCINT29
#define PCINT_HAS_PCINT29 true
#else
#define PCINT_HAS_PCINT29 false
#endif
#ifdef PCINT30
#define PCINT_HAS_PCINT30 true
#else
#define PCINT_HAS_PCINT30 false
#endif
#ifdef PCINT31
#define PCINT_HAS_PCINT31 true
#else
#define PCINT_HAS_PCINT31 false
#endif


// count numbers of available pins on each port
/*
for (int port = 0; port < 4; port++) {
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
}
*/
#define PCINT_NUM_PINS_PORT0 ( \
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
PCINT_HAS_PCINT23)

#define PCINT_NUM_PINS_PORT3 ( \
PCINT_HAS_PCINT24 + \
PCINT_HAS_PCINT25 + \
PCINT_HAS_PCINT26 + \
PCINT_HAS_PCINT27 + \
PCINT_HAS_PCINT28 + \
PCINT_HAS_PCINT29 + \
PCINT_HAS_PCINT30 + \
PCINT_HAS_PCINT31)


// number of available hardware pins
#define EXTERNAL_NUM_PINCHANGEINTERRUPT ( \
PCINT_NUM_PINS_PORT0 + \
PCINT_NUM_PINS_PORT1 + \
PCINT_NUM_PINS_PORT2 + \
PCINT_NUM_PINS_PORT3)


//================================================================================
// Used Pins
//================================================================================

// check if pins are physically available and enabled
/*
for (int i = 0; i < 32; i++) {
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
#if (PCINT_HAS_PCINT24 == true) && defined(PCINT_ENABLE_PCINT24)
#define PCINT_USE_PCINT24 true
#else
#define PCINT_USE_PCINT24 false
#endif
#if (PCINT_HAS_PCINT25 == true) && defined(PCINT_ENABLE_PCINT25)
#define PCINT_USE_PCINT25 true
#else
#define PCINT_USE_PCINT25 false
#endif
#if (PCINT_HAS_PCINT26 == true) && defined(PCINT_ENABLE_PCINT26)
#define PCINT_USE_PCINT26 true
#else
#define PCINT_USE_PCINT26 false
#endif
#if (PCINT_HAS_PCINT27 == true) && defined(PCINT_ENABLE_PCINT27)
#define PCINT_USE_PCINT27 true
#else
#define PCINT_USE_PCINT27 false
#endif
#if (PCINT_HAS_PCINT28 == true) && defined(PCINT_ENABLE_PCINT28)
#define PCINT_USE_PCINT28 true
#else
#define PCINT_USE_PCINT28 false
#endif
#if (PCINT_HAS_PCINT29 == true) && defined(PCINT_ENABLE_PCINT29)
#define PCINT_USE_PCINT29 true
#else
#define PCINT_USE_PCINT29 false
#endif
#if (PCINT_HAS_PCINT30 == true) && defined(PCINT_ENABLE_PCINT30)
#define PCINT_USE_PCINT30 true
#else
#define PCINT_USE_PCINT30 false
#endif
#if (PCINT_HAS_PCINT31 == true) && defined(PCINT_ENABLE_PCINT31)
#define PCINT_USE_PCINT31 true
#else
#define PCINT_USE_PCINT31 false
#endif


//================================================================================
// Number Used Pins
//================================================================================

// count numbers of used pins on each port
/*
for (int port = 0; port < 4; port++) {
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
}
*/
#define PCINT_NUM_USED_PINS_PORT0 ( \
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

#define PCINT_NUM_USED_PINS_PORT3 ( \
PCINT_USE_PCINT24 + \
PCINT_USE_PCINT25 + \
PCINT_USE_PCINT26 + \
PCINT_USE_PCINT27 + \
PCINT_USE_PCINT28 + \
PCINT_USE_PCINT29 + \
PCINT_USE_PCINT30 + \
PCINT_USE_PCINT31)


// number of used hardware pins
#define EXTERNAL_NUM_USED_PINCHANGEINTERRUPT ( \
PCINT_NUM_USED_PINS_PORT0 + \
PCINT_NUM_USED_PINS_PORT1 + \
PCINT_NUM_USED_PINS_PORT2 + \
PCINT_NUM_USED_PINS_PORT3)

//================================================================================
// Used Ports
//================================================================================

// check if ports are used
#if PCINT_NUM_USED_PINS_PORT0
#define PCINT_USE_PORT0 true
#else
#define PCINT_USE_PORT0 false
#endif
#if PCINT_NUM_USED_PINS_PORT1
#define PCINT_USE_PORT1 true
#else
#define PCINT_USE_PORT1 false
#endif
#if PCINT_NUM_USED_PINS_PORT2
#define PCINT_USE_PORT2 true
#else
#define PCINT_USE_PORT2 false
#endif
#if PCINT_NUM_USED_PINS_PORT3
#define PCINT_USE_PORT3 true
#else
#define PCINT_USE_PORT3 false
#endif

// number of used ports
#define PCINT_NUM_USED_PORTS ( \
PCINT_USE_PORT0 + \
PCINT_USE_PORT1 + \
PCINT_USE_PORT2 + \
PCINT_USE_PORT3)
