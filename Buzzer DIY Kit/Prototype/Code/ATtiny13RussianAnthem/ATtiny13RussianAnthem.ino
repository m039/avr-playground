#include "russian_anthem.h"

#define BUZZER_PIN 0 // B0

void setup() {
  DDRB |= (1 << BUZZER_PIN);
  TCCR0A = (1 << COM0A0) | (1 << WGM00) | (0 << WGM01);
}

uint8_t mDelay(uint16_t time) {
  for (uint16_t i = 0; i < time; i++) {
    _delay_ms(1);

    // if (isButtonActive()) {
    //   if (!buttonPressed) {
    //     return 1;
    //   }
    // } else {
    //   buttonPressed = 0;
    // }
  }

  return 0;
}

void playMelody() {
  for (int thisNote = 0; thisNote < MELODY_SIZE; thisNote++) {   
    mTone(MELODY_TONE(thisNote));
    if (mDelay(MELODY_DURATION(thisNote))) {
      return;
    }
    
    mTone(0);
    if (mDelay(MELODY_NO_TONE_DURATION(thisNote))) {
      return;
    }
  }
}

void loop() {
  playMelody();
  delay(1000);
}