#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_simple(int n) {
	int p = sqrt(n);
	for (int i = 2; i <= p; i++) {
		if (n % p == 0) return false;
	}
	return true;
}

void print_mersenn(unsigned long n) {
	unsigned long k = 4;
	int power = 2;
	while (k - 1 < n) {
		if (is_simple(power)) printf("%u ", k - 1);
		k *= 2;
		power++;
	}
}

int main() {
	print_mersenn(1000000);
	return 0;
}
