#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"

#define FALSE 0
#define TRUE 1

struct _fila_ {

    int front;
    int rear;
    int numItens;
    int maxItens;
    void** vec;
};

FILA* filaCreate(int len){
    FILA* ptrFila;
    if (len > 0){
        ptrFila = (FILA*) malloc(sizeof(FILA));
        if(ptrFila != NULL){
            ptrFila ->vec = malloc(sizeof(void*) * len);
            if(ptrFila ->vec != NULL){
                ptrFila -> maxItens = len;
                ptrFila -> numItens = 0;
                ptrFila -> front = 0;
                ptrFila -> rear = -1;
                return ptrFila;
            }
            free(ptrFila);
        }
    }
    return NULL;
}

int filaInsert(FILA* fila, void* elm){

    if(fila != NULL){
        if(fila -> numItens < fila -> maxItens){
            fila -> rear = (fila -> rear + 1) % fila -> maxItens;
            fila -> vec[fila -> rear] = elm;
            fila -> numItens += 1;
            return TRUE;
        }
    }
    return FALSE;
}

void* filaRemove(FILA* fila){
    void* data;
    if(fila != NULL){
        if(fila -> numItens > 0){
            data = fila -> vec[fila -> front];
            fila -> front = (fila -> front + 1) % fila -> maxItens;
            fila -> numItens -= 1;
            return data;
        }
    }
    return NULL;
}

int filaIsEmpty(FILA* fila){
    if(fila != NULL){
        return fila -> numItens == 0;
    }
    return -1;
}
void* filaFront(FILA* fila){
    void* data;
    if(fila != NULL){
        if(fila -> numItens > 0){
            data = fila -> vec[fila -> front];
            return data;
        }

    }
    return NULL;
}
int filaDestroy(FILA* fila){
    if(fila != NULL){
        if(fila -> numItens == 0){
            free(fila -> vec);
            free(fila);
            return TRUE;
        }
    }
    return FALSE;
}
