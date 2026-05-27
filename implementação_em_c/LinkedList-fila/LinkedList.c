
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define FALSE 0
#define TRUE 1
struct _linkedlista_ {
    void* data;
    LIST* next;

};
LIST* listCreate(){
    LIST* newList;
    newList = (LIST*) malloc(sizeof(LIST));
    if(newList != NULL){
        newList -> data = NULL;
        newList -> next = NULL;
        return newList;
    }
    return NULL;
}

int listInsert(LIST* node, void* item){
    LIST* newNode;
    newNode = (LIST*) malloc(sizeof(LIST));

    if(node != NULL){
        while(node -> next != NULL){
            node = node -> next;
        }
        if(newNode != NULL){
            newNode -> data = item;
            node -> next = newNode;
            return TRUE;
        }

    }
    return FALSE;
}
void* removeItem(LIST* node){
    LIST* removedNode = NULL;
    if(node != NULL){
        if(node -> next != NULL){
            removedNode = node -> next;
            node -> next = removedNode -> next;
            return  removedNode -> data;
        }
    }
    return NULL;
}
void* listGetFirst(LIST* node){
    LIST* firstNode;
    if(node != NULL){
        firstNode = node -> next;
        return firstNode -> data;
    }
    return NULL;

}

int flushList(LIST* node){
    if(node->next != NULL){
        return flushList(node -> next);
    }
    free(node);
    return 1;
}
