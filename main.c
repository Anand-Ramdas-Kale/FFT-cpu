
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "./include/complex.h"
#include "./include/init.h"
#include <stdlib.h>

void print_imf64_t(imf64_t * A, int size) {
    for (int i = 0; i < size; i += 1) {
        printf("(%s%lf %s i·%lf) ", (A[i].a < 0) ? "-" : "", fabs(A[i].a), (A[i].b < 0) ? "-" : "+", fabs(A[i].b));
    }
    printf("\n");
}

int main() {
    imf64_t C[8] = {(imf64_t){1,0}, (imf64_t){2,0}, (imf64_t){3,0}, (imf64_t){4,0}, (imf64_t){1,0}, (imf64_t){2,0}, (imf64_t){3,0}, (imf64_t){4,0}};
    imf64_t T[8];
    memcpy(T, C, sizeof C);
    imf64_t Temp[8];
    imf64_t roots[8];
    // printf("----------- Coefficients ---------\n");
    // print_imf64_t(C, 8);

    if (!init_root(roots, 8, 8)) {
        abort();
    }
    // printf("----------- roots ---------\n");
    // print_imf64_t(roots, 8);

    imf64_t S[8];
    for (int i = 0; i < 8; i += 1) {
        memcpy(C, T, sizeof C);
        S[i] = evaluate(C, Temp, 8, roots[i]);
    }
    printf("----------- Samples ---------\n");
    print_imf64_t(S, 8);
    for (int i = 0; i < 8; i += 1) {
        conjugate(&roots[i]);
    }
    memcpy(T, S, sizeof C);
    for (int i = 0; i < 8; i += 1) {
        memcpy(S, T, sizeof C);
        C[i] = evaluate(S, Temp, 8, roots[i]);
        C[i].a = C[i].a / 8;
        C[i].b = C[i].b / 8;
    }
    printf("----------- Coefficients <- Samples ---------\n");
    print_imf64_t(C, 8);
    return 0;
}
