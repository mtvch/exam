#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define MAX_WORDS 100

void print_disrtib(FILE* fp1) {
	int c = fgetc(fp1);
	int letters = 0;
	int arr[MAX_WORDS] = { 0 };
	while (c != EOF) {
		while (islower(c)) {
			letters++;
			c = fgetc(fp1);
		}
		arr[letters]++;
		while (!islower(c)) c = fgetc(fp1);
	}
	for (int i = 0; i < MAX_WORDS; i++) {
		if (arr[i] != 0) {
			printf("%d: %d\n", i, arr[i]);
		}
	}
	rewind(fp1);
}

int main() {

	return 0;
}
