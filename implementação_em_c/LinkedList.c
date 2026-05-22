#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"




    void printLinkedList(Node* start){
        Node* holder = NULL;
        int i = 0;
        while (start != NULL && (start -> node) != NULL){
            printf("list[%d]: %d", i, start -> value);
            Node* holder = start;
            start = (holder -> node);
            i++;
        }

    }
//digamos que o insert seja sempre no final do node
    void insert(Node* start, Node* node){
        Node* holder = NULL;
        while ((start -> node) != NULL){
            start = (start -> node);
        }
        start -> node = node;
    }

    void removeAt(Node* start, int index){

    }

    Node* get(Node* start, int index){

    return NULL;

}
