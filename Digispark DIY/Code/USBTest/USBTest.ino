#include <EasyHID.h>

void setup() {
  HID.begin();
  pinMode(1, OUTPUT);
  pinMode(0, INPUT_PULLUP);
}

bool buttonState;

void loop() {
  bool bs = digitalRead(0) == 1;
  if (bs != buttonState) {
    buttonState = bs;
    if (!bs) {
      Keyboard.click(KEY_A);
    }
  }
  
  HID.tick();
}