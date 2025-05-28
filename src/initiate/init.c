#include "../../include/complex.h"
#include "../../include/bits.h"
#include <math.h>
#include <stdbool.h>

/*
 *  this is the code that initializes all of the roots of unity needed by user
 *  I am using Euler's Identity for calculating the roots
 *  exp(i·θ) = cos(θ) + i·sin(θ)
 *  let,
 *      α = exp(i·θ/n) = cos(θ/n) + i·sin(θ/n)
 *      α^0, α^1, α^2, α^3, α^4, ... , α^(n-1)
 *      we can use repeated multiplication, but it might propogate error and increase it with each
 *      operation
 *      so I am calculating each one by calculating sine and cosine for each term,
 *  this calculation will be performed only once throughout the program, or we will use static arrays
 *  to store these results, every function here is also temporary
*/

// initializes the roots array
bool init_root(imf64_t *reserved, int reservedSize, int nRoot) {
    if (nRoot > reservedSize) {
        return false;
    }
    for (int i = 0; i < nRoot; ++i) {
        reserved[i] = (imf64_t){cosf(1.0f * i / (real)nRoot), sinf(1.0f * i / (real)nRoot)};
    }
    return true;
}
