#include <Arduino.h>
#include "food.h"
#include "snake.h"
#include "shared.h"

static food_t food;

void food_generate_new(void *s) {
    snake_t *snake = (snake_t *)s;
    bool food_collide;
    do {
        food_collide = false;
        food.x = random(0, SCREEN_WIDTH);
        food.y = random(16, SCREEN_HEIGHT);

        /* Does food collide with snake? */
        for (int i = 0; i <= snake->length; i++) {
            if (snake->pos[i].x == food.x && snake->pos[i].y == food.y) {
                food_collide = true;
                break;
            }
        }
    } while (food_collide);
}

food_t *food_init(void) {
    food.x = 80;
    food.y = 50;

    return &food;
}
