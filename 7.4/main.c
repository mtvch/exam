#define _CRT_SECURE_NO_WARNIGNS
#include <stdlib.h>
#include <stdio.h>
typedef struct Time Time;

struct Time {
	char h;
	char min;
	char sec;
};

int convert_sec(Time* time) {
	return (int)time->h * 3600 + (int)time->min * 60 + time->sec;
}

int add_time(Time* time, int add) {
	int sec = convert_sec(time);
	sec += add;
	time->h = (sec / 3600) % 24;
	time->min = (sec / 60 ) % 60;
	time->sec = sec % 60;
}

int main() {
	Time* time = malloc(sizeof(Time));
	if (time == NULL) {
		printf("memory error\n");
		return 1;
	}
	time->h = 15;
	time->min = 30;
	time->sec = 23;
	add_time(time, 3600);
	return 0;
}
