#include <stdint.h>
#include <stdlib.h>

#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

typedef uint64_t* DYN_ARRAY;
typedef uint64_t NUMBER;

#define HEADER_LEN 2
#define CNT_LOC 0
#define MEM_LOC 1

DYN_ARRAY array_init() {
    DYN_ARRAY arr = malloc(HEADER_LEN * sizeof(NUMBER));
    //Element count
    arr[CNT_LOC] = 0;
    //Memory
    arr[MEM_LOC] = 0;
    return arr;
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

static inline DYN_ARRAY append(DYN_ARRAY arr, NUMBER el) {
    NUMBER count = len(arr);
    NUMBER memory = mem(arr);
    count += 1;
    if (count > memory) {
        memory = memory > 0 ? memory * 2 : 1;
        arr = realloc(arr, (memory + 2) * sizeof(NUMBER));
        arr[MEM_LOC] = memory;
    }
    set_at(arr, count - 1, el);
    arr[CNT_LOC] = count;
    return arr;
}
#endif
