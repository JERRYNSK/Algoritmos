#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct _list_ {
    void* data;
    LIST* next;
}
LIST* listCreate(){
    LIST* newNode;
    newNode = (LIST*) malloc(sizeof(LIST));
    if(newNode != NULL){
        newNode->data = NULL;
        newNode->next = NULL;
        return newNode;
    }
    return NULL;
}
//insere no primeiro
int listPush(LIST* node, void* item){
    LIST* newNode;
    if(node != NULL){

    }
    return NULL;
}
