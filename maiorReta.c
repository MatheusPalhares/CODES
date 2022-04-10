#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Reta
{
    int x1[1000];
    int x2[1000];
};

double getDistancia(struct Reta a, struct Reta b, int k);

int main()
{
    struct Reta a;
    struct Reta b;
    int i, x, j, l;
    int y;
    scanf("%d", &x);
    double res[x];
    double maior;
    for (i = 0; i < x; i++)
    {
        scanf("%d", &a.x1[i]);
        scanf("%d", &a.x2[i]);
        scanf("%d", &b.x1[i]);
        scanf("%d", &b.x2[i]);
        res[i] = getDistancia(a, b, i);
        if (i == x - 1)
        {
            y = 0;
            maior = res[0];
            for (j = 0; j < x; j++)
            {
                if (res[j] > maior)
                {
                    maior = res[j];
                }
            }
            for (l = 0; l < x; l++)
            {
                if (maior == res[l])
                {
                    y = l;
                }
            }
            printf("Reta numero %d, pontos [%d,%d] e [%d,%d], tamanho %.2lf", y, a.x1[y], a.x2[y], b.x1[y], b.x2[y], maior);
        }
    }
    return 0;
}

double getDistancia(struct Reta a, struct Reta b, int k)
{
    double resultado;
    while (1)
    {
        resultado = sqrt(pow(a.x1[k] - b.x1[k], 2) + pow(a.x2[k] - b.x2[k], 2));
        break;
    }
    return resultado;
}