#include <cstdio>

using namespace std;

struct bignum {
	int data[ 1000 ];
	int len;
};

void init( bignum &a ) {
	a.len = 0;
	for ( int i = 0; i < 1000; ++i ) {
		a.data[ i ] = 0;
	}
}

bignum makeBignum( long long int num, int pos ) {
	bignum a;
	init( a );
	if ( num == 0 ) {
		a.len = 1;
		a.data[ 999 ] = 0;
		return a;
	}
	int i;
	int len = 0;

	for ( i = 999 - pos; num != 0; --i ) {
		a.data[ i ] = num % 10;
		num = num / 10;
		++len;
	}
	a.len = len + pos;
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


	for ( i = 999; i >= 1000 - max; --i ) {
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

void printBignum( bignum a ) {
	for ( int i = 1000 - a.len; i < 1000; ++i ) {
		printf( "%d", a.data[ i ] );
	}
	printf( "\n" );
}

bignum mult( bignum a, bignum b ) {
	bignum c, d;
	init( c );
	init( d );
	int i, j, k = 0, n = 0;

	for ( i = 999; i >= 1000 - a.len; --i ) {
		for ( j = 999; j >= 1000 - b.len; --j, ++k ) {
			init( c );
			c = makeBignum( a.data[ i ] * b.data[ j ], k );
			if ( c.len == 1 && c.data[ 999 ] == 0 ) ;
			else {
				d = add( d, c );
			}
		}
		k = n + 1;
		n = k;
	}
	printf( "\n\n\n" );
	return d;
}

void printSum( bignum a ) {
	int sum = 0;
	for ( int i = 0; i < 1000; ++i ) {
		sum += a.data[ i ];
	}
	printf( "%d\n", sum );
}

int main() {
	bignum a, b;
	init( a );
	init( b );
	a = makeBignum( 100, 0 );
	for ( int i = 99; i > 1; --i ) {
		b = makeBignum( i, 0 );
		a = mult( a, b );
	}
	printSum( a );

	return 0;
}
