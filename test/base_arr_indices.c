/*
 this file is made for showing the result of divide and conquer algorithm of fft showing the last set of atomic indicex (last singleton sets)
 and compare them with the chosen algorithm of finding them without divide and conquer explicitly
 the divide and conqer mechanism is in the heart of this method (it just doesn't show it explicitly)

    what is method?
        just reverse the bits of each index and that formed number will be the index of coefficient that should be stored at the original index
        only the right r bits are reversed for 2^r - 1 degree polynomial

    example:
        suppose we apply the fft for degree 7 polynomial so,
        n = 8, degree = n - 1 = 7
        f(x) = a_0 + a_1*x + a_2*x^2 + a_3*x^3 + a_4*x^4 + a_5*x^5 + a_6*x^6 + a_7*x^7

        Level 0: [a_0, a_1, a_2, a_3, a_4, a_5, a_6, a_7]
        Level 1: [a_0, a_2, a_4, a_6]       [a_1, a_3, a_5, a_7]
        Level 2: [a_0, a_4]   [a_2, a_6]    [a_1, a_5]   [a_3, a_7]
        Level 3: [a_0] [a_4]  [a_2] [a_6]   [a_1] [a_5]  [a_3] [a_7]

        so at level three we see
         decimal   coefficient   binary   coefficient_index   bit-reversed
        ------------------------------------------------------------------
           0          a_0         000            a₀              000 (0)
           1          a_4         001            a₄              100 (4)
           2          a_2         010            a₂              010 (2)
           3          a_6         011            a₆              110 (6)
           4          a_1         100            a₁              001 (1)
           5          a_5         101            a₅              101 (5)
           6          a_3         110            a₃              011 (3)
           7          a_7         111            a₇              111 (7)
        ------------------------------------------------------------------
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GLOBAL_SPACE_SIZE = 1 << 12;
int static_space[1 << 12];

/**
 * @brief   divide and conquer mechanism of coefficient grouping / evaluation at each lvl
 * @param   r  degree of polynomial and last index of array
 * @param   coefficients  coefficient array
 * @return  void
 */
void divide_and_conquer_array_index_division(int r, int *coefficients) {
    return;
}

int nearest_power2(int r) {
    r -= 1;
    r |= (r >> 1);
    r |= (r >> 2);
    r |= (r >> 4);
    r |= (r >> 8);
    r |= (r >> 16);
    return r + 1;
}

void print_bits(int num) {
    
}

int count_bits(int n) {
    int count = 0;
    while (n) {
        count += 1;
        n >>= 1;
    }
    return count;
}

int reverse_bits(int i, int bit_length) {
    int reversed = 0;
    while (bit_length) {
        reversed <<= 1;
        bit_length -= 1;
        reversed |= (i & 1);
        i >>= 1;
    }
    return reversed;
}

void bit_reversal_array_index_division(int r, int *coefficients, bool print_indices_only) {
    int n = nearest_power2(r);
    if (n > GLOBAL_SPACE_SIZE) {
        printf("increase \"global_space_size\"\n");
        return;
    }
    int bit_length = count_bits(n) - 1;
    printf("bit_length = %d\n", bit_length);
    if (print_indices_only) {
        for (int i = 0; i < n; i += 1) {
            int coefficient_index = reverse_bits(i, bit_length);
            printf("%d -> %d\n", i, coefficient_index);
        }
        return;
    }
    for (int i = 0; i < n; i += 1) {
        int coefficient_index = reverse_bits(i, bit_length);
        printf("%d -> %d\n", i,(coefficient_index <= r) ? coefficients[coefficient_index] : 0);
    }
}

int main() {
    int r = 12;
    // int x = nearest_power2(r);
    // int l = count_bits(x);
    //
    // printf("r = %d\n", r);
    // printf("x = %d\n", x);
    // printf("l = %d\n", l);
    // printf("=--=--=--=--=--=\n");
    // for (int i = 0; i < x; i += 1) {
    //     printf("%d - %d\n", i, reverse_bits(i, l - 1));
    // }
    int *coefficients = malloc(sizeof(int[r]));
    for (int i = 0; i <= r; i += 1) {
        coefficients[i] = i;
    }
    bit_reversal_array_index_division(r, coefficients, false);
    return 0;
}
