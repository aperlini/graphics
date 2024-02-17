#include "screen.h"

// Global screen infos
static screen *s = NULL;

void init(int w, int h, color fg, color bg) {

	// Persists infos
	s = (screen*)(malloc(sizeof(screen)));

	if(s == NULL) {
		fprintf(stderr, "Issue w/ malloc!\n");
		exit(-1);
	}

	s->w = w;
	s->h = h;
	s->bg = bg;
	s->fg = fg;

	// Open a new window for drawing.
	gfx_open(s->w, s->h,"Default cross", s->fg, s->bg);
}

int screen_width() {
	return s->w;
}

int screen_height() {
	return s->h;
}

color foreground() {
	return s->fg;
}

color background() {
	return s->bg;
}

void clean_up() {
	free(s);
	s = NULL;
}

void enable_display() {

	char key_pressed;

	while(1) {

		key_pressed = gfx_wait();

		// Quit when q is pressed
		if(key_pressed =='q') break;
	}
}


