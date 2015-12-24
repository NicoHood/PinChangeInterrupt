/*
 Copyright (c) 2014-2015 NicoHood
 See the readme for credit to other people.

 PinChangeInterrupt_HowItWorks
 Shows how to manually setup a single PCINT function with a few helper functions.

 Connect a button/cable to pin 7 and ground.
 The led will change its state if pin 7 changes.

 PinChangeInterrupts are different than normal Interrupts.
 See readme for more information.
 Dont use Serial or delay inside interrupts!
 This library is not compatible with SoftSerial.

 The following pins are usable for PinChangeInterrupt:
 Arduino Uno/Nano/Mini: All pins are usable
 Arduino Mega: 10, 11, 12, 13, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64),
               A11 (65), A12 (66), A13 (67), A14 (68), A15 (69)
 Arduino Leonardo/Micro: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
 HoodLoader2: All (broken out 1-7) pins are usable
 Attiny 24/44/84: All pins are usable
 Attiny 25/45/85: All pins are usable
 Attiny 13: All pins are usable
 Attiny 441/841: All pins are usable
 ATmega644P/ATmega1284P: All pins are usable
 */

//================================================================================
// User Settings
//================================================================================

// choose a valid PinChangeInterrupt pin of your Arduino board
#define PCINT_PIN 7
#define PCINT_MODE CHANGE
#define PCINT_FUNCTION blinkLed

void setup()
{
  // set pins to input with a pullup, led to output
  pinMode(PCINT_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // attach the new PinChangeInterrupt
  attachPinChangeInterrupt();
}

void loop() {
  // empty
}

void blinkLed(void) {
  // switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

//================================================================================
// PCINT Definitions
//================================================================================

#define PCMSK *digitalPinToPCMSK(PCINT_PIN)
#define PCINT digitalPinToPCMSKbit(PCINT_PIN)
#define PCIE  digitalPinToPCICRbit(PCINT_PIN)
#define PCPIN *portInputRegister(digitalPinToPort(PCINT_PIN))

#if (PCIE == 0)
#define PCINT_vect PCINT0_vect
#elif (PCIE == 1)
#define PCINT_vect PCINT1_vect
#elif (PCIE == 2)
#define PCINT_vect PCINT2_vect
#else
#error This board doesnt support PCINT ?
#endif

volatile uint8_t oldPort = 0x00;

void attachPinChangeInterrupt(void) {
  // update the old state to the actual state
  oldPort = PCPIN;

  // pin change mask registers decide which pins are enabled as triggers
  PCMSK |= (1 << PCINT);

  // PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
  PCICR |= (1 << PCIE);
}

void detachPinChangeInterrupt(void) {
  // disable the mask.
  PCMSK &= ~(1 << PCINT);

  // if that's the last one, disable the interrupt.
  if (PCMSK == 0)
    PCICR &= ~(0x01 << PCIE);
}

ISR(PCINT_vect) {
  // get the new and old pin states for port
  uint8_t newPort = PCPIN;

  // compare with the old value to detect a rising or falling
  uint8_t change = newPort ^ oldPort;

  // check which pins are triggered, compared with the settings
  uint8_t trigger = 0x00;
#if (PCINT_MODE == RISING) || (PCINT_MODE == CHANGE)
  uint8_t rising = change & newPort;
  trigger |= (rising & (1 << PCINT));
#endif
#if (PCINT_MODE == FALLING) || (PCINT_MODE == CHANGE)
  uint8_t falling = change & oldPort;
  trigger |= (falling & (1 << PCINT));
#endif

  // save the new state for next comparison
  oldPort = newPort;

  // if our needed pin has changed, call the IRL interrupt function
  if (trigger & (1 << PCINT))
    PCINT_FUNCTION();
}
