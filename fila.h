#ifndef FILA_H
#define FILA_H
#define FILA_VAZIA -1
#define ELEMENTO_NAO_ENCONTRADO_FILA -1
#define ELEMENTO_PRESENTE_FILA 1

typedef struct no tipoNO;
typedef struct fila tipoFILA;

tipoFILA *criar_fila();
tipoNO *criar_no_fila(int valor);
void queue(tipoFILA *fila, int valor);
int dequeue(tipoFILA *fila, int valor);
void print_fila(const tipoFILA *fila);
void liberar_fila(tipoFILA**fila);

#endif