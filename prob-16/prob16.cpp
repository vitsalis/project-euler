#include <cstdio>

using namespace std;

struct bignum {
	int data[ 1000 ];
	int len;
};

bignum makeBignum( long long int num ) {
	int k = 10, n = 1, len = 0;
	bignum a;

	if ( num == 0 ) {
		a.data[ 999 ] = 0;
		a.len = 1;
		return a;
	}
	int i;

	for ( i = 999; num != 0; --i ) {
		a.data[ i ] = num % 10;
		++len;
		num = num / 10;
	}
	a.len = len;
	return a;
}

void init( bignum &a ) {
	a.len = 0;
	for ( int i = 0; i < 999; ++i ) {
		a.data[ i ] = 0;
	}
}

bignum add( bignum a, bignum b ) {
	bignum c;
	int max;
	if ( a.len > b.len ) {
		max = a.len;
	}
	else {
		max = b.len;
	}
	int i;
	int sum, rem = 0, len = 0;
	for ( i = 999; i >= 1000 - max; --i ) {
		c.data[ i ] = 0;
		sum = a.data[ i ] + b.data[ i ];
		sum += rem;
		rem = sum / 10;
		sum %= 10;
		c.data[ i ] += sum;
		++len;
	}
	if ( rem != 0 ) {
		++len;
		c.data[ i ] = rem;
	}
	c.len = len;
	return c;
}

void printSum( bignum a ) {
	int sum = 0;
	for ( int i = 0; i < 1000; ++i ) {
		sum += a.data[ i ];
	}
	printf( "%d\n", sum );
}

int main() {
	bignum a;
	init( a );
	a = makeBignum( 2 );
	for ( int i = 0; i < 999; ++i ) {
		a = add( a, a );
	}
	printSum( a );

	return 0;
}
