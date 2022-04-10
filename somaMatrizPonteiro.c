#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int m, int n)
{
    int i;
    float **mat;
    mat = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
        mat[i] = malloc(n * sizeof(float));
    return mat;
}

void recebeMatriz(float **mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i = i + 1)
        for (j = 0; j < n; j = j + 1)
            scanf("%f", &mat[i][j]);
}

float **somaMatriz(float **a, float **b, int m, int n)
{
    int i, j;
    float **c;
    c = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
        c[i] = malloc(n * sizeof(float));

    for (i = 0; i < m; i = i + 1)
        for (j = 0; j < n; j = j + 1)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

void exibeMatriz(float **mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i = i + 1)
    {
        for (j = 0; j < n; j = j + 1)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int m, n;
    float **m1, **m2, **m3;
    scanf("%d", &m);
    scanf("%d", &n);
    m1 = alocaMatriz(m, n);
    m2 = alocaMatriz(m, n);
    m3 = alocaMatriz(m, n);
    recebeMatriz(m1, m, n);
    recebeMatriz(m2, m, n);
    m3 = somaMatriz(m1, m2, m, n);
    exibeMatriz(m3, m, n);
    return 0;
}