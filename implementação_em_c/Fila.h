#ifndef FILA_H
#define FILA_H

typedef struct _fila_ FILA;

FILA* filaCreate(int len);
int filaInsert(FILA* fila, void*  elemento);
void* filaRemove(FILA* fila);
int filaIsEmpty(FILA* fila);
void* filaFront(FILA* fila);
int filaDestroy(FILA* fila);
#endif // FILA_H
