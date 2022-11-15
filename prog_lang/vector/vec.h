#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
#include <string.h>

#define vec_unpack_(v)\
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data)

#define vec_reserve(v, n)\
  vec_reserve_(vec_unpack_(v), n)


#define vec_t(T)\
  struct { T *data; int length, capacity; }


#define vec_init(v)\
  memset((v), 0, sizeof(*(v)))

#define vec_add(v, val)\
  ( vec_expand_(vec_unpack_(v)) ? -1 :\
    ((v)->data[(v)->length++] = (val), 0), 0 )


#define vec_pop(v)\
  (v)->data[--(v)->length]



#define vec_set_len(v, len) \
    ((v)->length=len);

#define vec_clear(v)\
  ((v)->length = 0)


#define vec_first(v)\
  (v)->data[0]


#define vec_last(v)\
  (v)->data[(v)->length - 1]


#define vec_compact(v)\
  vec_compact_(vec_unpack_(v))


int vec_reserve_(char **data, int *length, int *capacity, int memsz, int n);
int vec_expand_(char **data, int *length, int *capacity, int memsz);
int vec_compact_(char **data, int *length, int *capacity, int memsz);

typedef vec_t(int) vec_int_t;

int vec_take(vec_int_t vec, int num);

#endif
