#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
int main()
{
  Node *node1 = (Node*)malloc(sizeof(Node));
  Node *node2 = (Node*)malloc(sizeof(Node));

  node1 -> node = node2;

  printf("%d", node1 -> node -> value);

  free(node1);
  free(node2);



    return 0;
}
