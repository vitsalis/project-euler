#include <cstdio>

using namespace std;

int divSum( int num ) {
	int i, sum = 0;
	for ( i = 1; i <= num / 2; ++i ) {
		if ( num % i == 0 ) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int num[ 10001 ];
	int i;
	visited[ 0 ] = false;
	for ( i = 1; i <= 10000; ++i ) {
		num[ i ] = divSum( i );
	}

	int sum = 0;
	for ( i = 1; i <= 10000; ++i ) {
		if ( num[ i ] <= 10000 ) {
			if ( num[ num[ i ] ] == i && num[ i ] != i ) {
				sum += i;
			}
		}
	}
	printf( "%d\n", sum );

	return 0;
}
