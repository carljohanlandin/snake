#ifndef BUTTON_H
#define BUTTON_H

typedef struct button_s {
    bool left;
    bool right;
} button_state_t;

button_state_t *button_init(void);
button_state_t *button_read_state(void);
void button_reset_state(void);

void IRAM_ATTR left_button_pressed(void);
void IRAM_ATTR right_button_pressed(void);


#endif // BUTTON_H
