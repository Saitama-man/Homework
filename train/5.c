#include <stdio.h>
#define MAX 1000

void print (char *str) {
    while (*str) {
        printf("%c",*str);
        str++;
    }
}

int my_strlen (char *p) {
    int i = 0;
    while(p[i]) {
        i++;
    }
    return i;
}

void input (char *str) {
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n' && i < MAX-1) {
        str[i++] = (char)c;

    }
    str[i] = '\0';
}

void my_strcpy(char *str, char *dest, int len) {
    int i = 0;
    while(str[i] && i< len-1) {
        dest[i] = str[i]; 
        i++;

    }
    dest[i] = '\0';
}


int main () {

    char str[MAX];
    input(str);
    int len = 123;
    char biba[len];
    my_strcpy(str,biba, len);
    print(biba);

    putchar('\n');

    return 0; 
}