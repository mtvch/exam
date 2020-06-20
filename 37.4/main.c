#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reverse_simple(char* s, int start, int len) {
	int i = 0;
	while (i < len / 2) {
		char temp = s[start + i];
		s[start + i] = s[len + start - i - 1];
		s[len + start - i - 1] = temp;
		i++;
	}
}

bool reverse_words(char* s) {
	if (s == NULL) {
		printf("wrong input\n");
		return false;
	}
	int len = strlen(s);
	int i = 0;
	reverse_simple(s, i, len);
	int i_prev = 0;
	i = 0;
	while (i < len) {
		while (s[i] != ' ' && i < len) {
			i++;
		}
		reverse_simple(s, i_prev, i - i_prev);
		i++;
		i_prev = i;
	}
	return true;
}

int main() {
	char s[25] = "I want to pass the exam";
	if (!reverse_words(s)) {
		return 1;
	}
	printf("%s", s);
	return 0;
}
