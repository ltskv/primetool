#include "dyn_array.h"

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
        factors = append(factors, 2);
        factors = append(factors, exp);
    }

    for (NUMBER maybe_div = 3; number / maybe_div >= maybe_div; maybe_div += 2)
    {
        exp = 0;
        while (number % maybe_div == 0) {
            number /= maybe_div;
            exp++;
        }

        if (exp) {
            factors = append(factors, maybe_div);
            factors = append(factors, exp);
        }
    }

    if (number != 1) {
        factors = append(factors, number);
        factors = append(factors, 1);
    }
    return factors;
}
