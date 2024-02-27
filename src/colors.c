#include "colors.h"
#include "gfx.h"

rgb_t colors[] = {
    {0, 0, 0}, // black
    {100, 100, 100}, // grey
    {200, 200, 200}, // light-grey
    {255, 255, 255}, // white
    {250, 0, 0},  // red
    {0, 200, 100}, // green
    {0, 100, 200}, // blue
    {250, 250, 0}, // yellow
    {250, 120, 0}, // orange
    
};

void set_colors(color c) {
	gfx_color(colors[c].r,colors[c].g,colors[c].b);
}

