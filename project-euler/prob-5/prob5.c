#include <stdio.h>

int main () {

	int i = 20, j, k = 1;

	while ( k ) {
		for ( j = 20; i % j == 0; --j ) {
			if ( j == 1 ) {
				printf( "%d\n", i);
				k = 0;
				break;
			}
		}
		i += 20;
	}
	return 0;
}
