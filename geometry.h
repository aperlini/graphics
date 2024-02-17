#ifndef __GEOMETRY_H
#define __GEOMETRY_H

#include <stdbool.h>
#include <math.h>
#include <aio.h> 
#include "colors.h"
#include "gfx.h"

#define M_PI 3.14159265358979323846
#define DEG2RAD(d) (d * (M_PI / 180.0))
#define STEP (M_PI / 180.0) // old : 0.0009765625
#define HAS_GRID 1
#define GRID_STEP 40
#define GRID_COLOR LGREY

typedef struct point {
    int x, y;
} point_t; 

void point(point_t p, color c);
void line(point_t a, point_t b, color c);
void square(int side, int pos_x, int pos_y, color border, color fill, int thickness);
void draw_grid_of_squares();
void arc(int radius, int pos_x, int pos_y, int deg, color border);
void add_plane();
void print_point(point_t p);

#endif
