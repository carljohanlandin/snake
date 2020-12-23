#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "snake.h"
#include "food.h"

void display_set_snake(snake_t *snake);
void display_clear(void);
void display_update(void);
void display_border_animation(void);
void display_set_border(void);
void display_set_food(food_t *food);
void display_set_score(uint32_t score);
void display_game_over(void);




void display_init();    // Initialize Display
void testdrawline();    // Draw many lines
void testdrawrect();    // Draw rectangles (outlines)
void testfillrect();    // Draw rectangles (filled)
void testdrawcircle();  // Draw circles (outlines)
void testfillcircle();  // Draw circles (filled)
void testdrawroundrect();   // Draw rounded rectangles (outlines)
void testfillroundrect();   // Draw rounded rectangles (filled)
void testdrawtriangle();    // Draw triangles (outlines)
void testfilltriangle();    // Draw triangles (filled)
void testdrawchar();    // Draw characters of the default font
void testdrawstyles();  // Draw 'stylized' characters
void testscrolltext();  // Draw scrolling text
void testdrawbitmap();  // Draw a small bitmap image
void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h);  // Animate bitmaps

#endif // DISPLAY_H

