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
 * */



