#include <stdio.h>
#include <stdlib.h>

struct node
{
  int dado;
  struct node *prox;
};

struct Lista
{
  struct node *inicio;
} Lista;

void inicializar(struct Lista *lista);

/* inserir na lista Simplesmente Encadeada */
int inserirListaSE(struct Lista *lista, int dado);
int mostrarListaSE(struct Lista lista);

/* inserir na lista circular */
int inserirListaCircular(struct Lista *lista, int dado);
int mostrarListaCircular(struct Lista *lista);

int mostrarListaMergeFAKE(struct Lista lista, int repeticao);

/* Todo: Essas funções são o desafio */
void MergeLista(struct Lista *listaSE, struct Lista listaCircular);
int ExisteLoopNaListaEQuantidadeDeNos(struct Lista lista, int *qtdNos);

int main()
{

  struct Lista lista_se;
  struct Lista lista_merge;
  struct Lista l2_circular;

  int qtdNos = 0;

  inicializar(&lista_se);
  inicializar(&lista_merge);
  inicializar(&l2_circular);

  // usada para testar o caso onde não existe lista circular
  inserirListaSE(&lista_se, 100);
  inserirListaSE(&lista_se, 200);
  inserirListaSE(&lista_se, 300);

  // essa é lista simplesmente encadeada que vamos unir a lista circular
  inserirListaSE(&lista_merge, 1);
  inserirListaSE(&lista_merge, 2);
  inserirListaSE(&lista_merge, 3);

  mostrarListaSE(lista_merge);

  // essa é lista circular
  inserirListaCircular(&l2_circular, 4);
  inserirListaCircular(&l2_circular, 5);
  inserirListaCircular(&l2_circular, 6);

  mostrarListaCircular(&l2_circular);

  // Aqui ocorre o merge
  MergeLista(&lista_merge, l2_circular);

  // Essa é um função fake que imprime a lista unida (merge). Como a lista é circular é necessário informar para função
  // fake quantas vezes executar (no caso 6), caso contrário, você terá um loop infinito.
  mostrarListaMergeFAKE(lista_merge, 6);

  if (ExisteLoopNaListaEQuantidadeDeNos(lista_merge, &qtdNos))
  {
    printf("\nLista possui loop e esse loop é composto por %d nó(s).", qtdNos);
  }
  else
  {
    printf("\nLista não possui loop.");
  }

  if (ExisteLoopNaListaEQuantidadeDeNos(lista_se, &qtdNos))
  {
    printf("\nLista possui loop e esse loop é composto por %d nó(s).", qtdNos);
  }
  else
  {
    printf("\nLista não possui loop.");
  }

  return 0;
}

int ExisteLoopNaListaEQuantidadeDeNos(struct Lista lista, int *qtdNos)
{
  // todo: implementar
  struct node *fast, *slow;
  int res = 0;
  fast = lista.inicio->prox;
  slow = lista.inicio;
  int quantidade = 0;
  while (slow != NULL && fast != NULL && fast->prox != NULL)
  {
    if (slow == fast)
    {
      res = 1;
      break;
    }
    fast = fast->prox;
  }
  if (res == 1)
  {
    do
    {
      quantidade++;
      fast = fast->prox->prox;
    } while (slow != fast);
  }
  *qtdNos = quantidade;
  return res;
}

void MergeLista(struct Lista *listaMerge, struct Lista listaCircular)
{
  // todo: implementar
  struct node *aux;
  aux = listaMerge->inicio;
  while (aux != NULL)
  {
    if (aux->prox == NULL)
    {
      break;
    }
    aux = aux->prox;
  }
  aux->prox = listaCircular.inicio;
}

void inicializar(struct Lista *lista)
{
  lista->inicio = NULL;
}

/**
 * Observe que essa implementação não tem ponteiro de fim da lista
 */
int inserirListaSE(struct Lista *lista, int dado)
{
  struct node *aux, *aux2;
  struct node *novo = malloc(sizeof(struct node));

  novo->dado = dado;
  novo->prox = NULL;

  if (novo == NULL)
    return 0;

  if (lista->inicio == NULL)
  {
    lista->inicio = novo;
    novo->prox = NULL;
  }
  else
  {
    aux = lista->inicio;
    while (aux != NULL)
    {
      aux2 = aux;
      aux = aux->prox;
    }
    aux = aux2;
    aux->prox = novo;
  }

  return 1;
}

int mostrarListaSE(struct Lista lista)
{
  struct node *aux;

  if (lista.inicio == NULL)
  {
    return 0;
  }
  else
  {
    aux = lista.inicio;
    while (aux != NULL)
    {
      printf("%d ", aux->dado);
      aux = aux->prox;
    }
    printf("\n");
  }
  return 1;
}

int inserirListaCircular(struct Lista *lista, int dado)
{
  struct node *head;
  struct node *aux, *aux2;
  struct node *novo = malloc(sizeof(struct node));

  if (novo == NULL)
    return 0;

  novo->dado = dado;
  head = lista->inicio;

  if (lista->inicio == NULL)
  {
    lista->inicio = novo;
    novo->prox = lista->inicio;
    aux2 = head;
  }
  else
  {
    aux = lista->inicio->prox;
    aux2 = aux;
    while (aux != head)
    {
      aux2 = aux;
      aux = aux->prox;
    }
    aux = aux2;
    novo->prox = lista->inicio;
    aux->prox = novo;
  }

  return 1;
}

int mostrarListaCircular(struct Lista *lista)
{
  struct node *head = lista->inicio;
  struct node *current = lista->inicio;

  if (current == NULL)
  {
    return 0;
  }

  do
  {
    printf("%d ", current->dado);
    current = current->prox;
  } while (current != head);

  printf("\n");

  return 1;
}

int mostrarListaMergeFAKE(struct Lista lista, int repeticao)
{
  struct node *aux;
  int i = 0;

  if (lista.inicio == NULL)
  {
    return 0;
  }
  else
  {
    aux = lista.inicio;
    while (aux != NULL)
    {
      printf("%d ", aux->dado);
      aux = aux->prox;

      // para quando i for igual ao número de repetição definido, caso contrário, ficaria em loop infinito.
      if (i == repeticao)
        break;
      i++;
    }
    printf("\n");
  }

  return 1;
}
