


#include<stdio.h>
#include<stdlib.h>
#include "Gcofo.h"

#define TRUE 1
#define FALSE 0

struct _gcofo_ {
    int numItens;
    int maxItens;
    int cur;
    void **v;
};

//criacao de cofo
GCOFO* gcofCreate(int len){
    GCOFO* gcof;
    if (len > 0){
    gcof = (GCOFO*) malloc(sizeof(GCOFO));
        if (gcof != NULL){
            gcof ->v = malloc(sizeof(void*) * len);
            if(gcof -> v == NULL){
                free(gcof);
                return NULL;
            }
            gcof ->maxItens = len;
            gcof ->numItens = 0;
            gcof -> cur = -1;

            return gcof;
        }
    }
    return NULL;
}
int gcofDestroy(GCOFO* gcof){
    //somente esvaziar se estiver vazio
    if(gcof != NULL){
        if((gcof -> numItens) == 0){
            free(gcof -> v);
            free(gcof);
            gcof = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

//esvazia
int gcofEsvaziar(GCOFO* gcof){
    if(gcof != NULL ){
        for(int i = 0; i < (gcof -> numItens); i++){
            free(gcof->v[i]);
        }
        gcof->numItens = 0;
        return TRUE;
    }
    return FALSE;
}

//insere algo no cofo
int gcofInsert(GCOFO* gcof, void* item){
    if(gcof != NULL){
        if((gcof -> numItens) < (gcof -> maxItens)){
            gcof->v[gcof->numItens] = item;
            gcof -> numItens += 1;
            return TRUE;
        } else {
            return FALSE;
        }
    }
    return FALSE;
}

//retorna o que foi retirado;-;
void* gcofRemove(GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type)){
    void* data;
    if(gcof != NULL){
        for(int i = 0; i < (gcof->numItens);i++){
            if(comparar(gcof->v[i], key, type)){
                data = gcof->v[i];
                for(int j = i; j < (gcof->numItens) - 1; j++){
                    gcof->v[j] = gcof->v[j + 1];
                }
                gcof-> numItens -= 1;
                return data;
            }
        }
        return NULL;
    }
    return NULL;
}
void* gcofConsultar(GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type)){
    void* data;
    if(gcof != NULL){
        for(int i = 0; i < (gcof->numItens);i++){
            if(comparar(gcof->v[i], key, type)){
                data = gcof->v[i];
                return data;
            }
        }
        return NULL;
    }
    return NULL;
}

void* gcofGetFirst(GCOFO* gcof){
    if(gcof != NULL){
        if(gcof -> numItens > 0){
            return gcof -> v[0];//retorna o 0 pq é o primeiro, assim q entendi
        }
    }
    return NULL;
}
void* gcofGetNext(GCOFO* gcof){
    if(gcof != NULL){
        if(gcof ->numItens > 0){
            if((gcof -> cur) < ((gcof-> numItens) - 1)){
                gcof->cur += 1;
                return gcof->v[gcof->cur];
            } else {
                gcof->cur = -1;
            }
        }
    }
    return NULL;
}

int gcofIsFull(GCOFO* gcof){
    if(gcof != NULL){
        return gcof-> numItens == gcof->maxItens;
    }
    return FALSE;
}
int gcofIsEmpty(GCOFO* gcof) {
    if(gcof != NULL){
        return gcof -> numItens == 0;
    }
    return FALSE;
}





