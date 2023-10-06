// joão pedro dias melo - 13828592
// Fernando Mezher Silva Lopes - 12725515
//Beatriz Vieira da Silva Andrade - 13692362

#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qnt_casos = 0, qnt_operacoes = 0, num;
    char operacao;
    int recebe_pilha = 0, recebe_fila = 0;
    int auxiliar;

    scanf("%d", &qnt_casos);

    /*for que ira ler cada linha de casos*/
    for (int a = 0; a < qnt_casos; a++)
    {
        /*criação de uma pilha e fila para o caso específico*/

        tipoFILA *fila = criar_fila();
        tipoPILHA *pilha = criar_pilha();

        scanf("%d", &qnt_operacoes);

        /*essa variavél ira auxiliar na leitura das operações de cada caso*/
        auxiliar = qnt_operacoes;

        while (auxiliar > 0)
        {
            scanf(" %c %d", &operacao, &num);

            if (operacao == 'i')
            { // ira inseir um elemento na pilha e fila
                push(pilha, num);
                queue(fila, num);
            }
            if (operacao == 'r')
            { // ira remover um elemento da fila e pilha se esse elemento existir nas estruturas
                if (recebe_pilha != -1)
                    recebe_pilha = pop(pilha, num); // ira retornar 1 se existir e -1 se nao existir

                if (recebe_fila != -1)
                    recebe_fila = dequeue(fila, num); // ira retornar 1 se existir e -1 se nao existir
            }
            auxiliar--;
        }

        /*nesta parte do código é feita a checagem para ver qual tipo de estrtura realiza
        a operação de remoçao */

        if (recebe_pilha != -1 && recebe_fila != -1)
        { // ambas as estruturas são capazes de realizar a operação
            printf("indefinido\n");
        }

        if (recebe_pilha == -1 && recebe_fila == -1)
        { // nenhuma das estruturas é capaz de realizar a operação
            printf("impossivel\n");
        }

        if (recebe_pilha != -1 && recebe_fila == -1)
        { // somente  a pilha realiza a operação
            printf("pilha\n");
        }

        if (recebe_pilha == -1 && recebe_fila != -1)
        { // somente a fila realiza a operação
            printf("fila\n");
        }

        /*ocorre a liberação da pilha e da fila criadas dinamicamente
         no caso em questão*/
        liberar_fila(&fila);
        liberar_pilha(&pilha);
        /*ambas as variáveis vão para zero , pois no próximo caso deveram
        ser reutilizadas */
        recebe_pilha = 0;
        recebe_fila = 0;
    }

    return 0;
}