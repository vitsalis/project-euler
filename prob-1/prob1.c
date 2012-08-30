#include <stdio.h>

const int MAX = 1000;

int main() {
	int num, sum = 0;

	for ( num = 0; num < MAX; ++num ) {
		if ( num % 3 == 0 || num % 5 == 0 ) {
			sum += num;
		}
	} 
	printf( "%d\n", sum );
	return 0;
}
