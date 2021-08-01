#include "../src/ll.h"
#include <stdio.h>
#include <stdlib.h>

void example0()
{
  int *list;
  list = ll_new(list);

  *((int *)_ll_push(list)) = 10;
  printf("%d\n", *((int *)_ll_first(list)));

  *ll_push(list) = 10;
  printf("%d\n", *ll_first(list));

  ll_free(list);
}

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

void example4()
{
  int *list;
  list = ll_new(list);
  *ll_push(list) = 1;
  *ll_push(list) = 2;
  *ll_push(list) = 3;
  *ll_push(list) = 4;
  *ll_push(list) = 5;

  ll_remove(ll(0, list));
  ll_remove(ll(3, list));
  ll_remove(ll(1, list));

  printf("len=%d [ ", ll_len(list));
  int *node = ll_first(list);
  while (node != NULL)
  {
    printf("%d ", *node);
    node = ll_next(node);
  }
  printf("]\n");

  ll_free(list);
}

void example5()
{
  int data[] = {1, 2, 3, 4, 5};
  int **refs;
  refs = ll_new(refs);
  *ll_push(refs) = &data[0];
  *ll_push(refs) = &data[1];
  *ll_push(refs) = &data[2];
  *ll_push(refs) = &data[3];
  *ll_push(refs) = &data[4];

  printf("[ ");
  for (int **ref = ll_first(refs); ref != NULL; ref = ll_next(ref))
    printf("%d ", **ref);
  printf("]\n");

  ll_remove(ll_first(refs));

  printf("[ ");
  for (int **ref = ll_first(refs); ref != NULL; ref = ll_next(ref))
    printf("%d ", **ref);
  printf("]\n");

  data[2] = data[2] * 10;

  printf("[ ");
  for (int **ref = ll_first(refs); ref != NULL; ref = ll_next(ref))
    printf("%d ", **ref);
  printf("]\n");
}

void main()
{
  example1();
  example2();
  example3();
  example4();
  example5();
}