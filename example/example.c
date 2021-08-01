#include "../src/ll.h"
#include <stdio.h>

void exampe1()
{
  int *list;
  list = ll_new(list);

  *ll_push(list) = 10;
  *ll_push(list) = 20;
  // *ll_insert_after(ll_first(list)) = 20;
  // *ll_push(list) = 30;

  int *value = ll_first(list);
  while (value != NULL)
  {
    printf("%d\n", *value);
    value = ll_next(value);
  }

  ll_free(list);
}

void main()
{
  exampe1();
}