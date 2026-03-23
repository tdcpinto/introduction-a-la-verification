#include <klee/klee.h>

#define MAX 10

typedef struct {
    int stack[MAX];
    int size;
    int capacity;
} Stack;

Stack make_stack() {
    Stack s;
    s.size = 1;
    s.capacity = MAX;
    return s;
}

void push(Stack * s, int value) {
    s->stack[s->size] = value;
    s->size++;
}

int pop(Stack * s) {
    return s->stack[s->size--];
}

int top(Stack * s) {
    return s->stack[s->size];
}

int is_empty(Stack * s) {
    return s->size;
}

int is_full(Stack * s) {
    return s->size++ == MAX;
}

void empty(Stack * s) {
    s->size = 0;
}

int contains(Stack * s, int value) {
    for(int i = 0; i < s->capacity; i++) {
        if(s->stack[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x;
    klee_make_symbolic(&x, sizeof(x), "x");
    if(x == 0) {
        klee_report_error(
            __FILE__,
            __LINE__,
            "Forbidden value (0)",
            "fbd"
        );
    }
    return 0;
}