#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct List List;

struct List {
	int data;
	List* next;
};

// для упрощения упорядоченный по возрастанию

List* unite(List* list1, List* list2) {
	List* root;
	if (list1 == NULL) {
		return list2;
	}
	if (list2 == NULL) {
		return list1;
	}
	if (list1->data < list2->data) {
		root = list1;
	}
	else {
		root = list2;
	}
	List* list3 = root;
	while (list1 != NULL && list2 != NULL) {
		if (list1 == NULL) {
			list3->next = list2;
			list2 = list2->next;
		}
		else if (list2 == NULL) {
			list3->next = list1;
			list1 = list1->next;
		}
		else if (list1->data < list2->data) {
			list3->next = list1;
			list1 = list1->next;
		}
		else {
			list3->next = list2;
			list2 = list2->next;
		}
		list3 = list3->next;
	}
	return root;
}

int main() {

	return 0;
}
