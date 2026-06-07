

#ifndef _DOUBLELINKEDLIST_
#define _DOUBLELINKEDLIST_
typedef struct _dllLIST_ DLIST;

//comportamento de pilha
int DLLpush(DLIST* l, void* item);
void* DLLpop(DLIST* l);
void* DLLtop(DLIST* l);
//comportamento fila
int DLLenqueue(DLIST* l, void* item);
void* DLLdequeue(DLIST* l);
void* DLLfirst(DLIST* l);

//funcoes diferentonas
int DLLinsertBefore(DLIST* l, void* key, void* value, int(*cmp)(void*, void*));
int DLLinsertAfter();
int DLLconsultar(DLIST* l, void* key, int(*cmp)(void*, void*));
void* DLLremove(DLIST* l, void* key, int(*cmp)(void*, void*));
void DLLimprimir(DLIST* l);


//extras
DLIST* DLLcreate();
int DLLdestroy(DLIST* l);
int DLLmakeCircle(DLIST* l);

#endif
