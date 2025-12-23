#ifndef CONFIG__
#define CONFIG__

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#define BUTTON_BIT 1 // B1

#define BUZZER_BIT 0 // B0

#define buttonSetup() \
  DDRB &= ~(1 << BUTTON_BIT);\
  PORTB |= (1 << BUTTON_BIT);\
  GIMSK |= (1 << PCIE);\
  PCMSK |= (1 << BUTTON_BIT);\
  sei();

#define buzzerOff() \
  TCCR0A = 0;\
  DDRB &= ~(1 << BUZZER_BIT);

#define buzzerOn() \
  DDRB |= (1 << BUZZER_BIT);\
  TCCR0A = (1 << COM0A0) | (1 << WGM00) | (0 << WGM01);

#define sleep() \
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);\
  sleep_enable();\
  sleep_cpu();\
  sleep_disable();

#define isButtonActive()    !(PINB & (1 << BUTTON_BIT))

#endif