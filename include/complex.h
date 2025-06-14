/*
    I am still thinking about which implementation should be used,
    I am using the a + ib representation of the imaginary numbers,
    here addition will be easy, but multiplication is computationally intensive,
    whereas in the Euler's representation - re^(ix) addition is computationally intensive, while multiplication is straight forward
    we will be performing too many multiplications here
    but the combining step after multiplication (addition) wants us to compute sines and cosines of angles,
    which i think is longer method than using cpu's fast floating point multiplication units which are also more than one in number
    ... we will expoit instruction level parallelism in future
*/

typedef double real;

typedef struct {
    int a, b;
} imi32_t;

typedef struct {
    real a, b;
} imf64_t; // TODO: I will fix this

/*
    I don't want the final implementation of fft to have much overhead of procedures and loops and brances,
    hence any function that are being created here are more of a temporary kind, - just to see if the logic works ?...
    after that we will be repalcing them with in-place code as a c developer do,

    NOTE : NONE OF THE "NEAT CODE RULES" WILL BE OBEYED IN THIS CODE-BASE,
    I AM DOING WHAT MATTERS FOR PERFORMANCE, (IF NOT YET...)
*/
imf64_t mul_imf64_t (imf64_t x, imf64_t y);
imf64_t add_imf64_t (imf64_t x, imf64_t y);

void mul_imf64_tp (imf64_t* x, imf64_t* y, imf64_t* z);
void add_imf64_tp (imf64_t* x, imf64_t* y, imf64_t* z);

// rough fft-functions
imf64_t evaluate(imf64_t *P, imf64_t *Temp, int nterms, imf64_t x);
void conjugate(imf64_t *C);
