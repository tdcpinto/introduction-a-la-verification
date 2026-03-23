#include <klee/klee.h>

// sums the elements of the array modulo
// the given base
int modulo(short array[], int size, int base) {
    int modular_sum = 0;
    for(int i = 0; i < size; i++) {
        modular_sum += array[i] % base;
    }
    return modular_sum;
}