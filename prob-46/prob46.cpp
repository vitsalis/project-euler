#include <cstdio>
#include <cmath>

using namespace std;
int max;
bool check( int A[], int num ) {
	int i, j, n;

	for ( i = 0; A[ i ] < num && i < max; ++i ) {
		j = 1;
		while ( 1 ) {
			n = pow( j, 2 );
			if ( A[ i ] + 2 * n == num ) return true;
			if ( A[ i ] + 2 * n > num ) break;
			++j;
		}
	}
	return false;

}

int main() {
	int i, j, A[ 10000 ];
	bool prime[ 10000 ];
	for ( i = 2; i < 10000; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i < 10000; ++i ) {
		for ( j = 2 * i; j < 10000; j += i ) {
			prime[ j ] = false;
		}
	}
	for ( i = 2, j = 0; i < 10000; ++i ) {
		if ( prime[ i ] ) {
			A[ j++ ] = i;
		}
	}
	max = j;
	for ( i = 3; i < 10000; i += 2 ) {
		if ( !prime[ i ] ) {
			if ( !check( A, i ) ) {
				printf( "%d\n", i );
				break;
			}
		}
	}
}
