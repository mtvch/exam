#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SURNAME_SIZE 15
#define MAX_STUDENTS 200
#define MAX_GROUP_SIZE 10
#define MAX_COURSES 9
#define MAX_COURSE_NAME 20

typedef struct Course Course;

struct Course {
	char name[MAX_COURSE_NAME + 1];
	char student[MAX_STUDENTS + 1][MAX_SURNAME_SIZE + 1];
	int number;
};

bool survey_sort(FILE* fp1, FILE* fp2) {
	if (fp1 == NULL || fp2 == NULL) {
		printf("Can't open file\n");
		return false;
	}
	Course course[MAX_COURSES + 1];
	int n_courses = 0;
	for (int k = 0; k < MAX_COURSES; k++) {
		course[k].number = 0;
	}
	fseek(fp1, 0, SEEK_END);
	int end = ftell(fp1);
	rewind(fp1);
	while (ftell(fp1) < end - 2) {
		char student[MAX_SURNAME_SIZE + 1];
		int c = fgetc(fp1);
		int i = 0;
		while (c != ' ' && i < MAX_SURNAME_SIZE && c != EOF) {
			student[i] = c;
			c = fgetc(fp1);
			i++;
		}
		if (i == MAX_SURNAME_SIZE || c == EOF) {
			printf("wrong input\n");
			return false;
		}
		student[i] = '\0';
		c = fgetc(fp1);
		while (c != ' ' && c != EOF) {
			c = fgetc(fp1);
		}
		if (c == EOF) {
			printf("wrong input\n");
			return false;
		}
		c = fgetc(fp1);
		i = 0;
		while (c != '\n') {
			char name[MAX_COURSE_NAME + 1];
			while (c != ' ' && i < MAX_COURSE_NAME && c != EOF) {
				name[i] = c;
				c = fgetc(fp1);
				i++;
			}
			name[i] = '\0';
			bool is_listed = false;
			for (int j = 0; j < n_courses; j++) {
				if (!strcmp(name, course[j].name)) {
					memcpy(course[j].student[course[j].number], student, strlen(student));
					course[j].number++;
					is_listed = true;
				}
			}
			if (!is_listed) {
				memcpy(course[n_courses].name, name, strlen(name));
			}
		}
	}
	for (int i = 0; i < n_courses; i++) {
		fwrite(course[i].name, 1, strlen(course[i].name), fp2);
		fputs(": ", fp2);
		for (int j = 0; j < course[i].number - 1; j++) {
			fwrite(course[i].student[j], 1, strlen(course[i].student[j]), fp2);
			fputs(", ", fp2);
		}
		fwrite(course[i].student[course[i].number], 1, strlen(course[i].student[j]), fp2);
		fputs("\n", fp2);
	}
}

int main() {
	// примерный код, не тестировал
	return 0;
}
