#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StrNode {
    char* str;
    struct StrNode* next;
} StrNode;

StrNode* push_back(StrNode* head, const char* text) {
    StrNode* new_node = (StrNode*)malloc(sizeof(StrNode));

    new_node->str = (char*)malloc(strlen(text) + 1);
    strcpy(new_node->str, text);

    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    StrNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
    return head;
}

char* merge_strings(StrNode* head) {
    if (head == NULL) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int total_len = 0;
    int count = 0;
    StrNode* cur = head;

    while (cur != NULL) {
        total_len += strlen(cur->str);
        count++;
        cur = cur->next;
    }

    total_len += (count - 1) + 1;

    char* result = (char*)malloc(total_len);
    result[0] = '\0';

    cur = head;
    while (cur != NULL) {
        strcat(result, cur->str);

        if (cur->next != NULL) {
            strcat(result, " ");
        }

        cur = cur->next;
    }

    return result;
}

void print_list(StrNode* head) {
    StrNode* cur = head;

    while (cur != NULL) {
        printf("%s", cur->str);
        if (cur->next != NULL) {
            printf(" -> ");
        }
        cur = cur->next;
    }

    printf("\n");
}

void free_list(StrNode* head) {
    StrNode* cur = head;

    while (cur != NULL) {
        StrNode* temp = cur;
        cur = cur->next;
        free(temp->str);
        free(temp);
    }
}

int main() {
    StrNode* list = NULL;
    char buffer[100];
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        
        buffer[strcspn(buffer, "\n")] = '\0';

        list = push_back(list, buffer);
    }

    printf("\nList of strings: ");
    print_list(list);

    char* merged = merge_strings(list);
    printf("Merged string: %s\n", merged);

    free(merged);
    free_list(list);

    return 0;
}
