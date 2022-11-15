#include <stdio.h>
#include <stdint.h>


#include "vec.h"

int main( )
{
    vec_int_t vec;
    vec_init(&vec);
    vec_add(&vec, 123);
    vec_add(&vec, 92);
    printf("First\n");
    printf("%d ", vec.length);
    printf("%d ", vec_take(vec, 0));
    printf("%d ", vec_take(vec, 1));
    printf("%d\n", vec.capacity);
    vec_reserve(&vec, 4);
    printf("Reserve\n");

    printf("%d ", vec.length);
    printf("%d\n", vec.capacity);

    vec_compact(&vec);
    printf("Compact\n");
    printf("%d\n", vec.length);
    printf("%d ", vec_take(vec, 0));
    printf("%d\n", vec_take(vec, 1));
    printf("%d\n", vec.capacity);
    return 0;
}
