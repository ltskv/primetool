#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint64_t* DYN_ARRAY;
typedef uint64_t NUMBER;

DYN_ARRAY primes_up_to(NUMBER);
DYN_ARRAY factorization(NUMBER);

DYN_ARRAY array_init();
DYN_ARRAY append(DYN_ARRAY, NUMBER);
void set_at(DYN_ARRAY, NUMBER, NUMBER);
NUMBER at(DYN_ARRAY, NUMBER);
NUMBER length(DYN_ARRAY);
NUMBER memory(DYN_ARRAY);

int main(int argc, const char** argv) {
    DYN_ARRAY primes = primes_up_to(10000);
    for (NUMBER i = 0; i < length(primes); i++) printf("%9llu", at(primes, i));
    printf("\n");
    printf("%llu, %llu\n", length(primes), memory(primes));

    return 0;
}

DYN_ARRAY array_init() {
    DYN_ARRAY array = malloc(2 * sizeof(NUMBER));
    //Element count
    array[0] = 0;
    //Memory
    array[1] = 0;
    return array;
}

NUMBER length(DYN_ARRAY arr) {
    return arr[0];
}

NUMBER memory(DYN_ARRAY arr) {
    return arr[1];
}

NUMBER at(DYN_ARRAY arr, NUMBER ind) {
    return arr[ind + 2];
}

DYN_ARRAY append(DYN_ARRAY arr, NUMBER el) {
    NUMBER count = arr[0];
    NUMBER memory = arr[1];
    count += 1;
    if (count > memory) {
        memory = memory > 0 ? memory * 2 : 1;
        arr = realloc(arr, (memory + 2) * sizeof(NUMBER));
        arr[1] = memory;
    }
    set_at(arr, count - 1, el);
    arr[0] = count;
    return arr;
}

void set_at(DYN_ARRAY arr, NUMBER ind, NUMBER el) {
    arr[ind + 2] = el;
}

DYN_ARRAY primes_up_to(NUMBER top) {
    DYN_ARRAY primes = array_init();
    if (top < 2) {
        return primes;
    }
    primes = append(primes, 2);

    for (NUMBER maybe_prime = 3; maybe_prime <= top; maybe_prime += 2) {
        int is_prime = 1;
        for (NUMBER i = 0; maybe_prime / at(primes, i) >= at(primes, i); i++) {
            if (maybe_prime % at(primes, i) == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) primes = append(primes, maybe_prime);
        if (maybe_prime % 6 == 1) maybe_prime += 2;
    }
    return primes;
}

DYN_ARRAY factorization(NUMBER number) {
    DYN_ARRAY factors = array_init();

    NUMBER exp = 0;
    while (number % 2 == 0) {
        number /= 2;
        exp++;
    }

    if (exp) {
        append(factors, 2);
        append(factors, exp);
    }

    for (NUMBER maybe_div = 3; number / maybe_div >= maybe_div; maybe_div += 2) {
        exp = 0;
        while (number % maybe_div == 0) {
            number /= maybe_div;
            exp++;
        }

        if (exp) {
            append(factors, maybe_div);
            append(factors, exp);
        }
    }

    if (number != 1) {
        append(factors, number);
        append(factors, 1);
    }
    return factors;
}
