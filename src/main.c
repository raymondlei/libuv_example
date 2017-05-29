#include <stdio.h>
#include <uv.h>

//gcc -pthread ../deps/libuv/bin/*.o ex2.c -lrt -ldl -lm -o ex2

uv_loop_t* loop;

void timer_cb1 (uv_timer_t* timer, int status) {
	printf("1\n", status);
	uv_timer_stop(timer);
	uv_unref(timer);
}

void timer_cb2 (uv_timer_t* timer, int status) {
	printf("2\n", status);
	uv_timer_stop(timer);
	uv_unref(timer);
}

int main () {
	loop = uv_default_loop();

	uv_timer_t timer1;
	uv_timer_init(loop, &timer1);
	uv_timer_start(&timer1, (uv_timer_cb) &timer_cb1, 1000, 1000);

	uv_timer_t timer2;
	uv_timer_init(loop, &timer2);
	uv_timer_start(&timer2, (uv_timer_cb) &timer_cb2, 500, 1000);

	uv_run(loop, UV_RUN_DEFAULT);

	return 0;
}
