#include <stdio.h>
#include <string.h>
#include "dyn_array.h"

DYN_ARRAY primes_up_to(NUMBER);
DYN_ARRAY factorization(NUMBER);

NUMBER parse(const char*);
void print_solution(DYN_ARRAY, char);

int main(int argc, const char** argv) {

    if (argc < 3) {
        printf("Usage: prime -pf number\n");
        return 0;
    }
    NUMBER number;
    DYN_ARRAY solution;
    switch (argv[1][1]) {
        case 'p':
            number = parse(argv[2]);
            if (number == 0) {
                fprintf(stderr, "number should be integer btw 2 and 2^64 - 1\n");
                return 1;
            }
            solution = primes_up_to(number);
            print_solution(solution, 'p');
            break;
        case 'f':
            number = parse(argv[2]);
            if (number == 0) {
                fprintf(stderr, "number should be integer btw 2 and 2^64 - 1\n");
                return 1;
            }
            solution = factorization(number);
            print_solution(solution, 'f');
            break;
        default:
            fprintf(stderr, "unrecognized option %s\n", argv[1]);
            return 1;
            break;
    }
    return 0;
}

NUMBER parse(const char* numstr) {
    const char* ref;
    if (sizeof(NUMBER) == 8) ref = "18446744073709551615";
    else ref = "4294967295";

    //simultaneously check validity and convert to NUMBER
    NUMBER value = 0;
    if (strlen(numstr) > strlen(ref)) return 0;
    for (int i = 0; i < strlen(numstr); i++) {
        if (numstr[i] < 48) return 0;
        if (strlen(numstr) == strlen(ref) && numstr[i] > ref[i]) return 0;
        NUMBER digit = numstr[i] - 48;
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
