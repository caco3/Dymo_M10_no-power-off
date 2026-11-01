#include <Arduino.h>

#define TOGGLE_PIN 3
#define PERIOD_MS 2.5 * 60 * 1000 // overall cycle time (2.5 minutes)
#define PULSE_MS 300              // how long each button press (LOW) lasts
#define PULSE_SPACING_MS 600      // time between the two presses

static void press() {
    pinMode(TOGGLE_PIN, OUTPUT);
    digitalWrite(TOGGLE_PIN, LOW);
    delay(PULSE_MS);
    pinMode(TOGGLE_PIN, INPUT); // release to hi-Z
}

void setup() {
    pinMode(TOGGLE_PIN, INPUT); // start tri-stated (hi-Z)
}

void loop() {
    unsigned long start = millis();

    press();
    delay(PULSE_SPACING_MS - PULSE_MS);
    press();

    unsigned long elapsed = millis() - start;
    if (elapsed < PERIOD_MS) {
        delay(PERIOD_MS - elapsed);
    }
}
