#include <klee/klee.h>

int sum(int x, int y) {
  	return x + y;
}

int main() {
	int a, b;

	/* Ces lignes permettent de définir les variables 
	 * 'a' et 'b' comme étant symboliques.
	*/
	klee_make_symbolic(&a, sizeof(a), "a");
	klee_make_symbolic(&b, sizeof(b), "b");

	if(a < 0 || b < 0) {
		return 1;
	}

	if(sum(a, b) < a || sum(a, b) < b) {
		return -1;
	}
	return 0;
}