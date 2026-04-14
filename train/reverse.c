#include <stdio.h>
#define LEN 1000

void input(char *str) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && i<LEN-1) {
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

void reverse(char *str) {
    char *end = str;
    while(*end) {
        end++;
    } end--;
    while(str<end){
        char temp;
        temp = *str;
        *str = *end;
        *end = temp;
        end--;
        str++;
    }
}

int main () {

    char arr[LEN];
    input(arr);
    reverse(arr);
    print(arr);
    

    return 0;
}