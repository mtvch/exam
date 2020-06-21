#include <stdio.h>
#include <stdlib.h>

double** mtp(double** A, double** B, int a, int b) { // для упрощение матрицы квадратные
	double** C = malloc(sizeof(double*) * (a + b));
	if (C == NULL) {
		printf("memory error\n");
		return NULL;
	}
	for (int i = 0; i < a + b; i++) {
		C[i] = malloc(sizeof(double) * (a + b));
		if (C[i] == NULL) {
			printf("memory error\n");
			return NULL;
		}
	}
	for (int i = 0; i < a + b; i++) {
		for (int j = 0; j < a + b; j++) {
			for (int k = 0; k < a + b; k++) {
				for (int m = 0; m < a + b; m++) {
					C[i + k][j + m] += A[i][j] * B[k][m];
				}
			}
		}
	}
	return C;
}

int main() {

	return 0;
}
