#include "../../include/complex.h"

imf64_t mul_imf64_t (imf64_t x, imf64_t y) {
    /*
    real t1 = (x.a + x.b) * (y.a - y.b);
    real t2 = x.b * y.a;
    real t3 = x.a * y.b;
    return (imf64_t) {(t1 - t2 + t3), t2 + t3};
    */
    real a = x.a * y.a - x.b * y.b;
    real b = x.a * y.b + x.b * y.a;
    return (imf64_t) {a, b};
}

imf64_t add_imf64_t (imf64_t x, imf64_t y) {
    return (imf64_t) {x.a + y.a, x.b + y.b};
}

void mul_imf64_tp (imf64_t* x, imf64_t* y, imf64_t* z) {
    real b1 = x->b;
    real a2 = y->a;
    real a1 = x->a;
    real b2 = y->b;

    real t1 = (a1 + b1) * (a2 - b2);
    real t2 = b1 * a2;
    real t3 = a1 * b2;

    z->a = (t1 - t2 + t3);
    z->b = t2 + t3;
}

void add_imf64_tp (imf64_t* x, imf64_t* y, imf64_t* z) {
    z->a = x->a + y->a;
    z->b = x->b + y->b;
}

void conjugate(imf64_t *C) {
    C->b *= (real)(-1);
}
