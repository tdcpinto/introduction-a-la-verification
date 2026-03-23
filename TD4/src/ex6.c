#include <klee/klee.h>

static uint32_t rol32(uint32_t x, unsigned r) {
    r &= 31u;
    return (r == 0) ? x : (uint32_t)((x << r) | (x >> (32u - r)));
}

static int check_password_5(const char s[5]) {
    static const uint32_t c1[5] = {7, 19, 37, 53, 71};
    static const uint32_t c2[5] = {3, 5, 11, 17, 23};

    uint32_t e1 = 0, e2 = 0;

    for (int i = 0; i < 5; i++) {
        e1 += c1[i] * (uint32_t)s[i];
        e2 += c2[i] * (uint32_t)s[i];
    }
    e1 += 0x234u;
    e2 ^= 0xA5A5A5A5u;

    uint32_t a = ((uint32_t)s[0] << 24) | ((uint32_t)s[1] << 16) | ((uint32_t)s[2] << 8) | (uint32_t)s[3];
    uint32_t e3 = a + ((uint32_t)s[4] * 0x01010101u);

    uint32_t x = 0;
    x ^= rol32((uint32_t)s[0] * 0x9E3779B1u, 3);
    x ^= rol32((uint32_t)s[1] * 0x9E3779B1u, 7);
    x ^= rol32((uint32_t)s[2] * 0x9E3779B1u, 13);
    x ^= rol32((uint32_t)s[3] * 0x9E3779B1u, 17);
    x ^= rol32((uint32_t)s[4] * 0x9E3779B1u, 23);
    uint32_t e4 = x + 0x13579BDFu;

    if (e1 != 20916)        return 0;
    if (e2 != 2779102559)   return 0;
    if (e3 != 2984366309)    return 0;
    if (e4 != 1852314472)   return 0;

    return 1;
}

int main() {

}