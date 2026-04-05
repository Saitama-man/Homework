#include <stdio.h>
#include "input.h"

int is_empty (char *str) {
    return !*str;
}

int main () {
    char str[LEN];
    int test = 0;

    printf("Введите строку:");

    input(str);
    // char *p = str;

    // while(*p) {
    //     putchar(*p);
    //     p++;
    // }
    
    test = is_empty(str);

    if(test) printf("строка пустая");
    else printf("строка не пустая");

    return 0;
}