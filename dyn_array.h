#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef NUMBER
#define NUMBER uint64_t
#endif

#define DYN_ARRAY NUMBER*

#define HEADER_LEN 2
#define CNT_LOC 0
#define MEM_LOC 1

DYN_ARRAY array_init();
DYN_ARRAY append(DYN_ARRAY, NUMBER);

static inline NUMBER* addr(DYN_ARRAY arr, NUMBER ind) {
    return arr + HEADER_LEN + ind;
}

static inline NUMBER len(DYN_ARRAY arr) {
    return arr[CNT_LOC];
}

static inline NUMBER mem(DYN_ARRAY arr) {
    return arr[MEM_LOC];
}

static inline NUMBER at(DYN_ARRAY arr, NUMBER ind) {
    return arr[ind + HEADER_LEN];
}

static inline void set_at(DYN_ARRAY arr, NUMBER ind, NUMBER el) {
    arr[ind + HEADER_LEN] = el;
}

#endif
