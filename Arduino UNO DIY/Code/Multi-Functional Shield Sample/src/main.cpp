#include <MFShield.h>

MFShield mfs;

void setup ()
{
   Serial.begin (9600);
   /* Handle buttons */
   mfs.onKeyPress ([](uint8_t button) {
   	mfs.beep(10);	// make sound
   	mfs.setLed (button, !mfs.getLed(button)); // toggle onboard leds
   	Serial.println ("Button pressed: " + String(button));
   });
}

void loop ()
{
   /* Display seconds */
   mfs.display (millis() / 1000);

   mfs.loop();
   /* ^ It's important to insert this loop function in the main loop
    *   else numeric display wont work
    */
}