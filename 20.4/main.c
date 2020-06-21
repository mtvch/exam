#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>
#include <math.h>
typedef struct List List;

struct List {
	double data;
	List* next;
};

bool is_equal(double a, double b) {
	if (abs(a - b) > 0.00001) {
		return false;
	}
	return true;
}

// т.к. необходимо построить два списка, предположим, что адреса их начал уже даны, потому что нельзя вернуть два аргумента

int cmp(const void* a, const void* b) {
	return *(double*)a - *(double*)b;
}

List* create_node() {
	List* node = malloc(sizeof(List));
	if (node == NULL) {
		printf("memory error\n");
		return NULL;
	}
	node->data = 0;
	node->next = NULL;
	return node;
}

void double_to_lists(List* list1, List* list2, double* arr, int n) {
	qsort(arr, n, sizeof(double), cmp);
	for (int i = 1; i < n - 1; i++) {
		while ((is_equal(arr[i], arr[i - 1]) || is_equal(arr[i], arr[i + 1])) && i < n - 1) {
			i++;
		}
		if (arr[i] < 0) {
			list1->data = arr[i];
			list1->next = create_node();
			list1 = list1->next;
		}
		else {
			list2->data = arr[i];
			list2->next = create_node();
			list2 = list2->next;
		}
	}
}

int main() {
	double arr[3] = { -5, 0, 5 };
	List* list1 = create_node();
	List* list2 = create_node();
	double_to_lists(list1, list2, arr, 3);
	return 0;
}
