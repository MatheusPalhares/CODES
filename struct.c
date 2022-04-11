#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
  char nome[50];
  float n1, n2;
  float media;
} * a, *m, *l;

void lerAluno(struct aluno *a)
{
  scanf("%s", a->nome);
  scanf("%f", &a->n1);
  scanf("%f", &a->n2);
}
void calculaMedia(struct aluno *m)
{
  m->media = (m->n1 + m->n2) / 2;
}
void exibeMedia(struct aluno *l, int r)
{
  int i = 0;
  for (i = 0; i < r; i++)
  {
    printf("%s\n", l[i].nome);
    printf("%.2f\n", l[i].media);
  }
}

int main()
{
  int r;
  scanf("%d", &r);
  int i = 0;
  struct aluno *vetor = (struct aluno *)malloc(sizeof(struct aluno) * r);
  for (i = 0; i < r; i++)
  {
    lerAluno(&vetor[i]);
  }
  for (i = 0; i < r; i++)
  {
    calculaMedia(&vetor[i]);
  }
  exibeMedia(vetor, r);
  free(vetor);
  return 0;
}