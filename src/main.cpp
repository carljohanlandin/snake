/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.h"
#include "food.h"
#include "snake.h"
#include "shared.h"
#include "button.h"

static snake_t *snake;
static food_t *food;
static uint32_t score = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLDOWN);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLDOWN);
  attachInterrupt(LEFT_BUTTON_PIN, left_button_pressed, FALLING);
  attachInterrupt(RIGHT_BUTTON_PIN, right_button_pressed, RISING);

  display_init();
  snake = snake_init();
  food = food_init();
}

void loop() {
  if (snake->alive) {
    display_clear();
    display_set_border();
    display_set_score(score);
    display_set_snake(snake);
    display_set_food(food);
    display_update();
    snake_update_direction();
    snake_move();
    if (snake_ate_food(food)) {
      score++;
      food_generate_new(snake);
    }
    delay(5);
  }
  else {
    display_game_over();
  }
}



