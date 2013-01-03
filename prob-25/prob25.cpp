#include <cstdio>
#include <cstring>

using namespace std;

struct bignum {
	int data[ 1500 ];
	int len;
};

void init( bignum &a ) {
	for ( int i = 0; i < 1000; ++i ) {
		a.data[ i ] = 0;
	}
	a.len = 0;
}

bignum makeBignum( long long int num ) {
	int k = 10, n = 1, len = 0;
	bignum a;

	if ( num == 0 ) {
		a.data[ 1499 ] = 0;
		a.len = 1;
		return a;
	}
	int i;

	for ( i = 1499; num != 0; --i ) {
		a.data[ i ] = num % 10;
		++len;
		num = num / 10;
	}
	a.len = len;
	return a;
}

bignum add( bignum a, bignum b ) {
	bignum c;
	int min, max;
	if ( a.len >= b.len ) {
		max = a.len;
	}
	else {
		max = b.len;
	}
	init( c );
	int sum, rem = 0, save, len = 0;
	int i;


	for ( i = 1499; i >= 1500 - max; --i ) {
		sum = a.data[ i ] + b.data[ i ];
		sum += rem;
		rem = sum / 10;
		sum %= 10;
		c.data[ i ] = sum;
		++len;
	}
	if ( rem != 0 ) {
		++len;
		c.data[ i ] += rem;
	}
	c.len = len;
	return c;
}

int main() {
	bignum a, b, c;
	int count = 1;

	init( a );
	init( b );
	init( c );

	a = makeBignum( 1 );

	while ( a.len < 1000 ) {
		c = a;
		a = add( b, a );
		b = c;
		++count;
	}
	printf( "%d\n", count );
}
