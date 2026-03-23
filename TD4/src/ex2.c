#include <klee/klee.h>

// returns 1 if the password only contains 
// lowercase vowels, 0 otherwise
int password(char buffer[], unsigned int size) {
    for(int i = 0; i < size; i++) {
        int normalized = buffer[i] - 'a';
        if(normalized < 0 || normalized > 25) {
            return 0;
        }
        if(
            normalized != 0 && 
            normalized != 4 && 
            normalized != 8 && 
            normalized != 14 && 
            normalized != 20) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char buffer[7];
}