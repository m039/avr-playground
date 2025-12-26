#include "komarovo.h"
#include "config.h"

uint8_t buttonPressed;

void setup() {
  buttonSetup();
}

uint8_t delay_ms(uint16_t time) {
  for (uint16_t i = 0; i < time; i++) {
    _delay_ms(1);

    if (isButtonActive()) {
      if (!buttonPressed) {
        return 1;
      }
    } else {
      buttonPressed = 0;
    }
  }

  return 0;
}

void playMelody() {
  for (int thisNote = 0; thisNote < MELODY_SIZE; thisNote++) {   
    tone(MELODY_TONE(thisNote));
    if (delay_ms(MELODY_DURATION(thisNote))) {
      return;
    }
    
    tone(0);
    if (delay_ms(MELODY_NO_TONE_DURATION(thisNote))) {
      return;
    }
  }
}

void loop() {
  if (isButtonActive()) {
    if (buttonPressed)
    {
      return;
    }

    buttonPressed = 1;
    buzzerOn();
    playMelody();
    if (isButtonActive()) {
      buttonPressed = 1;
    }
    buzzerOff();
  } else {
    buttonPressed = 0;
  }

  buzzerOff();

  sleep();
}