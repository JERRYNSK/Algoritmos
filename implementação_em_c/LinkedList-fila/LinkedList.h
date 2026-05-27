#ifndef _LINKEDLISTA_
#define _LINKEDLISTA_
typedef struct _linkedlista_ LIST;
//FIFO
LIST* listCreate();
int listInsert(LIST* node, void* item);
void* removeItem(LIST* node);
void* listGetFirst(LIST* node);
int flushList(LIST* node);


#endif // _LINKEDLISTA_
