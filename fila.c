#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{ /* criação de um no de uma fila ou seja um elemento , que ira possuir um ponteiro para o proximo
     elemento e um para o elemento anterior.*/

    struct no *prox;
    struct no *anterior;
    int valor;

} tipoNO;

typedef struct fila
{ // criaçao de uma struct fila que é um ponteiro para o primeiro e último elemento da fila
    tipoNO *inicio;
    tipoNO *final;

} tipoFILA;

tipoFILA *criar_fila()
{ // cria um tipo fila ou seja o ponteiro para a fila ,colocando o início e o fim como NULL
    tipoFILA *fila = calloc(1, sizeof(tipoFILA));
    fila->final = NULL;
    fila->inicio = NULL;

    return fila;
}

tipoNO *criar_no_fila(int valor)
{ // cria um no da fila ,atribuindo o seu valor e colocando seus ponterios como NULL
    tipoNO *no = calloc(1, sizeof(tipoNO));
    no->valor = valor;
    no->prox = NULL;
    no->anterior = NULL;

    return no;
}

void queue(tipoFILA *fila, int valor)
{ /*essa função ira enserir um elemento na ultima posição da fila*/
    tipoNO *no = criar_no_fila(valor);

    if (fila->inicio == NULL && fila->final == NULL)
    { // fila está vazia
        fila->inicio = no;
        fila->final = no;
    }

    else
    { // fila não está vazia
        fila->final->prox = no;
        no->anterior = fila->final;
        fila->final = no;
    }
}

int dequeue(tipoFILA *fila, int valor)
{ /*essa função ira remover um elemento do inicio se esse elemento apresentar um valor igual
 ao passado como parametro da função*/
    tipoNO *auxiliar;

    if (fila->inicio != NULL && fila->final != NULL) // verifica se a fila não esta vazia
    {
        if (fila->inicio == fila->final)
        { // fila com um unico elemento
            if (fila->inicio->valor == valor)
            {
                auxiliar = fila->inicio;
                fila->inicio = NULL;
                fila->final = NULL;
                free(auxiliar);

                return ELEMENTO_PRESENTE_FILA;
            }
            else
            {
                return ELEMENTO_NAO_ENCONTRADO_FILA;
            }
        }

        else
        { // fila com mais de um elemento
            if (fila->inicio->valor == valor)
            {
                auxiliar = fila->inicio;
                fila->inicio = auxiliar->prox;
                auxiliar->prox->anterior = NULL;
                free(auxiliar);

                return ELEMENTO_PRESENTE_FILA;
            }
            else
            {
                return ELEMENTO_NAO_ENCONTRADO_FILA;
            }
        }
    }
    else
        return FILA_VAZIA;
}

void print_fila(const tipoFILA *FILA)
{ // função que imprime uma fila
    tipoNO *auxiliar = FILA->inicio;

    while (auxiliar != NULL)
    {
        printf("%d - ", auxiliar->valor);
        auxiliar = auxiliar->prox;
    }
    printf("\n");
}

void liberar_fila(tipoFILA **fila)
{ // função que libera a fila criada dinâmicamente

    tipoFILA *auxiliar = *fila;

    tipoNO *auxiliar2 = auxiliar->inicio;
    tipoNO *auxiliar3 = NULL;

    while (auxiliar2 != NULL)
    {
        auxiliar3 = auxiliar2;
        auxiliar2 = auxiliar2->prox;
        free(auxiliar3);
    }

    free(auxiliar);

    *fila = NULL;
}