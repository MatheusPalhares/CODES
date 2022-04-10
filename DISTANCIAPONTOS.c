#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    int x1;
    int x2;
};

double getDistancia(struct Point a, struct Point b);

int main()
{
    struct Point a;
    struct Point b;
    int i, x, j;
    scanf("%d", &x);
    double res[x];
    for (i = 0; i < x; i++)
    {
        scanf("%d", &a.x1);
        scanf("%d", &a.x2);
        scanf("%d", &b.x1);
        scanf("%d", &b.x2);
        res[i] = getDistancia(a, b);
        if (i == x - 1)
        {
            for (j = 0; j < x; j++)
            {
                printf("%.2lf\n", res[j]);
            }
        }
    }
    return 0;
}

double getDistancia(struct Point a, struct Point b)
{
    return sqrt(pow(a.x1 - b.x1, 2) + pow(a.x2 - b.x2, 2));
}