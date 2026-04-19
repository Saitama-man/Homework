#include <stdio.h>
#include <stdlib.h>

char *input()
{
    int size = 10 * sizeof(char);
    char *str = malloc(size);
    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i == size - 1)
        {
            char *temp = str;
            temp = realloc(temp, size * 2);
            if (temp != NULL)
            {
                size *= 2;
                str = temp;
            }
        }
        *(str + i) = (char)c;
        i++;
    }
    str[i] = '\0';
    return str;
}


int find_str(const char *str, const char *sample)
{
    if (!*sample)
        return -0;
    int j = 0;
    for(int i = 0; str[i]; i ++) {

        while(str[i+j] && sample[j] && str[i+j] == sample[j]) {
            j++;
        }
        if(!sample[j]) return i;
    }
    return -1;
}


// int find_str(const char *str, const char *sample)
// {
//     if (!*str || !*sample)
//         return -1;

//     int index = -1;
//     int j = 0, k = 0;
//     for (int i = 0; str[i]; i++)
//     {
//         printf("_k:%d _i:%d _j:%d \n", k, i, j);

//         // if(sample[j] && ((i - k)>1)) j = 0;

//         if (str[i] == sample[j] && sample[j])
//         {
//             if (j == 0)
//             {
//                 index = i;
//             }
//             j++;
//             // k = i;
//         }
//         else if (sample[j])
//         {
//             j = 0;
//             i--;
//         }
//         printf("k:%d i:%d j:%d index: %d \n", k, i, j, index);
//     }
//     if (sample[j])
//     {
//         index = -1;
//     }
//     return index;
// }

int main()
{

    char *str = input();
    char *smaple = input();

    putchar('\n');
    int index = find_str(str, smaple);

    if (index == -1)
    {
        printf("Не найдено ");
    }
    else
        printf("%d", index);

    free(str);
    free(smaple);

    return 0;
}