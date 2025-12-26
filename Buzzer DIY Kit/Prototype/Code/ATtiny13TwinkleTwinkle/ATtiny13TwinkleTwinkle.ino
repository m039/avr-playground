#define BUZZER_PIN 0 // B0

// Musical notes (frequencies in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define REST     0

#define ND(x) (((uint32_t)((1000.0 / x) * 1.30) << 16) | (1000 / x))

// Simple melody: "Twinkle Twinkle Little Star"
const uint16_t melody[] PROGMEM = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, REST,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, REST
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
const uint32_t noteDurations[] PROGMEM = {
  ND(4), ND(4), ND(4), ND(4), ND(4), ND(4), ND(2), ND(4),
  ND(4), ND(4), ND(4), ND(4), ND(4), ND(4), ND(2), ND(4)
};

void setup() {
}

void playMelody() {
  for (int thisNote = 0; thisNote < 16; thisNote++) {
    // Calculate the note duration
    uint32_t nd = pgm_read_dword(&noteDurations[thisNote]);
    
    tone(BUZZER_PIN, pgm_read_word(&melody[thisNote]), nd & 0xFFFF);
    
    // Pause between notes
    delay(nd >> 16);
    
    // Stop the tone
    noTone(BUZZER_PIN);
  }
}

void loop() {
  playMelody();
  delay(1000);
}