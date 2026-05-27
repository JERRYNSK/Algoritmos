#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
//pequeno teste

    LIST* lista;
    lista = listCreate();

    printf("deu certo?: %d\n", listInsert(lista, (void*) 10));
    printf("deu certo?: %d\n", listInsert(lista, (void*) 777));
    printf("deu certo?: %d\n", listInsert(lista, (void*) 777));
    flushList(lista);
    listDestroy(lista);
    printf("lista?: %d\n", listGetFirst(lista));

    return 0;
}
