#ifndef _lista_
#define _lista_

typedef struct _list_ LIST;
//usando LIFO
LIST* listCreate();
int listPush(LIST* node, void* item);
void* listPop(LIST* node);
void* topList(LIST* node);
int destroyList(LIST* node);

#endif // _lista_
