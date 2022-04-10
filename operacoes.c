#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b);
int mod(int a, int b);
int pot(int a, int b);

int main()
{
    int x, y, res1, res2, res3;
    scanf("%d", &x);
    scanf("%d", &y);
    char operacao[50];
    res1 = -1;
    res2 = -1;
    res3 = -1;

    while (1)
    {
        scanf("%s", operacao);

        if ((operacao[0] == 'O') && (operacao[1] == 'O') && (operacao[2] == 'O'))
        {
            if (res1 != -1)
            {
                printf("MDC(%d,%d) = %d\n", x, y, res1);
            }
            if (res2 != -1)
            {
                printf("MOD(%d,%d) = %d\n", x, y, res2);
            }
            if (res3 != -1)
            {
                printf("POT(%d,%d) = %d\n", x, y, res3);
            }
            break;
        }
        if ((operacao[0] == 'M') && (operacao[1] == 'D') && (operacao[2] == 'C'))
        {
            res1 = mdc(x, y);
        }
        if ((operacao[0] == 'M') && (operacao[1] == 'O') && (operacao[2] == 'D'))
        {
            res2 = mod(x, y);
        }
        if ((operacao[0] == 'P') && (operacao[1] == 'O') && (operacao[2] == 'T'))
        {
            res3 = pot(x, y);
        }
    }

    return 0;
}

int mdc(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    if (a < b)
    {
        return mdc(b, a);
    }
    return mdc(a - b, b);
}

int mod(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    if (a == b)
    {
        return 0;
    }
    return mod(a - b, b);
}

int pot(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * pot(a, b - 1);
    }
}