#include <stdio.h>
#include "input.h"

void input(char *str) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && i<LEN-1) {
        str[i++] = (char)c;
    }
    str[i] = '\0';

}