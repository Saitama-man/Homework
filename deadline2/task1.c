#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push_back(Node* head, int value);

void print_list(Node* head);

int contains(Node* head, int value);

Node* find_common(Node* list1, Node* list2);

void free_list(Node* head);



int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* common = NULL;

    int n1, n2;
    int value;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);

    printf("Enter elements of first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        list1 = push_back(list1, value);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);

    printf("Enter elements of second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        list2 = push_back(list2, value);
    }

    printf("\nFirst list: ");
    print_list(list1);

    printf("Second list: ");
    print_list(list2);

    common = find_common(list1, list2);

    printf("Common elements: ");
    if (common == NULL) {
        printf("none");
    } else {
        print_list(common);
    }

    free_list(list1);
    free_list(list2);
    free_list(common);

    return 0;
}
Node* push_back(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }  

    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
    return head;
}

void print_list(Node* head) {
    Node* cur = head;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
}

int contains(Node* head, int value) {
    Node* cur = head;

    while (cur != NULL) {
        if (cur->data == value) {
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

Node* find_common(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* cur = list1;

    while (cur != NULL) {
        if (contains(list2, cur->data) && !contains(result, cur->data)) {
            result = push_back(result, cur->data);
        }
        cur = cur->next;
    }

    return result;
}

void free_list(Node* head) {
    Node* cur = head;

    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
}
