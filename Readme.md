PinChangeInterrupt Library 1.0
==============================

![Header Picture](header.jpg)

New PinChangeInterrupt with a very resource friendly implementation.
Compared with the normal Interrupts it is even more compact and all available PCINTs can be used.
PinChangeInterrupts are a bit slower than normal Interrupts because of the pin change comparison
but with this library this changing is implemented as small as possible.


**Features:**
* PinChangeInterrupt for many pins
* Usable on every standard Arduino and Attiny as well
* Rising, Falling or Change detection for every pin separately
* Uses less ram & flash than normal Interrupts
* Implementation in fast&compact C

**The following pins are usable for PinChangeInterrupt on normal Arduinos:**
* On Arduino Uno you can use any pin for receiving.
* Arduino Mega: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)
* Arduino Leonardo: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
* With HoodLoader2 you can use pin 1-7 and some other pins which are normally not connected.

Todo:
* Change .cpp in .c?
* Advanced library for people who want to use specific ports, passes the whole trigger variable.

[Comment for feedback on my blog.](http://nicohood.wordpress.com/)

Installation/How to use
=======================

Download the zip, extract and remove the "-master" of the folder.
Install the library [as described here](http://arduino.cc/en/pmwiki.php?n=Guide/Libraries).

### Basic example
The basic example shows you how the library and its syntax work.

You can attach your pins with the attach function and the digitalPinToPinChangeInterrupt(p) definition.
Make sure your attached pin is actually a PinChangeInterrupt as listed above.
Keep in mind that on Arduino Mega the definition excludes some pins like 14 (TX3) and 15 (RX3).
You can still use them by manually passing attachPinChangeInterrupt(PCINT10, CHANGE);

PinChangeInterrupts are always executed after each other. Make sure that the functions are short and have no Serial prints in it.
Lower pins on a port are executed faster. This means PCINT is faster than PCINT7. PCINT8 is on another port (port 1) and faster than PCINT15 for example.
As normal user you might wonder what I am talking about, maybe you should read how PinChangeInterrupts work. Its really important to understand what your are using.
PinChangeInterrupts trigger for pin changes on a whole port so we have to check the difference between the last interrupt.
That's why we also have in general a **delay between the interrupt call and the actual function execution**.

### IRLremote example

To test the IRLremote example install the IRLremote:
https://github.com/NicoHood/IRLremote

This demonstrates how to use the PinChangeInterrupt library together with the IRLremote library. This can be useful if you are running out if normal
interrupt pins or don't have them at all (HoodLoader2). The PinChangeInterrupt library is also smaller than the normal Interrupt library, just a tiny bit slower.


More projects + contact can be found here:
http://nicohood.wordpress.com/

How it works
============

To be continued when I am in the mood :)
Otherwise look at the source, its very simple (depending on your knowledge).

Version History
===============
```
1.0 Release (04.12.2014)
* Added general PinChangeInterrupt functions
* Added support for most Arduino boards
* Added basic example
* Added an example with IRLremote
```


Licence and Copyright
=====================
If you use this library for any cool project let me know!

```
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
```
