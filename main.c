#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "dyn_array.h"

DYN_ARRAY primes_up_to(NUMBER);
DYN_ARRAY factorization(NUMBER);

NUMBER num_from_string(const char*);
void print_solution(DYN_ARRAY, char);

void print_usage(const char* name) {
    fprintf(stderr,
            "Usage: %s (-p | -f) NUMBER\n",
            name);
}

int main(int argc, char* const argv[]) {

    int sol_type = -1;
    int opt;

    while ((opt = getopt(argc, argv, "pf")) != -1) {
        switch (opt) {
            case 'p':
            case 'f':
                if (sol_type == -1) {
                    sol_type = opt;
                    break;
                }
            default:
                print_usage(argv[0]);
                return 1;
        }
    }

    if (optind >= argc) {
        print_usage(argv[0]);
        return 1;
    }

    DYN_ARRAY (*solution_func)(NUMBER) = NULL;

    if (sol_type == 'p') {
        solution_func = &primes_up_to;
    }
    else if (sol_type == 'f') {
        solution_func = &factorization;
    }
    else {
        print_usage(argv[0]);
        return 1;
    }

    NUMBER number = num_from_string(argv[optind]);
    if (number < 2) {
        fprintf(stderr,
                "NUMBER should be a base-10 integer "
                "between 2 and 2**%lu - 1\n",
                sizeof(NUMBER) * 8);
        return 1;
    }

    DYN_ARRAY solution = (*solution_func)(number);
    print_solution(solution, sol_type);
    free(solution);
    return 0;
}

NUMBER num_from_string(const char* numstr) {
    const char* ref;
    if (sizeof(NUMBER) == 8) ref = "18446744073709551615";
    else ref = "4294967295";

    //simultaneously check validity and convert to NUMBER
    if (strlen(numstr) > strlen(ref)) return 0;
    NUMBER value = 0;
    for (size_t i = 0; i < strlen(numstr); i++) {
        if (numstr[i] < '0' || numstr[i] > '9') return 0;
        if (strlen(numstr) == strlen(ref) && numstr[i] > ref[i]) return 0;
        NUMBER digit = numstr[i] - '0';
        value *= 10;
        value += digit;
    }
    return value;
}

void print_solution(DYN_ARRAY solution, char type) {
    if (type == 'p') {
        for (NUMBER i = 0; i < len(solution); i++) {
            if (i % 5 == 0) printf("\n");
            printf("%10llu", at(solution, i));
        }
        printf("\n");
    }
    else if (type == 'f') {
        for (NUMBER i = 0; i < len(solution); i+=2) {
            printf("%llu ^ %llu\n", at(solution, i), at(solution, i + 1));
        }
    }
    else printf("Not a valid solution type\n");
}
