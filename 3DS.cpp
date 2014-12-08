#include "3DS.h"

3DS_ 3DS;

// Pull a pin to ground to press it
void button_control(char pin, char state) {
    if (pin < 0) {
        return;
    }

    if (state == 0) {
        pinMode(pin, INPUT);
    } else {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
}

// Write analog values to c-stick
void c_stick_control(uint8_t x_val, uint8_t y_val) {
    analogWrite(3DS.X_AXIS, (int)(255 - x_val));
    analogWrite(3DS.Y_AXIS, (int)(y_val));
}

void initialize_3ds_pins(void) {
    const uint8_t NUM_PINS = 11;
    uint8_t pin_map[NUM_PINS] = {
        3DS.A, 3DS.B, 3DS.X, 3DS.Y, 3DS.L, 3DS.R,
        3DS.LEFT, 3DS.RIGHT, 3DS.UP, 3DS.DOWN, 3DS.START
    };

    // Set up all button pins, and give them initial values
    for (int i = 0; i < NUM_PINS; i++) {
        pinMode(pin_map[i], INPUT);
        button_control(pin_map[i], 0);
    }

    // Set up c-stick pins
    pinMode(3DS.X_AXIS, OUTPUT);
    pinMode(3DS.Y_AXIS, OUTPUT);
    analogWrite(3DS.X_AXIS, 30);
    analogWrite(3DS.Y_AXIS, 200);
}