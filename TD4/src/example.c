#include <klee/klee.h>

int f(int x, int y) {
    if(x == 120 && y == 150) {
        return 0;
    }
    return x - y;
}

int main() {
    int x, y;

    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");

    if(f(x, y) != x - y) {
        return -1;
    }
    return 0;
}