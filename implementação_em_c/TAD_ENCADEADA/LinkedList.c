
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define FALSE 0
#define TRUE 1
//funcoes
void addElements(SLIST* l, SLIST* listToReceive, int (*cmp)(void*, void*));
typedef struct _node_ NODE;
struct _linkedlista_ {
   NODE* first;
   NODE* cur;

};

struct _node_ {
    void* data;
    NODE* next;

};


SLIST* listCreate(){
    SLIST* newList;
    newList = (SLIST*) malloc(sizeof(SLIST));
    if(newList != NULL){
        newList -> first = NULL;
        newList -> cur = NULL;
        return newList;
    }
    return NULL;
}
int sllRemoveSpec(SLIST* l, void* key, int(*cmp)(void*, void*)){
    int STAT = FALSE;
    NODE* prev;
    if(l != NULL){
        if(l -> first != NULL){
            l->cur = l -> first;
            prev = NULL;
            STAT = cmp(l->cur->data, key);
            while( l->cur -> next != NULL && STAT == FALSE){
                prev = l->cur;
                l->cur = l->cur->next;
                STAT = cmp(l->cur->data, key);
            }
            if(STAT == TRUE){
                if ( prev == NULL) {
                    l->first = l->cur->next;
                } else {
                    prev->next =l->cur->next;
                }
                free(l->cur);
                return TRUE;
            }
        }
    }
    return FALSE;
}
int listPush(SLIST* l, void* item){
    NODE *newNode;
    newNode = (NODE*) malloc(sizeof(NODE));
    if(newNode != NULL){
        if(l != NULL){
           if (l -> first != NULL){
                newNode -> data = item;
                newNode -> next = l -> first;
                l -> first = newNode;
           } else {
                newNode -> data = item;
                newNode -> next = NULL;
                l->first = newNode;
           }
           return TRUE;
        }
    }
    return FALSE;
}
void* listRemoveFirst(SLIST* l){
    NODE* removedNode = NULL;
    void* data;
    if(l != NULL){
        if (l -> first != NULL){
            removedNode = l -> first;
            if(removedNode -> next != NULL){
                l -> first = removedNode -> next;
                data = removedNode->data;
                free(removedNode);
                return data;
            } else {
                data = removedNode->data;
                free(removedNode);
                return data;
            }
        }

    }
    return NULL;
}
void* listGetFirst(SLIST* l){
    if(l != NULL){
        if(l->first != NULL){
            return l -> first -> data;
        }
    }

    return NULL;

}
//funcoes adicionais
void* sllGetFirst (SLIST * l){
    void* data;
    if(l != NULL){
        if(l -> first != NULL){
            data = l -> first -> data;
            l -> cur = l -> first;
            return data;
        }
    }
    return NULL;
}
void* sllGetNext (SLIST * l){
    void* data;
    if(l != NULL){
        if(l -> cur != NULL && l -> cur -> next != NULL){
           l -> cur = l -> cur -> next;
            return l->cur->data;
        }
    }
    return NULL;
}
SLIST* sllIntersection(SLIST * l1, SLIST * l2, int (*cmp)(void*, void*)){
    SLIST* l3;

    l3 = listCreate();
    if(l3 != NULL){
        if(l1 != NULL && l2 != NULL){
            if(l1 -> first != NULL && l2->first != NULL){
                l1 -> cur = l1 -> first;

                while(l1 -> cur != NULL){
                    l2 -> cur = l2 -> first;
                    while(l2 -> cur != NULL){
                        if(cmp(l1 -> cur -> data, l2->cur->data)){
                            int STAT = FALSE;
                            if (l3 -> first != NULL){
                                l3 -> cur = l3 ->first;
                                //verificando se ja tem o valor comum
                                while(l3 -> cur != NULL){
                                    STAT = cmp(l3->cur->data, l1->cur->data);
                                    if(STAT == TRUE) break;
                                    l3-> cur = l3->cur->next;
                                }
                                if(STAT == FALSE) {
                                    listPush(l3, l1->cur->data);
                                }
                            } else {
                                listPush(l3, l1->cur->data);
                            }

                        }
                    l2->cur = l2->cur->next;
                    }

                l1->cur = l1->cur->next;

                }
                return l3;
            }
        }
    }

    return NULL;
}
SLIST* sllUniao (SLIST * l1, SLIST * l2, int (*cmp)(void*, void*)){
    SLIST* l3;
    l3 = listCreate();
    if(l1 != NULL && l2 != NULL && l3 != NULL){
        addElements(l1, l3, cmp);
        addElements(l2, l3, cmp);
        return l3;

    }

    return NULL;
}
void addElements(SLIST* l, SLIST* listToReceive, int (*cmp)(void*, void*)){
    if(l -> first != NULL){
        l -> cur = l -> first;
        while(l -> cur != NULL){
            void* data;
            data = l->cur->data;
            if(listToReceive -> first != NULL){

                int STAT = FALSE;
                listToReceive->cur = listToReceive->first;

                while(listToReceive->cur != NULL && STAT == FALSE){
                    STAT = cmp(data, listToReceive->cur->data);

                    listToReceive->cur = listToReceive->cur->next;
                }
                if(STAT == FALSE){
                    NODE* newNode;
                    newNode = (NODE*) malloc(sizeof(NODE));
                    newNode-> data = data;
                    newNode->next = listToReceive->first;
                    listToReceive->first = newNode;

                }
            }
            else {
                NODE* newNode;
                newNode = (NODE*) malloc(sizeof(NODE));
                newNode-> data = l-> cur -> data;
                newNode->next = NULL;
                listToReceive->first = newNode;
                listToReceive-> cur = listToReceive->first;
            }
            l -> cur = l -> cur -> next;
        }
    }

}

int destroyList(SLIST* l){

    NODE* trash;
    NODE* pointer;
    if(l != NULL){
        if(l -> first != NULL){
            pointer = l -> first;

            while(pointer != NULL){
                trash = pointer;
                pointer = pointer -> next;
                free(trash);
            }
            free(l);
            return TRUE;
        }
        free(l);
        return TRUE;
    }
    return FALSE;
}
