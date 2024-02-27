#include "geometry.h"

static void add_grid();
static void fill_square(point_t points[], int side, int pos_x, color fill);
static void border_square(point_t *points, int thickness, color border);

// line abstraction 
void line(point_t a, point_t b, color c) {
	set_colors(c);
	gfx_line(a.x, a.y, b.x, b.y);
}

// point abstraction 
void point(point_t p, color c) {
	set_colors(c);
    gfx_point(p.x, p.y);
}

// square abstraction
void square(int side, int pos_x, int pos_y, color border, color fill, int thickness) {

	int grid = HAS_GRID;

	// set points position + grid offset 
	// so the shape doesn't overlap grid
	point_t points[4] = {
        {pos_x+grid, pos_y+grid}, // top left
        {pos_x+grid + side-(2*grid), pos_y+grid}, //top right
        {pos_x+grid + side-(2*grid), pos_y+grid + side-(2*grid)}, // bottom right
        {pos_x+grid, pos_y+grid + side-(2*grid)}, // bottom left
    };

	assert(pos_x >= 0); // left limit
	assert(pos_y >= 0); // top limit
	assert(pos_x+side <= screen_width()); // right limit
	assert(pos_y+side <= screen_height()); // bottom limit
	
	// draw shape
	fill_square(points, side, pos_x, fill);

	// draw borders
	border_square(points, thickness, border);
}

/**
 * not so nice...
*/
void arc(int radius, int pos_x, int pos_y, int deg, color border) {

    // Degrees to radiant
    float max_angle = DEG2RAD(deg);

    // Draw arc
    point_t p1, p2;
	float x1=0.0, y1 = 0.0;	
	float x2=0.0, y2 = 0.0;		
	int offset = 10;
	for(float angle=0.0; angle < max_angle; angle+=STEP) {
		x1 = (float)(pos_x) - (float)(radius) * cos(angle);
		y1 = (float)(pos_y) - (float)(radius) * sin(angle);
		x2 = (float)(pos_x+offset) - (float)(radius) * cos(angle);
		y2 = (float)(pos_y+offset) - (float)(radius) * sin(angle);
		p1.x = (int)(x1);
		p1.y = (int)(y1);
		p2.x = (int)(x2);
		p2.y = (int)(y2);
		line(p1, p2, border);
	}
}

// display x, y axis in euclydian plane
void add_axis() {

	// check if grid must ne set
	if(HAS_GRID)
		add_grid();

	int w = screen_width();
	int h = screen_height();

	point_t axis[4] = {
		{0, (h / 2)}, // mid left
		{w, (h / 2)}, // mid right
		{(w / 2), 0}, // mid top
		{(w / 2), h}  // mid bottom
	};

	line(axis[0], axis[1], BLACK); // vert
	line(axis[2], axis[3], BLACK); // horz
}

// draw grid
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

// draw fill of shape
static void fill_square(point_t points[], int side, int pos_x, color fill) {

	// from left to right (minus grid offset)
	for(int i=0; i<side-(2*HAS_GRID); i++) {
		line(points[0], points[3], fill); // vertical left
		points[0].x += 1;
		points[3].x += 1;
		
	}
	// reset x position to default
	points[0].x = pos_x+HAS_GRID;
	points[3].x = pos_x+HAS_GRID;
}

// draw border of shape
static void border_square(point_t *points, int thickness, color border) {

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

// Drawing 10x10 orange square grid
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