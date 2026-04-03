#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int strlen_1 (char *str) { 
    int i = 0;
    while(*(str+i) != '\0') {
        i++;
    }
    return i;
}

int main() {
    char str[MAX];
    int c; 
    int i = 0;

    printf("Введите строку размером не более 1000 символов\n");

    while((c=getchar()) != EOF && c != '\n' && i< MAX-1) {
        str[i++] = c;
    }
    str[i] = '\0';

    printf("%d", strlen_1(str));
} 