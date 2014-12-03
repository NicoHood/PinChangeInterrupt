
//================================================================================
// PCINT functions
//================================================================================

// variables to save the last port states and the interrupt settings
static uint8_t oldPorts[3] = {0};
static uint8_t fallingPorts[3] = {0};
static uint8_t risingPorts[3] = {0};

// function prototypes
inline void attachPinChangeInterrupt(const uint8_t pin, const uint8_t mode);

inline void detachPinChangeInterrupt(const uint8_t pin);

inline void PCintPort(uint8_t port);

void __attribute__((weak)) PinChangeInterruptEvent(uint8_t port);

// TODO how to implement this weak in a .ino?
//void PinChangeInterruptEvent(uint8_t port) {
//}

void attachPinChangeInterrupt(const uint8_t pin, const uint8_t mode) {
  // get PCINT registers and bitmasks
  uint8_t PCIE = pin / 8;
  uint8_t PCINT = pin % 8;

  // save settings related to mode and registers
  if (mode == CHANGE || mode == RISING)
    risingPorts[PCIE] |= (1 << PCINT);
  if (mode == CHANGE || mode == FALLING)
    fallingPorts[PCIE] |= (1 << PCINT);

  // update the old state to the actual state
  oldPorts[PCIE] = *portInputRegister(digitalPinToPort(pin));

  // pin change mask registers decide which pins are enabled as triggers
  switch (PCIE) {
    case 0:
      PCMSK0 |= (1 << PCINT);
      break;
    case 1:
      PCMSK1 |= (1 << PCINT);
      break;
    case 2:
      PCMSK2 |= (1 << PCINT);
      break;
  }

  // PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
  PCICR |= (1 << PCIE);
}


void detachPinChangeInterrupt(const uint8_t pin) {
  // get PCINT registers and bitmasks
  uint8_t PCIE = digitalPinToPCICRbit(pin);
  uint8_t PCINT = digitalPinToPCMSKbit(pin);
  volatile unsigned char* PCMSK = digitalPinToPCMSK(pin);

  // disable the mask.
  *PCMSK &= ~(1 << PCINT);

  // if that's the last one, disable the interrupt.
  if (*PCMSK == 0)
    PCICR &= ~(1 << PCIE);
}


void PCintPort(uint8_t port) {
  // get the new pin states for port
  uint8_t newPort;

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__) // || defined(__AVR_ATmega168__) || defined(__AVR_ATmega168p__)
  if (port == 0)
    newPort = PINB;
  else if (port == 1)
    newPort = PINC;
  else //if (port == 2)
    newPort = PIND;

#elif defined(__AVR_ATmega2560__) // || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega128RFA1__) || defined(__AVR_ATmega256RFR2__)
  if (port == 0)
    newPort = PINB;
  else if (port == 1)
    newPort = (PINE & (1 << 0)) | ((PINJ & 0x7F) << 1);
  else //if (port == 2)
    newPort = PINK;

#elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
  // u4 Series has only 7 PCINT
  //if (port == 0)
  newPort = (PINB & 0x7F);

#elif defined(__AVR_AT90USB82__) || defined(__AVR_AT90USB162__) || defined(__AVR_ATmega32U2__) || defined(__AVR_ATmega16U2__) || defined(__AVR_ATmega8U2__)
  // u2 Series has crappy pin mappings for port 1
  if (port == 0)
    newPort = PINB;
  else //if (port == 1)
    newPort = ((PINC >> 6) & (1 << 0)) | ((PINC >> 4) & (1 << 1)) |  ((PINC >> 2) & (1 << 2)) | ((PINC << 1) & (1 << 3)) | ((PIND >> 1) & (1 << 4));


#else
#error PinChangeInterrupt library doesnt support this MCU yet.

#endif


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
      PinChangeInterruptEvent(i + 8 * port);

    trigger >>= 1;
    i++;
  }

  // save the new state for next comparison
  oldPorts[port] = newPort;
}

#if defined(PCINT0_vect)
ISR(PCINT0_vect) {
  PCintPort(0);
}
#endif

#if defined(PCINT1_vect)
ISR(PCINT1_vect) {
  PCintPort(1);
}
#endif

#if defined(PCINT2_vect)
ISR(PCINT2_vect) {
  PCintPort(2);
}
#endif

#if defined(PCINT3_vect)
ISR(PCINT2_vect) {
  //TODO currently not supported. which avr has 3 PCINT?
  //PCintPort(3);
}
#endif
