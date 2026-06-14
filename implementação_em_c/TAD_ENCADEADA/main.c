#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include "LinkedList.h"
#define MAXLENGTH 10
#define FALSE 0
#define TRUE 1

//funcoes
void listar(SLIST* l);
int compare(void* a, void* b);



int compare(void* a, void* b){
    intptr_t v1, v2;
    v1 = (intptr_t) a;
    v2 = (intptr_t) b;
    return (v1 == v2);
}
int main()
{
    //variaveis
    int escolha = 1;
    errno = 0;
    long value;
    SLIST *l1, *l2, *l3;
    l1 = listCreate();
    l2 = listCreate();
    l3 = listCreate();
    char buffer[MAXLENGTH];
    char *endpointerError;
    //listar menu
    while(escolha != -1){
        printf("ESCOLHA A ACAO:\n\nSAIR[-1]\nInserir C1[1]\n⁠Inserir C2[2]\nRemover C1 spec[3]\nRemover C2 spec[4]\nListar C1[5]\nListar C2[6]\nListar C3[7]\nCriar interseccao[8]\nCriar uniao[9]\n");
        fgets(buffer, MAXLENGTH, stdin);
        escolha = atoi(buffer);
        switch(escolha){
            case 1:
                do {
                     printf("escreva o numero a colocar: \n");
                     fgets(buffer, MAXLENGTH, stdin);
                     value = strtol(buffer, &endpointerError, 10);
                } while(errno != 0 || errno == ERANGE || errno == EINVAL || endpointerError == buffer);
                listPush(l1, (void*)value);
            break;
            case 2:
                do {
                     printf("escreva o numero a colocar: \n");
                     fgets(buffer, MAXLENGTH, stdin);
                     value = strtol(buffer, &endpointerError, 10);
                } while(errno != 0 || errno == ERANGE || errno == EINVAL || endpointerError == buffer);
                listPush(l2, (void*)value);
            break;
            case 3:
                 do {
                    printf("escreva o numero a retirar: \n");
                    fgets(buffer, MAXLENGTH, stdin);
                    value = strtol(buffer, &endpointerError, 10);
                 } while(errno != 0 || errno == ERANGE || errno == EINVAL || endpointerError == buffer);
                sllRemoveSpec(l1, (void*)value, compare);
            break;
            case 4:
                 do {
                    printf("escreva o numero a retirar: \n");
                    fgets(buffer, MAXLENGTH, stdin);
                    value = strtol(buffer, &endpointerError, 10);
                 } while(errno != 0 || errno == ERANGE || errno == EINVAL || endpointerError == buffer);
                sllRemoveSpec(l2, (void*)value, compare);
            break;
            case 5:
                listar(l1);
            break;
            case 6:
                listar(l2);
            break;
            case 7:
                listar(l3);
            break;
            case 8:
            l3 = sllIntersection(l1, l2, compare);
            break;
            case 9:
            l3 = sllUniao(l1, l2, compare);
            break;
        }
    }


    l3 = sllIntersection(l1, l2, compare);




    free(l1);
    free(l2);
    free(l3);

    return 0;
}

void listar(SLIST* l){
     if(l != NULL){
        void* data;
        data = sllGetFirst(l);
        printf("LISTA DE VALORES: ");
        while (data != NULL){
            printf("%ld, ", (intptr_t)data);
            data = sllGetNext(l);
        }
        printf("\n===================\n");
    }
}
