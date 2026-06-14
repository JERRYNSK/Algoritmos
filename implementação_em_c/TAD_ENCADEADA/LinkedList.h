#ifndef _LINKEDLISTA_
#define _LINKEDLISTA_
typedef struct _linkedlista_ SLIST;
//FIFO
SLIST* listCreate();
int listPush(SLIST* node, void* item);
void* listRemoveFirst(SLIST* node);
void* listGetFirst(SLIST* node);

void* listRemoveFirst(SLIST* l);

int sllRemoveSpec(SLIST* l, void* key, int(*cmp)(void*, void*));
int flushList(SLIST* node);
//funcoes adicionais
SLIST* sllIntersection(SLIST * l1, SLIST * l2, int (*cmp)(void*, void*));
SLIST* sllUniao(SLIST * l1, SLIST * l2, int (*cmp)(void*, void*));
void* sllGetFirst(SLIST* l);
void* sllGetNext(SLIST* l);

#endif // _LINKEDLISTA_
