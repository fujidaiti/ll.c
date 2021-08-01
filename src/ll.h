#ifndef __LL_H
#define __LL_H

#include <stdlib.h>

void *_ll_new(size_t data_size);
void ll_free(void *list);
void ll_shift(void *list);
int ll_len(void *list);
void *_ll_next(void *node);
void *_ll(int index, void *list);
void *_ll_first(void *list);
void *_ll_last(void *list);
void *_ll_insert_before(void *node);
void *_ll_insert_after(void *node);
void *_ll_push(void *list);

#define ll_new(LIST) ((typeof(LIST))_ll_new(sizeof(*LIST)))
#define ll_next(NODE) ((typeof(NODE))_ll_next(NODE))
#define ll(INDEX, LIST) ((typeof(LIST))_ll(INDEX, LIST))
#define ll_first(LIST) ((typeof(LIST))_ll_first(LIST))
#define ll_last(LIST) ((typeof(LIST))_ll_last(LIST))
#define ll_insert_before(NODE) ((typeof(NODE))_ll_insert_before(NODE))
#define ll_insert_after(NODE) ((typeof(NODE))_ll_insert_after(NODE))
#define ll_push(LIST) ((typeof(LIST))_ll_push(LIST))

#endif