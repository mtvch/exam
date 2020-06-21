#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
double random_to_number(char c, unsigned source_ns, int power) {
	if (c >= 'A' && c <= 'Z' && c < 'A' + (int)source_ns - 10) return ((double)10 + (double)c - (double)'A') * pow(source_ns, power);
	if (c >= 'a' && c <= 'z' && c < 'a' + (int)source_ns - 10) return ((double)10 + (double)c - (double)'a') * pow(source_ns, power);
	else if (c >= '0' && c <= '9' && c < '0' + (int)source_ns) return ((double)c - (double)'0') * (double)pow(source_ns, power);
	else return -1;
}
char number_to_random(int number) {
	if (number >= 0 && number <= 9) return '0' + number;
	else if (number >= 10 && number <= 15) return 'A' + number - 10;
	else return '-';
}
long double to_decimal(char* input, unsigned source_ns) {
	long double final_number = 0;
	int numbers_before_dot = 0;
	int numbers_after_dot = 0;
	int power = 0;
	int counter = 0;
	bool is_dot = false;
	if (*input == '.') return -1;
	while (*input != '\0') {
		if (*input != '.' && !is_dot) numbers_before_dot++;
		else if (*input != '.' && is_dot) numbers_after_dot++;
		else if (*input == '.') is_dot = true;
		else return -1;
		input++;
	}
	if (is_dot && numbers_after_dot == 0) return -1;
	counter = numbers_after_dot;
	while (counter > 0) {
		input--;
		power = -1 * counter;
		if (random_to_number(*input, source_ns, power) != -1) final_number += random_to_number(*input, source_ns, power);
		else return -1;
		counter--;
	}
	while (counter < numbers_before_dot) {
		input--;
		if (*input == '.') input--;
		power = counter;
		if (random_to_number(*input, source_ns, power) != -1) final_number += random_to_number(*input, source_ns, power);
		else return -1;
		counter++;
	}
	return final_number;
}
char* from_decimal(double input, unsigned target_ns) {
	int result_before_dot[50] = { 0 };
	long long inumber = trunc(input);
	long double dnumber = input - inumber;
	int i = 0;
	if ((int)input == 0) i = 1;
	while (inumber > 0) {
		result_before_dot[i] = inumber % target_ns;
		inumber /= target_ns;
		i++;
	}
	int result_after_dot[12] = { 0 };
	int j = 0;
	while (j < 12 && (double)dnumber > 0.00000001) {
		dnumber *= target_ns;
		inumber = trunc(dnumber);
		dnumber = dnumber - inumber;
		result_after_dot[j] = inumber;
		j++;
	}
	char* result = (char*)malloc((i + j + 2) * sizeof(char));
	if (j == 0 && i > 0) result[i] = '\0';
	else result[i + j + 1] = '\0';
	int i1 = i;
	int j1 = 0;
	for (int k = 0; k < i; k++) {
		i1--;
		if (number_to_random(result_before_dot[i1]) != '-') result[k] = number_to_random(result_before_dot[i1]);
		else {
			free(result);
			return NULL;
		}
	}
	if (j != 0) result[i] = '.';
	for (int k = i + 1; k < i + j + 1; k++) {
		if (number_to_random(result_before_dot[i1]) != '-') result[k] = number_to_random(result_after_dot[j1]);
		else {
			free(result);
			return NULL;
		}
		j1++;
	}
	return result;
}
int main() {
	bool is_dot = false;
	int base_of_number_system_1, base_of_number_system_2;
	if (scanf("%d %d\n", &base_of_number_system_1, &base_of_number_system_2) != 2 || base_of_number_system_1 < 2 || base_of_number_system_1 > 16 || base_of_number_system_2 < 2 || base_of_number_system_2 > 16) {
		printf("bad input\n");
		return 0;
	}
	char number[14];
	int i = 0;
	if (scanf("%13s", number) != 1) {
		printf("bad input");
		return 0;
	}
	while (number[i] != '\0') {
		if (is_dot) {
			if (number[i] == '.') {
				printf("bad input\n");
				return 0;
			}
		}
		if (number[i] == '.') is_dot = true;
		if (random_to_number(number[i], base_of_number_system_1, 1) == -1 && number[i] != '.' && number[i] != '\0') {
			printf("bad input\n");
			return 0;
		}
		i++;
	}
	if (to_decimal(number, base_of_number_system_1) == -1) {
		printf("bad input\n");
		return 0;
	}
	char* result = from_decimal(to_decimal(number, base_of_number_system_1), base_of_number_system_2);
	if (result == NULL) {
		printf("bad input\n");
		return 0;
	}
	printf("%s", result);
	free(result);
	return 0;
}
