#include <stdio.h>

int main()
{

    char str1[100];
    char str2[100];
    char str3[100];
    int i = 0, j = 0;
    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);
    while (str1[i] != '\0') {
        str3[j] = str1[i];
        i++;
        j++;
    }
    i = 0;
    while (str2[i] != '\0') {
        str3[j] = str2[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    printf("\n%s", str3);
    return 0;
}