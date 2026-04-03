#include <stdio.h>
#define MAX 1000

void print(char *str) {
    int i = 0;
    while(*str) {
    printf("%c", *str);
    str++;
    }

}

int main() {
    char str[MAX];

    printf("Введите строку (макс 1000 символов)\n"); 

    int c, i = 0; 

    while((c = getchar()) != EOF && c != '\n' && i < MAX - 1) {
        str[i++] = c;
    }
    str[i] = '\0';

    printf("Ваша строка: \n");
    print(str);
    printf("\n");

    return 0;

}