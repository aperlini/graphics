#include "geometry.h"
#include "screen.h"

static void add_grid();

void line(point_t a, point_t b, color c) {
	set_colors(c);
	gfx_line(a.x, a.y, b.x, b.y);
}

void point(point_t p, color c) {
	set_colors(c);
    gfx_point(p.x, p.y);
}

void square(int side, int pos_x, int pos_y, color border, color fill, int thickness) {

	int grid = HAS_GRID;

	// setting corner positions
    point_t points[4] = {
        {pos_x+grid, pos_y+grid}, 								  // top left
        {pos_x+grid + side-(2*grid), pos_y+grid}, 				  // top right
        {pos_x+grid + side-(2*grid), pos_y+grid + side-(2*grid)}, // bottom right
        {pos_x+grid, pos_y+grid + side-(2*grid)}, 				  // bottom left
    };
	
	// drawing fill
	if((int)(fill) != -1) {
		// from left to right
		for(int i=0; i<side-(2*grid); i++) {
			line(points[0], points[3], fill); // vertical left
			points[0].x += 1;
			points[3].x += 1;
			
		}
		// reset x position for sides
		points[0].x = pos_x+grid;
		points[3].x = pos_x+grid;
	}

	// thickness of the line
	for(int i=0; i<thickness; i++) {

		// drawing sides
		line(points[0], points[1], border); // top
		line(points[1], points[2], border); // right
		line(points[2], points[3], border); // bottom
		line(points[3], points[0], border); // left

		// inner position
		points[0].y += 1; // top (down)
		points[1].y += 1; // top (down)
		points[2].y -= 1; // bottom (up)
		points[3].y -= 1; // bottom (up)
		points[3].x += 1; // left (right)
		points[0].x += 1; // left (right)
		points[1].x -= 1; // right (left)
		points[2].x -= 1; // right (left)
	}
}

/**
 * not so nice...
*/
void arc(int radius, int pos_x, int pos_y, int deg, color border) {

    // Degrees to radiant
    float max_angle = DEG2RAD(deg);

    // Draw arc
    point_t p;
	float x=0.0, y = 0.0;		
	for(float angle=0.0; angle < max_angle; angle+=STEP) {
		x = (float)(pos_x) - (float)(radius) * cos(angle);
		y = (float)(pos_y) - (float)(radius) * sin(angle);
		p.x = (int)(x);
		p.y = (int)(y);
		point(p, border);
	}
}

void add_plane() {

	// check if grid must ne set
	if(HAS_GRID)
		add_grid();

	int w = screen_width();
	int h = screen_height();

	point_t plane[4] = {
		{0, (h / 2)}, // mid left
		{w, (h / 2)}, // mid right
		{(w / 2), 0}, // mid top
		{(w / 2), h}  // mid bottom
	};

	line(plane[0], plane[1], BLACK); 	 // vert
	line(plane[2], plane[3], BLACK); // horz
}

static void add_grid() {

	int w = screen_width();
	int h = screen_height();

	point_t p[4] = {
		{0, 0}, // top left
		{w, 0},	// top right
		{0, 0},	// top left
		{0, h}	// bottom left
	};
		
	// horizontal lines
	for(int i=0; i< h / GRID_STEP; i++) {
		p[0].y = p[1].y = i*GRID_STEP;
		line(p[0], p[1], GRID_COLOR);

		// vertical lines
		for(int j=0; j< w / GRID_STEP; j++) {
			p[2].x = p[3].x = j*GRID_STEP;
			line(p[2], p[3], GRID_COLOR);
		}
	}
}

void draw_grid_of_squares() {
	int side = 10, offset = 4;
	point_t p = {0, 0};
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			p.x = 10 + offset*j + side*j;
			p.y = 10 + offset*i + side*i;
			square(side, p.x, p.y, ORANGE, BLACK, 10);
		}	
	}
}

void print_point(point_t p) {
	fprintf(stdout, "x: %d, y: %d\n", p.x, p.y);
}