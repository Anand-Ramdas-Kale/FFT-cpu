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
