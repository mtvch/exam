#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool cypher(bool is_cypher, int shift, FILE* fp1, FILE* fp2) {
	if (fp1 == NULL || fp2 == NULL) {
		printf("Can't use unopened file\n");
		return false;
	}
	shift %= 26;
	int c = fgetc(fp1);
	char c2 = 0;
	if (is_cypher) {
		while (c != EOF) {
			if (islower(c)) {
				c2 = (c - 'a' + shift) % ('z' - 'a' + 1) + 'a';
			}
			else if (!ispunct(c) && c != ' ') {
				printf("Wrong input\n");
				return false;
			}
			else c2 = c;
			fputc(c2, fp2);
			c = fgetc(fp1);
		}
	}
	else {
		while (c != EOF) {
			if (islower(c)) {
				if (c - 'a' - shift >= 0) {
					c2 = (c - 'a' - shift) + 'a';
				}
				else {
					c2 = ('z' - 'a' + shift - 1 - c) + 'a';
				}
			}
			else if (!ispunct(c) && c != ' ') {
				printf("Wrong input\n");
				return false;
			}
			else c2 = c;
			fputc(c2, fp2);
			c = fgetc(fp1);
		}
	}
	return true;
}

int main() {
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("in.txt", "rb");
	fp2 = fopen("out.txt", "wb");
	if (!cypher(1, 27, fp1, fp2)) {
		fclose(fp1);
		fclose(fp2);
		return 1;
	}
	if (!cypher(0, 27, fp2, fp1)) {
		fclose(fp1);
		fclose(fp2);
		return 1;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}