#ifndef LinkedList
#define LinkedList

typedef struct item{
    int value;
    struct item *node;
} Node;

void printLinkedList(Node* start);
void insert(Node* start, Node* node);
void removeAt(Node* start, int index);
Node* get(Node* start, int index);


#endif // LinkedList

