#include <cstdio>
#include <algorithm>

using namespace std;

bool sameDig( int a, int b, int c ) {
	int A[ 5 ];
	int B[ 5 ];
	int C[ 5 ];
	int i = 0;
	while ( c > 0 ) {
		A[ i ] = a % 10;
		B[ i ] = b % 10;
		C[ i ] = c % 10;
		a /= 10;
		b /= 10;
		c /= 10;
		++i;
	}
	sort( A, A + 4 );
	sort( B, B + 4 );
	sort( C, C + 4 );
	i = 0;
	while ( i < 4 ) {
		if ( A[ i ] != B[ i ] || A[ i ] != C[ i ] ) return false;
		if ( B[ i ] != C[ i ] ) return false;
		++i;
	}
	return true;
}

int main() {
	bool prime[ 10001 ];
	int i, j, sum;
	for ( i = 2; i <= 10000; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i <= 10000; ++i ) {
		for ( j = 2 * i; j <= 10000; j += i ) {
			prime[ j ] = false;
		}
	}
	int diff;
	for ( i = 1000; i <= 10000; ++i ) {
		if ( prime[ i ] ) {
			for ( j = i + 1; j <= 10000; ++j ) {
				if ( prime[ j ] ) {
					diff = j - i;
					if ( i + ( 2 * diff ) <= 10000 && prime[ i + ( diff * 2 ) ] ) {
						if ( sameDig( i, i + diff, i + ( 2 * diff ) ) ) {
							printf( "%d%d%d\n", i, i + diff, i + ( 2 * diff ) );
						}
					}
				}	
			}
		}
	}

	return 0;
}
