#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

map< int, bool > prime;

bool trunc( int num, int len ) {
	int copy = num / 10;

	while ( copy > 0 ) {
		if ( !prime[ copy ] ) {
			return false;
		}
		copy /= 10;
	}
	int k = pow( 10, len - 1 );
	copy = num % k;
	k /= 10;
	while ( k > 0 ) {
		if ( !prime[ copy ] ) {
			return false;
		}
		copy = copy % k;
		k /= 10;
	}
	return true;
}

int main() {
	int i, j;
	for ( i = 0; i <= 1000000; ++i ) {
		prime[ i ] = true;
	}
	prime[ 0 ] = false;
	prime[ 1 ] = false;
	for ( i = 2; i <= 1000000; ++i ) {
		for ( j = 2 * i; j <= 1000000; j += i ) {
			prime[ j ] = false;
		}
	}
	int count = 0;
	int sum = 0, len = 2, k = 100;
	for ( i = 11; i <= 1000000; ++i ) {
		if ( prime[ i ] ) {
			if ( trunc( i, len ) ) {
				sum += i;
				++count;
			}
		}
		if ( i / k > 0 ) {
			++len;
			k *= 10;
		}
		if ( count == 11 ) {
			break;
		}
	}
	printf( "%d %d\n", sum, count );
}
