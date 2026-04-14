#include <stdio.h>
#define MAX 1000

int my_strcmp (const char *str, const char *str1) {
    while (*str && *str == *str1 ) { 
        str++;
        str1++;
    }
    return *str - *str1;
}

void input (char *str) {
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n' && i < MAX-1) {
        str[i++] = (char)c;

    }
    str[i] = '\0';
}

int main () {
    char str[MAX] = "апельсин";
    char str1[MAX];

    printf("введите загаданное слово\n");
    input(str1);
    int a ;
    do {
        if((a = my_strcmp(str,str1)) == 0) printf("угадал\n");
        else {
            printf("старайся лучше\n");
            input(str1);
        }
    } while(a!=0);
    return 0;
}



