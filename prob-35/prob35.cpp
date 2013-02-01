#include <cstdio>
#include <cmath>

using namespace std;

void rev( int &num, int len ) {
	int rem = num % 10;
	num = num / 10;
	rem = rem * ( pow( 10, len - 1 ) );
	num += rem;
}

int main() {
	bool prime[ 1000001 ];
	int i, j;
	for ( i = 0; i <= 1000000; ++i ) {
		prime[ i ] = true;
	}
	prime[ 0 ] = false;
	prime[ 1 ] = false;
	for ( i = 2; i < 1000000; ++i ) {
		for ( j = 2 * i; j < 1000000; j += i ) {
			if ( j % i == 0 ) {
				prime[ j ] = false;
			}
		}
	}
	int count = 0;
	int len = 1, k = 10;
	for ( i = 2; i < 1000000; ++i ) {
		j = 0;
		if ( prime[ i ] ) {
			j = 0;
			int num = i;
			while ( j < len ) {
				rev( num, len );
				if ( !prime[ num ] ){
					break;
				}
				++j;
			}
		}
		if ( j == len ) {
			++count;
		}
		if ( i / k > 0 ) {
			k *= 10;
			++len;
		}
	}
	printf( "%d\n", count );
	return 0;
}
