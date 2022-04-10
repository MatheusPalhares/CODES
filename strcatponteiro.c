#include <stdio.h>

int main()
{

    char str1[100];
    char str2[100];
    gets(str1);
    gets(str2);
    char *p1 = str1;
    char *p2 = str2;
    while (*p1) {
        p1++;
    }
    while (*p2) {
        *p1 = *p2;
        p2++;
        p1++;
    }
    *p1 = '\0';
    printf("\n%s", str1);
    return 0;
}