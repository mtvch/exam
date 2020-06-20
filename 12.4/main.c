#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count_min(FILE* fp1) {
	if (fp1 == NULL) {
		printf("memory error\n");
		return -1;
	}
	int n;
	int count = 0;
	int min = INT_MAX;
	fread(&n, sizeof(int), 1, fp1);
	while (n != EOF) {
		if (min < n) {
			min = n;
			count = 0;
		}
		if (min == n) count++;
		fread(&n, sizeof(int), 1, fp1);
	}
	rewind(fp1);
	return count;
}

int main() {
	
	return 0;
}
