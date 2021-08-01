#ifndef __LL_C
#define __LL_C

#include "ll.h"
#include <assert.h>
#include <stdio.h>

struct ll;

typedef struct llnode
{
  struct llnode *prev;
  struct llnode *next;
  struct ll *base;
} LLN;

typedef struct ll
{
  LLN *head;
  LLN *tail;
  int len;
  size_t data_size;
} LL;

static LL *_get_list_header(void *list)
{
  return (LL *)(((char *)list) - sizeof(LL));
}

static LLN *_get_node_header(void *node)
{
  return (LLN *)(((char *)node) - sizeof(LLN));
}

static void *_get_node_data(LLN *node)
{
  return ((char *)node) + sizeof(LLN);
}

static void *_get_list_data(LL *list)
{
  return ((char *)list) + sizeof(LL);
}

static void _free_node(LLN *node)
{
  free(node);
}

static LLN *_new_node(LL *list)
{
  assert(list != NULL);
  list->data_size;
  LLN *node = (LLN *)malloc(sizeof(LLN) + list->data_size);
  node->next = NULL;
  node->prev = NULL;
  node->base = list;
  return node;
}

void *_ll_new(size_t data_size)
{
  LL *list =
      (LL *)malloc(sizeof(LL) + data_size);
  list->head = NULL;
  list->tail = NULL;
  list->data_size = data_size;
  list->len = 0;
  return _get_list_data(list);
}

void ll_free(void *list)
{
  LL *ll = _get_list_header(list);
  LLN *node = ll->head;
  while (node != NULL)
  {
    LLN *next = node->next;
    _free_node(node);
    node = next;
  }
  free(ll);
}

void *_ll_insert_before(void *node)
{
  LLN *curr = _get_node_header(node);
  LLN *prev = curr->prev;
  LL *list = curr->base;
  LLN *new = _new_node(list);
  if (prev == NULL)
  {
    new->next = curr;
    curr->prev = new;
    list->head = new;
  }
  else
  {
    prev->next = new;
    curr->prev = new;
    new->next = curr;
    new->prev = prev;
  }

  list->len += 1;
  return _get_node_data(new);
}

void *_ll_insert_after(void *node)
{
  LLN *curr = _get_node_header(node);
  LLN *next = curr->next;
  if (next != NULL)
    return _ll_insert_before(_get_node_data(next));

  LL *list = curr->base;
  LLN *new = _new_node(list);
  curr->next = new;
  new->prev = curr;
  list->tail = new;

  list->len += 1;
  return _get_node_data(new);
}

void *_ll_push(void *list)
{
  LL *ll = _get_list_header(list);
  if (ll->tail != NULL)
    return _ll_insert_after(_get_node_data(ll->tail));

  LLN *new = _new_node(ll);
  ll->head = ll->tail = new;

  ll->len += 1;
  return _get_node_data(new);
}

int ll_len(void *list)
{
  return _get_list_header(list)->len;
}

void *_ll_next(void *node)
{
  LLN *next = _get_node_header(node)->next;
  return next != NULL ? _get_node_data(next) : NULL;
}

void ll_shift(void *list)
{
  LL *ll = _get_list_header(list);
  if (ll->head == NULL)
    return;

  LLN *new_head = ll->head->next;
  if (new_head == NULL)
  {
    ll->head = ll->tail = NULL;
    ll->len = 0;
  }
  else
  {
    ll->head = new_head;
    new_head->prev = NULL;
    ll->len -= 1;
  }
}

void *_ll_first(void *list)
{
  LLN *head = _get_list_header(list)->head;
  return head != NULL ? _get_node_data(head) : NULL;
}

void *_ll_last(void *list)
{
  LLN *tail = _get_list_header(list)->tail;
  return tail != NULL ? _get_node_data(tail) : NULL;
}

void *_ll(int index, void *list)
{
  LL *ll = _get_list_header(list);
  assert(0 <= index && index < ll->len);
  if (index == 0)
    return _ll_first(list);
  if (index == ll->len - 1)
    return _ll_last(list);

  LLN *node = ll->head;
  for (int i = 0; i < index; ++i)
    node = node->next;
  return _get_node_data(node);
}

#endif