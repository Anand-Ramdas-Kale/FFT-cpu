#include <string.h>
#include "../../include/complex.h"
#include "../../include/bits.h"

imf64_t evaluate(int *P, int *Temp, int nterms, imf64_t x) {
    if (nterms == 1) {
        int coeff = *P;
        return (imf64_t) {x.a * coeff, x.b * coeff};
    }
    
    int size = nterms >> 1;
    int *E = P;
    int *O = P + size;

    memcpy(Temp, P, sizeof(int) * nterms);
    for (int i = 0; i < size; i += 1) {
        E[i] = P[(i << 1)];
        O[i] = P[(i << 1) + 1];
    }

    imf64_t square = mul_imf64_t(x, x);
    imf64_t e = evaluate(E, Temp, size, square);
    imf64_t o = evaluate(O, Temp + size, size, square);

    imf64_t xo = mul_imf64_t(x, o);

    return (imf64_t) {e.a + xo.a, e.b + xo.b};
}
