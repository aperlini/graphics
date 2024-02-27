#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "geometry.h"
#include "translate.h"

#define WINDOW_W 1200
#define WINDOW_H 800

int main() {

	// initialize screen 
	init(WINDOW_W, WINDOW_H, BLACK, WHITE);

	// set axis
	add_axis();

	// drawing green square on grid
	point_t p = {0, 0};
	int side = 40;
	snap_square_to_grid(&p, side);
	square(side, p.x, p.y, GREEN, BLACK, 6);

	// draw orange square on grid
	p.x = 120;
	p.y = 120;
	snap_square_to_grid(&p, side);
	square(side, p.x, p.y, ORANGE, BLACK, 6);

	// draw red square on grid
	p.x = 480; 
	p.y = 0;
	snap_square_to_grid(&p, side);
	square(side, p.x, p.y, RED, BLACK, 6);

	// arc(100, 120, 120, 180, ORANGE);

	// display things
	enable_display();

    return EXIT_SUCCESS;
}
