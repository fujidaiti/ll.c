#include "../src/ll.h"
#include <stdio.h>
#include <stdlib.h>

void example1()
{
  int *list;
  list = ll_new(list);

  *ll_push(list) = 10;
  *ll_push(list) = 20;
  *ll_push(list) = 30;

  printf("len = %d\n", ll_len(list));
  int *node = ll_first(list);
  while (node != NULL)
  {
    printf("%d\n", *node);
    node = ll_next(node);
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

  ll_shift(list);

  printf("len = %d\n", ll_len(list));
  node = ll_first(list);
  while (node != NULL)
  {
    printf("[%d %d]\n", node->x, node->y);
    node = ll_next(node);
  }

  ll_free(list);
}

void example3()
{
  srand(0);
  int *list;
  list = ll_new(list);

  for (int i = 0; i < 10; ++i)
  {
    int x = rand() % 100;
    int *xi = ll_first(list);
    while (xi != NULL && *xi < x)
      xi = ll_next(xi);

    if (xi == NULL)
      *ll_push(list) = x;
    else
      *ll_insert_before(xi) = x;
  }

  printf("len=%d : [ ", ll_len(list));
  for (int i = 0; i < 10; ++i)
    printf("%d ", *ll(i, list));
  printf("]\n");

  ll_free(list);
}

void main()
{
  example1();
  example2();
  example3();
}