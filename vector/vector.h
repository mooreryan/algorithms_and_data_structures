/* 4 October 2015 */

#ifndef _vec_h
#define _vec_h

/* set it low for testing size doubling */
#define VEC_INIT_SIZE 3

struct Vec {
  int num_items;
  int max_items;
  int *items;
};

struct Vec *vec_new();
void vec_destroy(struct Vec *vec);

int vec_double_size(struct Vec *vec);

int vec_push(struct Vec *vec, int item);
int vec_pop(struct Vec *vec);

int vec_at(struct Vec *vec, int idx);
int vec_set_at(struct Vec *vec, int idx, int item);

void vec_print(struct Vec *vec, char sep);

#endif
