#include <stdio.h>
#include "./include/complex.h"
#include <stdlib.h>

int main() {
    imf64_t a = (imf64_t) {1, 2};
    imf64_t b = (imf64_t) {3, 4};
    imf64_t c;
    mul_imf64_tp(&a, &b, &c);
    printf("%.1f + %.1fi\n", c.a, c.b);
    return 0;
}
