#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Crie aqui um struct para gerenciar a palavra e o seu tamanho */
struct tam_palavra
{
    char palavra[50];
    int tamanho;
};

/* insira aqui o algoritmo de sua preferência para ordenar. Não esqueça de adaptá-lo */
void insertionsort(struct tam_palavra *item, int count)
{
    int i, j;
    struct tam_palavra eleito;

    for (i = 1; i <= count - 1; i++)
    {
        eleito = item[i];
        j = i - 1;

        while (j >= 0 && item[j].tamanho > eleito.tamanho)
        {
            item[j + 1] = item[j];
            j = j - 1;
        }
        item[j + 1] = eleito;
    }
}

/**
 * Essa função recebe uma frase e armazena palavra por palavra na matrix
 */
int splitMatrix(char *string, char matrix[][50])
{

    int i = 0;

    // Extract the first token
    char *token = strtok(string, " ");
    // loop through the string to extract all other tokens
    while (token != NULL)
    {
        // printf( " %s\n", token ); //printing each token
        strcpy(matrix[i++], token);
        token = strtok(NULL, " ");
    }

    return i;
}

int main()
{
    char frase[500];
    int i;

    // leia até encontrar um ENTER */
    fscanf(stdin, "%[^\n]", frase);

    // Cria uma matriz
    char matriz[100][50];

    // Chama a função splitMatrix que recebe uma frase e retorna a matriz preenchida com as palavras que formam a frase.
    int num_palavras_na_frase = splitMatrix(frase, matriz);

    /* Talvez aqui você possa criar um vetor de estruturas dinamicamente alocado */
    struct tam_palavra *vetor = (struct tam_palavra *)malloc(num_palavras_na_frase * sizeof(struct tam_palavra));

    /* Uma vez que você tem uma matriz de palavras que foi processada pela função splitMatrix
       talvez agora seja o momento de inserir cada palavra e o seu tamanho no vetor de estruturas */
    for (i = 0; i < num_palavras_na_frase; i++)
    {
        strcpy(vetor[i].palavra, matriz[i]);
        vetor[i].tamanho = strlen(matriz[i]);
    }

    /* Aqui já é possível chamar o seu algoritmo de ordenação adaptado para ordenar vetor de structs */
    insertionsort(vetor, num_palavras_na_frase);

    /* Se tudo deu certo, aqui você pode imprimir o seu vetor de structs que já estará ordenado pelo tamanho da palavra */
    for (i = 0; i < num_palavras_na_frase; i++)
    {
        printf("%s ", vetor[i].palavra);
    }
    return 0;
}