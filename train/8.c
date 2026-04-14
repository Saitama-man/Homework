#include <stdio.h>
#define LEN 1000

void input(char *str) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && i<LEN-1) {
        str[i++] = (char)c;
    }
    str[i] = '\0';

}

void print (char *str) {
    while (*str) {
        printf("%c",*str);
        str++;
    }
}

void delete_char(char *p, const char a) {
    while(*p) {
        if(*p==a){
            char *p1 = p;
            while(*p1) {
                *p1 = *(p1+1);
                p1++;
            } continue;
        } p++;
    }
}

void delete_char2(char *str, char a) {
    char *read = str;
    char *write = str;
    while(*read) {
        if(*read != a) {
            *write = *read;
            write++;
        } read++;
    } *write = '\0';
}





int main () {
    char s[] = "e  rw w e ";
    delete_char(s,' ');
    print(s);

    return 0;
}