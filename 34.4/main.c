#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
typedef struct Node Node;
typedef struct AdvancedNode AdvancedNode;

struct AdvancedNode {
	int lvl;
	int data;
};

struct Node {
	Node* right;
	Node* left;
	int data;
};

int cmp(const void* a, const void* b) {
	return (((AdvancedNode*)a)->lvl - ((AdvancedNode*)b)->lvl) + 1;
}

int evaluate_depth(int depth, Node* node, AdvancedNode* advanced_node, int* i) {
	if (node != NULL) {
		advanced_node[*i].data = node->data;
		advanced_node[*i].lvl = depth;
		(*i)++;
		evaluate_depth(depth + 1, node->left, advanced_node, i);
		evaluate_depth(depth + 1, node->right, advanced_node, i);
	}
	return *i;
}

void print_tree(Node* node) {
	AdvancedNode advanced_node[MAX_TREE_SIZE];
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		advanced_node[i].lvl = 0;
		advanced_node[i].data = 0;
	}
	int depth = 0;
	int i = 0;
	i = evaluate_depth(depth, node, advanced_node, &i);
	qsort(advanced_node, i, sizeof(advanced_node[0]), cmp);
	int lvl = 0;
	for (int j = 0; j < i; j++) {
		if (advanced_node[j].lvl > lvl) {
			printf("\n");
			lvl++;
		}
		printf("%d ", advanced_node[j].data);
	}
}
void free_tree(Node* node) {
	if (node != NULL) {
		free_tree(node->right);
		free_tree(node->left);
		free(node);
	}
}

Node* create_test_tree() {
	Node* root = malloc(sizeof(Node));
	if (root == NULL) {
		return NULL;
	}
	root->data = 50;
	Node* node1 = malloc(sizeof(Node));
	if (node1 == NULL) {
		return NULL;
	}
	node1->data = 20;
	root->left = node1;
	Node* node2 = malloc(sizeof(Node));
	if (node2 == NULL) {
		return NULL;
	}
	node2->data = 30;
	root->right = node2;
	node2->left = NULL;
	Node* node4 = malloc(sizeof(Node));
	if (node4 == NULL) {
		return NULL;
	}
	node4->data = 70;
	node1->left = node4;
	Node* node5 = malloc(sizeof(Node));
	if (node5 == NULL) {
		return NULL;
	}
	node5->data = 900;
	node1->right = node5;
	node4->right = node4->left = NULL;
	node5->right = node5->left = NULL;
	Node* node6 = malloc(sizeof(Node));
	if (node6 == NULL) {
		return NULL;
	}
	node6->data = 1000;
	node2->right = node6;
	node6->right = node6->left = NULL;
	return root;
}

int main() {
	Node* root = create_test_tree();
	print_tree(root);
	free_tree(root);
	return 0;
}
