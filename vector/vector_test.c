/* 4 October 2015 */

#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[])
{
  char sep = ',';
  int num = 0;
  int i = 0;

  struct Vec *vec = vec_new();

  /* this will error on empty */
  /* vec_pop(vec); */

  /* pushing and printing */
  vec_print(vec, sep);

  for (i = 1; i < 5; i++) {
    num = vec_push(vec, i * 1000);
    printf("num_items after push: %d\n", num);
    vec_print(vec, sep);
  }

  /* indexing */

  /* this will error */
  /* num = vec_at(vec, -1); */

  for (i = 0; i < vec->num_items; i++) {
    num = vec_at(vec, i);
    printf("item %d: %d\n", i, num);
  }

  /* this will error */
  /* vec_at(vec, 10); */

  /* setting items in the vec */

  /* this will error */
  /* num = vec_set_at(vec, -1, 50); */

  for (i = 0; i < vec->num_items; i++) {
    num = vec_set_at(vec, i, (i+1) * -10);
    printf("vec_set_at returned: %d\n", num);
    vec_print(vec, sep);
  }

  /* this will error */
  /* num = vec_set_at(vec, vec->num_items, 500); */

  /* popping things off */

  printf("\n\nvec->num_items: %d\n\n", vec->num_items);
  for (i = 1; i < 5; i++) {
    num = vec_pop(vec);
    printf("popped_item: %d\n", num);
    vec_print(vec, sep);
  }

  /* this will error */
  /* num = vec_pop(vec); */

  vec_destroy(vec);

  return 0;
}
