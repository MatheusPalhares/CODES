#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int splitMatrix(char *string, char **matrix)
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

void OrdenaMatriz(char **mat, int l)
{
  int j, i;
  char eleito[20][20];

  for (i = 1; i <= l - 1; i++)
  {
    strcpy(eleito[i], mat[i]);
    j = i - 1;

    while (j >= 0 && mat[j] > eleito[i])
    {
      mat[j + 1] = mat[j];
      j--;
    }

    strcpy(mat[j + 1], eleito[j]);
  }
}

int main()
{

  char string[100] = "Eu gosto muito de estudar Estrutura de Dados e usar ponteiros e algo muito legal";
  int i, line = 50, col = 50;

  char **m = (char **)malloc(line * sizeof(char *));
  for (i = 0; i < line; i++)
    m[i] = (char *)malloc(col * sizeof(char));

  int size = splitMatrix(string, m);

  OrdenaMatriz(m, line);

  for (i = 0; i < size; i++)
  {
    printf("%s\n", m[i]);
  }

  for (i = 0; i < line; i++)
    free(m[i]);

  free(m);

  return 0;
}