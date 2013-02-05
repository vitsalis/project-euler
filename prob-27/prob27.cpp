#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n, i, j;
	bool prime[ 1000000 ];
	prime[ 0 ] = false;
	prime[ 1 ] = false;
	for ( i = 2; i <= 1000000; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i <= 1000000; ++i ) {
		for ( j = 2 * i; j <= 1000000; j += i ) {
			prime[ j ] = false;
		}
	}

	int a, b, count = 0, prod, max = 0, num;

	for ( a = -999; a < 1000; ++a ) {
		for ( b = -999; b < 1000; ++b ) {
			num = 1 + a + b;
			n = 1;
			while ( prime[ num ] ) {
				++n;
				++count;
				num = pow( n, 2 ) + ( a * n ) + b;
			}
			if ( count > max ) {
				max = count;
				prod = a * b;
			}
			count = 0;
		}
	}
	printf( "%d\n", prod );

	return 0;
}
