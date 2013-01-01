#include <cstdio>

using namespace std;

struct bignum {
	int data[ 1000 ];
	int len;
};

void init( bignum &a ) {
	for ( int i = 0; i < 1000; ++i ) {
		a.data[ i ] = 0;
	}
	a.len = 0;
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
		sum = sum + rem;
		rem = sum / 10;
		sum = sum % 10;
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

int main() {
	FILE *fin = fopen( "prob13.in", "r" );
	bignum a, b;
	char c;
	init( a );
	init( b );
	int i, j;

	for ( i = 0; i < 100; ++i ) {
		for ( j = 950; j <= 999; ++j ) {
			fscanf( fin, "%c", &c );
			b.data[ j ] = c - '0';
			b.len = 50;
		}
		a = add( b, a );
		init( b );
	}
	printBignum( a );
}
