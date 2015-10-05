/* 4 October 2015 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

struct Vec *vec_new()
{
  struct Vec *vec = malloc(sizeof(struct Vec));
  assert(vec != NULL);

  vec->items = malloc(sizeof(int) * VEC_INIT_SIZE);
  assert(vec->items != NULL);

  vec->num_items = 0;
  vec->max_items = VEC_INIT_SIZE;

  return vec;
}

void vec_destroy(struct Vec *vec)
{
  assert(vec != NULL);
  assert(vec->items != NULL);

  free(vec->items);
  free(vec);
}

int vec_double_size(struct Vec *vec)
{
  vec->max_items *= 2;
  assert(vec->max_items > vec->num_items);

  int *tmp = realloc(vec->items, sizeof(int) * vec->max_items);
  assert(tmp != NULL);

  vec->items = tmp;
  assert(vec->items != NULL);

  return vec->max_items;
}

int vec_push(struct Vec *vec, int item)
{
  if (vec->num_items >= vec->max_items) {
    fprintf(stderr, "Doubling size of Vec\n");
    vec_double_size(vec);
  }
  assert(vec->num_items <= vec->max_items);

  vec->items[vec->num_items] = item;

  vec->num_items += 1;

  return vec->num_items;
}

int vec_pop(struct Vec *vec)
{
  if (vec->num_items == 0) {
    fprintf(stderr, "ERROR: tried to pop empty vector\n");
    exit(1);
  }

  vec->num_items -= 1;

  return vec->items[vec->num_items];
}

int vec_at(struct Vec *vec, int idx)
{
  if (idx < 0) {
    fprintf(stderr, "ERROR: negative index\n");
    exit(1);
  }

  if (idx >= vec->num_items) {
    fprintf(stderr,
            "ERROR: index (%d) out of range (%d)\n",
            idx,
            vec->num_items);
    exit(1);
  }

  return vec->items[idx];
}

int vec_set_at(struct Vec *vec, int idx, int item)
{
  if (idx < 0) {
    fprintf(stderr, "ERROR: negative index\n");
    exit(1);
  }

  if (idx >= vec->num_items) {
    fprintf(stderr,
            "ERROR: index (%d) out of range (%d)\n",
            idx,
            vec->num_items);
    exit(1);
  }

  vec->items[idx] = item;

  return item;
}

void vec_print(struct Vec *vec, char sep)
{
  if (vec->num_items < 1) { /* if it is empty */
    printf("");
  } else {
    int i = 0;

    for (i = 0; i < vec->num_items - 1; i++) {
      printf("%d%c", vec->items[i], sep);
    }

    printf("%d\n", vec->items[i]);
  }
}
