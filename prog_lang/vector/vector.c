#include "vec.h"


int vec_expand_(char **data, int *length, int *capacity, int memsz) {
    if (*length + 1 > *capacity) {
        void *ptr;
        int n = (*capacity == 0) ? 1 : *capacity << 1;
        ptr = realloc(*data, n * memsz);
        if (ptr == NULL) return -1;
        *data = ptr;
        *capacity = n;
    }
    return 0;
}

int vec_reserve_(char **data, int *length, int *capacity, int memsz, int n) {
    (void) length;
    if (n > *capacity) {
        void *ptr = realloc(*data, n * memsz);
        if (ptr == NULL) return -1;
        *data = ptr;
        *capacity = n;
    }
    return 0;
}
int vec_compact_(char **data, int *length, int *capacity, int memsz) {
    if (*length == 0) {
        free(*data);
        *data = NULL;
        *capacity = 0;
        return 0;
    } else {
        void *ptr;
        int n = *length;
        ptr = realloc(*data, n * memsz);
        if (ptr == NULL) return -1;
        *capacity = n;
        *data = ptr;
    }
    return 0;
}


int vec_take(vec_int_t vec, int num){
    return vec.data[num];
}

