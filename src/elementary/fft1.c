#include <string.h>
#include <stdio.h>
#include "../../include/complex.h"
#include "../../include/bits.h"

imf64_t evaluate(imf64_t *P, imf64_t *Temp, int nterms, imf64_t x) {
    if (nterms == 1) {
        return mul_imf64_t(*P, x);
    }
    
    int size = nterms >> 1;
    imf64_t *E = P;
    imf64_t *O = P + size;

    memcpy(Temp, P, sizeof(imf64_t) * nterms);
    for (int i = 0; i < size; i += 1) {
        E[i] = Temp[(i << 1)];
        O[i] = Temp[(i << 1) + 1];
    }

    imf64_t square = mul_imf64_t(x, x);
    imf64_t e = evaluate(E, Temp, size, square);
    imf64_t o = evaluate(O, Temp + size, size, square);
    
    imf64_t xo = mul_imf64_t(x, o);

    return (imf64_t) {e.a + xo.a, e.b + xo.b};
}
