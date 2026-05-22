
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(){
    FILA* fila;
    fila = filaCreate(10);
    filaInsert(fila, (void*) 10);
    filaInsert(fila, (void*) 20);
    filaInsert(fila, (void*) 30);

    printf("esta vazio: %d\n", filaIsEmpty(fila));
    filaDestroy(fila);

    return 0;
}


