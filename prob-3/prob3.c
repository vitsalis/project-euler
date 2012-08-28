#include <stdio.h>

int main () {

	long long int super = 600851475143;
	int i = 2, j = 1;
	int prevnum = 0, num = 0;

	while ( j ) {
		if ( super % i == 0.0 ) {
			super = super / i;
			prevnum = i;
			if ( prevnum > num ) {
				num = prevnum;
			}
			i = 2;
		}
		else {
			++i;
		}
		if ( super < num ) {
			printf( "%d\n", num );
			j = 0;
		}
	}
	return 0;
}
