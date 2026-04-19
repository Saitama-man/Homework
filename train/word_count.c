#include <stdio.h>

char is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void input(char *str, int len) {
    int c, i = 0;
    while((c=getchar()) != EOF && c != '\n' && i<len-1) {
        str[i++] = (char)c;
    }
    str[i] = '\0';
}

void print(char *p) {
    while(*p) {
        printf("%c", *p);
        p++;
    }
    putchar('\n');
}

int word_count(char *str) {
    int count = 0;
    if(!is_space(*str) && *str) count++;
    while(*str) {
        if(is_space(*str) && !is_space(*(str+1)) && *(str+1) != '\0') {
            count++;
        }
        str++;
    }
    return count;
}


int main() {
    char str[100];
    input(str,sizeof(str));
    int b = word_count(str);
    printf("%d\n", b);

    return 0;
}