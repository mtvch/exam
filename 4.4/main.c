#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define AB 26

bool is_consonant(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'y') {
		return false;
	}
	return true;
}

void print_consonants(char* s) {
	int letters[AB];
	for (int i = 0; i != '.'; i++) {
		if (islower(s[i])) letters[s[i] - 'a']++;
	}
	for (int i = 0; i < AB; i++) {
		if (is_consonant('a' + i) && letters[i] == 1) {
			printf("%d ", 'a' + i);
		}
	}
}

int main() {

	return 0;
}
