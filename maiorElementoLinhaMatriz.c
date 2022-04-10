#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int tamLinhas, int tamColunas);
int freeMatriz(int **matriz, int tamLinhas);
void recebeMatriz(int **matriz, int tamLinhas, int tamColunas);
void exibemaiormenor(int **matriz, int tamLinhas, int tamColunas);

int main()
{
    int l, c;
    scanf("%d", &l);
    scanf("%d", &c);
    int **conteudo;
    conteudo = alocaMatriz(l, c);
    recebeMatriz(conteudo, l, c);
    exibemaiormenor(conteudo, l, c);
    freeMatriz(conteudo, l);

    return 0;
}

int **alocaMatriz(int tamLinhas, int tamColunas)
{
    int **matriz, i;
    matriz = (int **)malloc(sizeof(int *) * tamLinhas);
    for (i = 0; i < tamLinhas; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * tamColunas);
    }

    return matriz;
}

void recebeMatriz(int **matriz, int tamLinhas, int tamColunas)
{
    int i, j;
    for (i = 0; i < tamLinhas; i++)
    {
        for (j = 0; j < tamColunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void exibemaiormenor(int **matriz, int tamLinhas, int tamColunas)
{
    int maior, vet[tamLinhas], i, j;
    vet[0] = 0;
    maior = 0;
    for (i = 0; i < tamLinhas; i++)
    {
        for (j = 0; j < tamColunas; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
        vet[i] = maior;
        maior = 0;
    }
    for (i = 0; i < tamLinhas; i++)
    {
        printf("Maior da linha %d: %d\n", i, vet[i]);
    }
}

int freeMatriz(int **matriz, int tamLinhas)
{
    int i;
    if (matriz != 0)
    {
        for (i = 0; i < tamLinhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
        return 0;
    }
    return -1;
}