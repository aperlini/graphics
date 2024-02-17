#include "translate.h"
#include "screen.h"

// y values must be reversed
void snap_square_to_grid(point_t *p, int y_offset) {
    p->x += screen_width() / 2;
    p->y = -p->y + screen_height() / 2 - y_offset;
}
