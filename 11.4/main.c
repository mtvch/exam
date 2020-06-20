#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;

struct Node {
	int data;
	Node* right;
	Node* left;
};

void search(Node* node, int* max) {
	if (node != NULL) {
		search(node->left, max);
		if (node->data > max) {
			*max = node->data;
		}
		search(node->right, max);
	}
}

int find_max_node(Node* node) {
	int max = -INT_MAX;
	search(node, &max);
	return max;
}

int main() {

	return 0;
}
