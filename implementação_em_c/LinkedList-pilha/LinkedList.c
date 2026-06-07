#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define FALSE 0
#define TRUE 1
struct _list_ {
    void* data;
    LIST* next;
};
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
    newNode = (LIST*) malloc(sizeof(LIST));
    if(newNode == NULL) return FALSE;

    if(node != NULL){
        newNode -> next = node -> next;
        node -> next = newNode;
        newNode -> data = item;
        return TRUE;
    }
    return FALSE;
}
void* listPop(LIST* node){
    LIST* removedNode;
    if(node != NULL){
        removedNode = node -> next;
        if(removedNode != NULL){
            node -> next = removedNode -> next;
            return removedNode->data;
        }
    }
    return NULL;
}
void* topList(LIST* node){

    if(node != NULL){
        if(node -> next != NULL){
            return node -> next -> data;
        }
    }
    return NULL;
}
int destroyList(LIST* node){

    if(node -> next == NULL){
        free(node);
        return 1;
    }
    destroyList(node -> next);
    free(node);
    return 1;
}
