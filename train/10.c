#include <stdio.h>

void print(char *p) {
    while(*p) {
        printf("%c", *p);
        p++;
    }
    putchar('\n');
}

void delete_char(char *str, const char c) {
    char *read = str;
    char *write = str;
    while(*read) {
        if(*read != c) {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';
}

// void format(char *str) {
//     for(int i = 0; str[i]; i++) {
//         if(str[i]<91&&str[i]>64) str[i]+=32;
//         if(str[i]<48 || str[i]=='?' || str[i]==':' || str[i] > 122){
//             delete_char(str, str[i]);
//             format(str);
//         }
//     }
// }

// int is_polindrome (char *str) {
//     format(str);
//     delete_char(str, ' ');
//     delete_char(str, '\t');
//     delete_char(str, '\n');
//     if(!*str) return 0;
//     char *end = str;
//     while(*end) { 
//         end++;
//     } end--;
//     while(str<end) {
//         if(*str != *end) return 0;
//         str++;
//         end--;
//     }
//     return 1;
// }

int is_palindrome(char *str) {
    char *left = str;
    char *right = str;
    while (*right) right++;
    right--;

    while (left < right) {

        while (left < right && !((*left >= 'a' && *left <= 'z') ||
                                (*left >= 'A' && *left <= 'Z') ||
                                (*left >= '0' && *left <= '9'))) {
            left++;
        }

        while (left < right && !((*right >= 'a' && *right <= 'z') ||
                                 (*right >= 'A' && *right <= 'Z') ||
                                 (*right >= '0' && *right <= '9'))) {
            right--;
        }
        char l = *left;
        char r = *right;
        if (l >= 'A' && l <= 'Z') l += 32;
        if (r >= 'A' && r <= 'Z') r += 32;

        if (l != r) return 0;

        left++;
        right--;
    }

    return 1;
}


int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    printf("%s", is_palindrome(str)?"true\n":"false\n");
    print(str);
    return 0;
}