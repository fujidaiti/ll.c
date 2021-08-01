#include "../src/ll.h"
#include <stdio.h>

void exampe1()
{
  int *list;
  list = ll_new(list);

  *ll_push(list) = 10;
  *ll_push(list) = 20;
  *ll_push(list) = 30;

  int *value = ll_first(list);
  while (value != NULL)
  {
    printf("%d\n", *value);
    value = ll_next(value);
  }

  ll_free(list);
}

typedef struct
{
  int x;
  int y;
} Point;

void example2()
{
  Point *list;
  list = ll_new(list);

  Point *node = ll_push(list);
  node->x = 10;
  node->y = -10;

  node = ll_insert_before(node);
  node->x = 20;
  node->y = -20;

  node = ll_insert_before(node);
  node->x = 30;
  node->y = -30;

  node = ll_first(list);
  while (node != NULL)
  {
    printf("[%d %d]\n", node->x, node->y);
    node = ll_next(node);
  }

  ll_free(list);
}

void main()
{
  exampe1();
  example2();
}