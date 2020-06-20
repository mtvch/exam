#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sim(int* a, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i]) return false;
	}
	return true;
}

char* sim(int a, int b, int A[a][b]) {
	char* B = malloc(a * sizeof(char));
	if (B == NULL) {
		printf("memory error\n");
		return 0;
	}
	for (int i = 0; i < a; i++) {
		if (is_sim(A[i], b - 1)) {
			B[i] = 1;
		}
		else B[i] = 0;
	}
	return B;
}

int main() {
	int A[5][6] = { 0 };
	char* B = sim(5, 6, A);
	for (int i = 0; i < 5; i++) {
		printf("%d ", B[i]);
	}
	return 0;
}
