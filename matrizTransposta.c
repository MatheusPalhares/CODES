#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int linhas, int colunas);
float **transpoeMatriz(float **m, int tamLinha, int tamColuna);
void exibeTransposta(float **m, int tamLinha, int tamColuna);
void recebeMatriz(float **m, int tamLinha, int tamColuna);

int main(void)
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    float **m1;
    float **m2;
    m1 = alocaMatriz(m, n);
    m2 = alocaMatriz(n, m);
    recebeMatriz(m1, m, n);
    m2 = transpoeMatriz(m1, m, n);
    exibeTransposta(m2, n, m);

    return 0;
}

float **alocaMatriz(int linhas, int colunas)
{
    int i;
    float **mat;
    mat = (float **)malloc(sizeof(float *) * linhas);
    for (i = 0; i < linhas; i++)
        mat[i] = malloc(colunas * sizeof(float));
    return mat;
}

void recebeMatriz(float **mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i = i + 1)
        for (j = 0; j < n; j = j + 1)
            scanf("%f", &mat[i][j]);
}

float **transpoeMatriz(float **m, int tamLinha, int tamColuna)
{
    int i, j;
    float **b;
    b = (float **)malloc(sizeof(float *) * tamColuna);
    for (i = 0; i < tamColuna; i++)
        b[i] = malloc(tamLinha * sizeof(float));

    for (i = 0; i < tamLinha; i++)
    {
        for (j = 0; j < tamColuna; j++)
        {
            b[j][i] = m[i][j];
        }
    }
    return b;
}

void exibeTransposta(float **mat, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i = i + 1)
    {
        for (j = 0; j < n; j = j + 1)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }
}