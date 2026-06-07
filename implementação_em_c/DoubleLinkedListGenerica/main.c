#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int compare(void* key1, void* key2){
    int a = (int) key1;
    int b = (int) key2;
    return a == b;
}
int main()
{
    DLIST* lista;
    lista = DLLcreate();
    DLLpush(lista, (void*) 10);
    DLLpush(lista, (void*) 20);
    DLLpush(lista, (void*) 30);
    DLLpush(lista, (void*) 40);
    DLLpush(lista, (void*) 50);
    DLLpush(lista, (void*) 60);
    DLLpush(lista, (void*) 70);


    //DLLpop(lista);
    //DLLpop(lista);


    //printf("esta la: %d\n", DLLconsultar(lista, (void*) 30, compare));
    //DLLinsertBefore(lista, (void*)60, (void*)222, compare);
    //DLLremove(lista, (void*)10, compare);
    printf("tem? %d\n", DLLconsultar(lista, (void*)40, compare));
    DLLimprimir(lista);

    return 0;
}
