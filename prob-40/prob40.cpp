#include <cstdio>
#include <cmath>

using namespace std;

int length( int num ) {
	int count = 0;

	while ( num > 0 ) {
		num /= 10;
		++count;
	}
	return count;
}

int main() {
	int array[ 2000000 ];
	int n = 1, num = 1;

	int i = 1, len = 0, k;
	while ( i <= 1000000 ) {
		n = num;
		len = length( num );
		k = pow( 10, len - 1 );
		while ( len > 0 ) {
			array[ i ] = n / k;
			n = n % k;
			k /= 10;
			++i;
			--len;
		}
		++num;
	}
	int prod = array[ 1 ] * array[ 10 ] * array[ 100 ] * array[ 1000 ] * array[ 10000 ] * array[ 100000 ];
	printf( "%d\n", prod );
}
