#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
#define TRUE 1
#define FALSE 0
typedef struct _node_ NODE;

struct _dllLIST_ {
    NODE* cur;
    NODE* first;
    NODE* last;
};
struct _node_ {
    void* data;
    NODE* prev;
    NODE* next;
};

DLIST* DLLcreate(){
    DLIST* node;
    node = (DLIST*) malloc(sizeof(DLIST));
    if(node != NULL){
        node -> first = NULL;
        return node;
    }
    return NULL;
}

int DLLpush(DLIST* l, void* item){
    NODE* newNode;
    newNode = (NODE*) malloc(sizeof(NODE));
    if(l != NULL){
        if(newNode != NULL){
            if(l -> first != NULL){
                l -> first -> prev = newNode;
                newNode ->next = l -> first;
                newNode -> prev = l -> last;
                l -> last -> next = newNode;
                newNode -> data = item;
                l -> first = newNode;
            } else {
                newNode -> data = item;
                l -> first = newNode;
                l -> last = newNode;
                newNode -> prev = l -> first;
                newNode -> next = l -> first;
            }

            return TRUE;
        }

    }
    return FALSE;
}


void* DLLtop(DLIST* l){
    if(l != NULL){
        if(l -> first != NULL){
            return l -> first -> data;
        }
    }
    return NULL;
}

void* DLLpop(DLIST* l){
    void* data;
    NODE* removedNode;
    if(l != NULL){
        if (l -> first != NULL){
            data = l -> first -> data;
            removedNode = l -> first;
            if(l -> first -> next != NULL){
                l -> first = l -> first -> next;
                l -> last -> next = l -> first;
            } else {
                l -> first = NULL;
            }
            free(removedNode);
            return data;

        }

    }
    return NULL;
}
int DLLconsultar(DLIST* l, void* key, int(*cmp)(void*, void*)){
    int stat = FALSE;
    if(l != NULL){
        if(l ->first != NULL){
            l -> cur = l -> first;
            stat = cmp(l -> cur -> data, key);
            while(l -> cur != l -> last && stat == FALSE){
                stat = cmp(l -> cur -> data, key);
                l -> cur = l -> cur -> next;
            }
            if(stat == TRUE){
                return TRUE;
            }

        }
    }
    return FALSE;
}
int DLLinsertBefore(DLIST* l, void* key, void* value, int(*cmp)(void*, void*)){
    int stat;
    NODE* prev;
    NODE* next;
    NODE* newNode;
    if(l != NULL){
        newNode = (NODE*) malloc(sizeof(NODE));
        if(newNode != NULL){
            if(l ->first != NULL){
                l -> cur = l -> first;
                stat = cmp(l ->cur->data, key);
                prev = l -> cur-> prev;
                next = l -> cur-> next;
                while(l -> cur != l-> last && stat == FALSE){
                    stat = cmp(l ->cur->data, key);
                    prev = l -> cur-> prev;
                    next = l -> cur-> next;
                    l -> cur = l -> cur -> next;
                }
                if(stat == TRUE){
                        newNode -> data = value;
                        newNode -> next = next -> prev;
                        newNode -> prev = prev;

                        prev -> next = newNode;
                        l -> cur -> prev = newNode;

                    } else {
                        DLLpush(l, value);
                        printf("dei um push\n");
                    }

            }
        }
    }
}
void* DLLremove(DLIST* l, void* key, int (*cmp)(void*, void*)){
    int stat = FALSE;
    void* data;
    NODE* removedNode;
    NODE* prev;
    NODE* next;
    if(l != NULL){
        if(l -> first != NULL){
            l -> cur = l -> first;
            /*stat = cmp(key, l->cur->data);
            prev = l->cur->prev;
            next = l->cur->next;
            while(l -> cur != l -> first && stat == FALSE){
                stat = cmp(key, l->cur->data);
                prev = l->cur->prev;
                next = l->cur->next;
                //if(stat == TRUE) break;
                l -> cur = l -> cur -> next;
            }*/
            do {
                stat = cmp(key, l->cur->data);
                prev = l->cur->prev;
                next = l->cur->next;
                if(stat == TRUE) break;
                l -> cur = l -> cur -> next;

            } while(l -> cur != l -> first);

            if(stat == TRUE){
                removedNode = l->cur;
                prev -> next = next;
                next -> prev = prev;

                data = removedNode-> data;
                if(removedNode == l -> first) l->first = next;
                else if(removedNode == l-> last) l-> last = prev;
                free(removedNode);

                return data;
            }
        }
    }
    return NULL;
}
void DLLimprimir(DLIST* l){
    if(l != NULL){
        if(l -> first != NULL){
            l -> cur = l -> first;
            while(l-> cur != NULL){
                printf("[%d], ", l -> cur -> data);
                if(l -> cur == l -> last) {
                    printf("\n");
                    break;
                }
                l -> cur = l -> cur -> next;
            }
        }
    }
}
