#include <stdbool.h>
#include <pthread.h>
#include "screen.h"

void animate_draw() {
	point_t p1;
	point_t p2;
	p1.x = 10;
	p1.y = 10;
	p2.x = 100;
	p2.y = 10;
	int end = 0;

	while(true) {

		gfx_clear();
		line(p1, p2, WHITE);
		
		if(p2.x >= screen_width()) {
			end = p1.x > 10;
		} 
		
		if(p1.x <= 10){
			end = 0;
		}

		if(end) {
			p1.x--;
			p2.x--;
		} else {
			p1.x++;
			p2.x++;
		}

		gfx_flush();  

		usleep(2500);
	}
}

void *t_func_anim() {
	animate_draw();
	return NULL;
}

void threaded_anim() {
	 // animation in new thread
	 pthread_t td;
	 int ret = pthread_create(&td, NULL, &t_func_anim, NULL);
	 if(ret != 0) {
	 	fprintf(stderr, "pthread error\n");
	 	exit(EXIT_FAILURE);
	 }

	 // blocking
	 enable_display();

	 // thread cancellation
	ret = pthread_cancel(td);

	 if(ret != 0) {
	 	printf("pthread_cancel: %d\n", ret);
	 }
}

