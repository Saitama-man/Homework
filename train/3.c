#include <stdio.h>
#define MAX 1000

int get_char_num(char * str, char c) {
    int num = 0;

    while(*str) {
        if(*str == c) num++;
        str++;
    }
    return num;
    
}

int main() {
    char str[MAX];
    int c, i = 0;

    printf("Введите строку (макс. символов 1000)\n");

    while((c = getchar()) != EOF && c != '\n' && i < MAX-1) {
        str[i++] = c;
    }
    str[i] = '\0';
    printf("Введите символ, который нужно посчитать\n");

    char ch = getchar();

    printf("Кол-во %c: %d", ch ,get_char_num(str, ch));
    putchar('\n');
    
    return 0;

}