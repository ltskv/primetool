#include "dyn_array.h"

DYN_ARRAY array_init() {
    DYN_ARRAY arr = malloc(HEADER_LEN * sizeof(NUMBER));
    //Element count
    arr[CNT_LOC] = 0;
    //Memory
    arr[MEM_LOC] = 0;
    return arr;
}

DYN_ARRAY append(DYN_ARRAY arr, NUMBER el) {
    NUMBER count = len(arr);
    NUMBER memory = mem(arr);
    count += 1;
    if (count > memory) {
        memory = memory > 0 ? memory * 2 : 1;
        arr = realloc(arr, (memory + HEADER_LEN) * sizeof(NUMBER));
        arr[MEM_LOC] = memory;
    }
    set_at(arr, count - 1, el);
    arr[CNT_LOC] = count;
    return arr;
}
