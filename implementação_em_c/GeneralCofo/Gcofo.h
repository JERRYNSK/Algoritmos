#ifndef _GCOFO_H_
#define _GCOFO_H_
#ifdef _GCOFO_C_
    typedef struct _gcofo _ {
    int numItens ;
    int maxItens ;
    int cur;
    void **item; // int *item;
    } GCOFO;
    gCofo *gcofCreate ( int max_itens );
    int gcofInsert (GCOFO* gcof, void *item );
    void *gcofRemove (GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type));
    void* gcofConsultar(GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type));
    void *gcofGetFirst (GCOFO* gcof);
    void *gcofGetNext (GCOFO* gcof);
    int gcofIsEmpty(GCOFO* gcof);
    int gcofDestroy (GCOFO* gcof);
    int gcofIsFull(GCOFO* gcof);
#else
    typedef struct _gcofo_ GCOFO;
    extern GCOFO *gcofCreate ( int max_itens );
    extern int gcofInsert (GCOFO *gcof, void *item );
    extern void * gcofRemove (GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type));
    extern void* gcofConsultar(GCOFO* gcof, void *key, char type, int (*comparar)(void*, void*, char type));
    extern void *gcofGetFirst (GCOFO*gcof);
    extern void *gcofGetNext (GCOFO *gcof);
    extern int gcofDestroy (GCOFO *gcof);
    extern int gcofIsEmpty(GCOFO* gcof);
    int gcofIsFull(GCOFO* gcof);
#endif
#endif
