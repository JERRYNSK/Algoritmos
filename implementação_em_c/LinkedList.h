#ifndef LinkedList
#define LinkedList

typedef struct _node_ Node;

void printLinkedList(Node* start);
void insert(Node* start, Node* node);
void removeAt(Node* start, int index);
Node* get(Node* start, int index);


#endif // LinkedList

