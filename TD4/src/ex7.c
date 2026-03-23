#include <stdint.h>
#include <stddef.h>
#include <stdio.h>


static uint32_t rol32(uint32_t x, unsigned r) {
    r &= 31u;
    return (r == 0) ? x : (uint32_t)((x << r) | (x >> (32u - r)));
}

static int check_prefix(const char *s, size_t size) {
    if (size > 15) return 0;

    int a[] = {
        1183505026,
        3512421768,
        728339482,
        1832037989,
        2790652269,
        3401519764,
        1474434169,
        4232233418,
        2287493471,
        185366033,
        1636738433,
        836034156,
        983283142,
        1400293255
    };

    int b[] = {
        2654438284,
        2654440320,
        2654444113,
        2654450016,
        2654467761,
        2654501070,
        2654498814,
        2654549395,
        2654661578,
        2654820301,
        2654157335,
        2653608745,
        2651947990,
        2659036138
    };

    int c[] = {
        3891928147,
        2158801132,
        29754653,
        3030187485,
        2282021102,
        2797488351,
        2404763933,
        2175508778,
        247214600,
        1700737245,
        1061640679,
        2691095393,
        483340338,
        3610854744
    };

    uint32_t acc1 = 0x12345678u;
    uint32_t acc2 = 0x9E3779B9u;
    uint32_t acc3 = 0xA5A5A5A5u;

    for (size_t i = 0; i < size; i++) {
        uint32_t c = (uint32_t)(unsigned char)s[i];

        acc1 = rol32(acc1 ^ (c + 0x41u * (uint32_t)(i + 1)), 5);
        acc2 = (acc2 + c * (17u + 6u * (uint32_t)i)) ^ rol32(c, (unsigned)(i + 3));
        acc3 ^= rol32(c * 0x9E3779B1u, (unsigned)(7u * i + 1u));
    }

    if(
        a[size - 1] != acc1 ||
        b[size - 1] != acc2 ||
        c[size - 1] != acc3
    )
        return 0;
    return 1;
}

int main() {

}