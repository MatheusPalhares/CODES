#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista_aux
{
    int id;
    struct lista_aux *prox;
};

struct lista
{
    struct lista_aux *inicio;
    struct lista_aux *fim;
};

struct pilha
{
    int tam;
    struct lista_aux *end_note;
    struct pilha *prox;
};

typedef struct pilha Pilha;
typedef struct lista Lista;

void inicializaPilha(Pilha *pilha)
{
    pilha->tam = 0;
    pilha->prox = NULL;
}

void inicializaLista(Lista *lista)
{
    lista->fim = NULL;
    lista->inicio = NULL;
}

void insereLista(Lista *lista, int id)
{
    struct lista_aux *novo = (struct lista_aux *)malloc(sizeof(struct lista_aux));
    novo->id = id;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = NULL;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->fim->prox = NULL;
    }
}

void MergeListas(Lista *l1, Lista *l2, Lista *l3)
{
    l1->fim->prox = l3->inicio;
    l1->fim = l3->fim;
    l2->fim->prox = l3->inicio;
    l2->fim = l3->fim;
}

void pushPilha(Pilha *pilha, struct lista_aux *end)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));

    novo->prox = pilha->prox;
    novo->end_note = end;
    pilha->prox = novo;

    pilha->tam++;
}

void ListaToPilha(Lista *lista, Pilha *pilha)
{
    struct lista_aux *LISTA_AUXILIAR = lista->inicio;

    while (LISTA_AUXILIAR != NULL)
    {
        pushPilha(pilha, LISTA_AUXILIAR);
        LISTA_AUXILIAR = LISTA_AUXILIAR->prox;
    }
}

struct lista_aux *popPilha(Pilha *pilha)
{
    Pilha *aux = pilha->prox;
    struct lista_aux *rem = aux->end_note;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

int pontoEmComum(Pilha *pilha1, Pilha *pilha2)
{
    struct lista_aux *end1 = popPilha(pilha1);
    struct lista_aux *end2 = popPilha(pilha2);
    int temp = end1->id;

    while (end1 == end2)
    {
        temp = end1->id;
        end1 = popPilha(pilha1);
        end2 = popPilha(pilha2);
    }
    return temp;
}

void inputValLista(Lista *lista, int index_lista)
{
    int i = 0;
    int id = 0;
    while (true)
    {
        printf("Digite o valor %d da lista %d\n", i + 1, index_lista);
        printf("DIGITE 0 PARA PARAR!!!\n");
        scanf("%d", &id);
        if (id == 0)
        {
            break;
        }
        insereLista(lista, id);
        i++;
    }
}

int main()
{
    Pilha pilha2;
    Pilha pilha1;

    inicializaPilha(&pilha2);
    inicializaPilha(&pilha1);

    Lista lista3;
    Lista lista2;
    Lista lista1;

    inicializaLista(&lista3);
    inicializaLista(&lista2);
    inicializaLista(&lista1);

    inputValLista(&lista1, 1);
    inputValLista(&lista2, 2);
    inputValLista(&lista3, 3);

    MergeListas(&lista1, &lista2, &lista3);

    ListaToPilha(&lista1, &pilha1);
    ListaToPilha(&lista2, &pilha2);

    int res = pontoEmComum(&pilha1, &pilha2);

    printf("Ponto de intersseccao: %d\n", res);

    return 0;
}
