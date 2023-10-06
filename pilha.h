#ifndef PILHA_H
#define PILHA_H
#define PILHA_VAZIA -1
#define ELEMENTO_NAO_ENCONTRADO_PILHA -1
#define ELEMENTO_PRESENTE_PILHA 1

typedef struct no tipoNO;
typedef struct pilha tipoPILHA;

tipoPILHA *criar_pilha();
tipoNO *criar_no(int valor);
void push(tipoPILHA *pilha, int valor);
int pop(tipoPILHA *pilha, int valor);
void print_pilha(const tipoPILHA *pilha);
void liberar_pilha(tipoPILHA **pilha);

#endif