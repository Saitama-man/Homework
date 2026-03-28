#include <stdio.h>
#include "utils.h"


int str_len(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void swap_char(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char *s, int left, int right) {
    if (left == right) {
        puts(s);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap_char(&s[left], &s[i]);
        permute(s, left + 1, right);
        swap_char(&s[left], &s[i]);  // откат
    }
}

int main(void) {

    char s[LEN];

    if (!read_line(s, LEN)) {
        return 0;
    }

    int n = str_len(s);
    if (n == 0) {
        return 0;
    }

    permute(s, 0, n - 1);
    return 0;
}