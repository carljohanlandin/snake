#include <Arduino.h>
#include "button.h"

#define DEBOUNCE_TIME 80

volatile uint32_t debounce_timer = 0;

static button_state_t button;

void IRAM_ATTR left_button_pressed(void) {
    if (millis() - DEBOUNCE_TIME >= debounce_timer) {
        debounce_timer = millis();
        button.left = true;
    }
}

void IRAM_ATTR right_button_pressed(void) {
    if (millis() - DEBOUNCE_TIME >= debounce_timer) {
        debounce_timer = millis();
        button.right = true;
    }
}

button_state_t *button_read_state(void) {
    return &button;
}

void button_reset_state(void) {
    button.left = false;
    button.right = false;
}

button_state_t *button_init(void) {
    button = {
        .left = false,
        .right = false,
    };

    return &button;
}

