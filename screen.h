#ifndef __SCREEN__H
#define __SCREEN__H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "geometry.h"

typedef struct {
    int w;
    int h;
    color fg;
    color bg;
} screen;

void init(int w, int h, color fg, color bg) ;
void enable_display();
int screen_width();
int screen_height();
color foreground();
color background();
void clean_up();

#endif
