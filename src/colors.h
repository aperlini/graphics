#ifndef __COLORS_H
#define __COLORS_H

typedef struct rgb {
    int r, g, b;
} rgb_t;

typedef enum color_index {
    BLACK,
    GREY,
    LGREY,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
} color;

void set_colors(color name);
#endif
