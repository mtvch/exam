#include <stdlib.h>
#include <stdio.h>

typedef struct List List;

struct List {
  int data;
  List* next;
};

List* reverse(List* list1) {
    if (list1 == NULL) {
        printf("wrong input\n");
        return NULL;
    }
    List* list2 = list1->next;
    list1->next = NULL;
    if (list2 == NULL) {
        return list1;
    }
    List* list3 = list2->next;
    list2->next = list1;
    while (list3 != NULL) {
        list1 = list3->next;
        list3->next = list2;
        list2 = list3;
        list3 = list1;
    }
    return list2;
}

void free_list(List* list1) {
    while (list1 != NULL) {
        List* list2 = list1->next;
        free(list1);
        list1 = list2;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if (N < 1) {
        return 0;
    }
    printf("\n");
    List* list1 = malloc(sizeof(List));
    scanf("%d", &list1->data);
    List* first = list1;
    for (int i = 0; i < N - 1; i++) {
        List* list2 = malloc(sizeof(List));
        scanf("%d", &list2->data);
        list1->next = list2;
        list1 = list2;
    }
    first = reverse(first);
    List* print_list = first;
    while (print_list != NULL) {
        printf("%d ", print_list->data);
        print_list = print_list->next;
    }
    free_list(first);
    return 0;
}
