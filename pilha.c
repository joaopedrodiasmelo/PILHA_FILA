#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{ /* criação de um no de uma pilha ou seja um elemento , que ira possuir um ponteiro para o proximo
      elemento e um para o elemento anterior.*/

    struct no *prox;
    struct no *anterior;
    int valor;

} tipoNO;

typedef struct pilha
{ // criaçao de uma struct pilha que é um ponteiro para o primeiro e último elemento da fila
    tipoNO *inicio;
    tipoNO *final;

} tipoPILHA;

tipoPILHA *criar_pilha()
{ // cria um tipo pilha ou seja o ponteiro para a pilha,colocando o início e o fim como NULL
    tipoPILHA *pilha = calloc(1, sizeof(tipoPILHA));
    pilha->final = NULL;
    pilha->inicio = NULL;

    return pilha;
}

tipoNO *criar_no(int valor)
{ // cria um no da pilha ,atribuindo o seu valor e colocando seus ponterios como NULL
    tipoNO *no = calloc(1, sizeof(tipoNO));
    no->valor = valor;
    no->prox = NULL;
    no->anterior = NULL;

    return no;
}

void push(tipoPILHA *pilha, int valor)
{ /*essa função ira enserir um elemento na ultima posição da pilha*/
    tipoNO *no = criar_no(valor);

    if (pilha->inicio == NULL && pilha->final == NULL)
    { // pilha esta vazia
        pilha->inicio = no;
        pilha->final = no;
    }

    else
    { // pilha não está vazia
        pilha->final->prox = no;
        no->anterior = pilha->final;
        pilha->final = no;
    }
}

int pop(tipoPILHA *pilha, int valor)
{ /*essa função ira remover um elemento do final se esse elemento apresentar um valor igual
  ao passado como parametro da função*/
    tipoNO *auxiliar2;

    if (pilha->inicio != NULL && pilha->final != NULL)
    { // pilha não esta vazia;
        if (pilha->inicio == pilha->final)
        { // pilha possui um único elemento
            if (pilha->final->valor == valor)
            {
                auxiliar2 = pilha->inicio;
                pilha->inicio = NULL;
                pilha->final = NULL;
                free(auxiliar2);

                return ELEMENTO_PRESENTE_PILHA;
            }
            else
            {
                return ELEMENTO_NAO_ENCONTRADO_PILHA;
            }
        }
        else
        { // pilha possui mais de um elemento
            if (pilha->final->valor == valor)
            {
                auxiliar2 = pilha->final;
                pilha->final = auxiliar2->anterior;
                auxiliar2->anterior->prox = NULL;
                free(auxiliar2);

                return ELEMENTO_PRESENTE_PILHA;
            }
            else
            {
                return ELEMENTO_NAO_ENCONTRADO_PILHA;
            }
        }
    }
    else
        return PILHA_VAZIA;
}

void print_pilha(const tipoPILHA *pilha)
{ // função que imprime uma pilha
    tipoNO *auxiliar = pilha->inicio;

    while (auxiliar != NULL)
    {
        printf("%d - ", auxiliar->valor);
        auxiliar = auxiliar->prox;
    }
    printf("\n");
}

void liberar_pilha(tipoPILHA **pilha)
{ // função que libera a pilha criada dinâmicamente

    tipoPILHA *auxiliar = *pilha;

    tipoNO *auxiliar2 = auxiliar->inicio;
    tipoNO *auxiliar3 = NULL;

    while (auxiliar2 != NULL)
    {
        auxiliar3 = auxiliar2;
        auxiliar2 = auxiliar2->prox;
        free(auxiliar3);
    }

    free(auxiliar);

    *pilha = NULL;
}
