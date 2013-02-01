#include <cstdio>
#include <algorithm>

using namespace std;

struct bignum {
	int data[ 1000 ];
	int len;
};

void init( bignum &a ) {
	for ( int i = 0; i < 1000; ++i ) {
		a.data[ i ] = 0;
	}
}

void print( bignum a ) {
	for ( int i = 1000 - a.len; i < 1000; ++i ) {
		printf( "%d", a.data[ i ] );
	}
	printf( "\n" );
}

bignum add( bignum a, bignum b ) {
	bignum sum;
	init( sum );
	int suma = 0, len = 0, rem = 0, i;
	for ( i = 999; i > 1000 - max( a.len, b.len ); --i ) {
		suma = a.data[ i ] + b.data[ i ];
		sum.data[ i ] = suma % 10 + rem;
		rem = suma / 10;
		++len;
	}

	if ( rem != 0 ) {
		++len;
		sum.data[ i ] = rem;
	}
	sum.len = len;
	return sum;
}
int main() {
	bignum a, b;
	init( a );
	init( b );
	int lena, lenb;
	scanf( "%d%d", &lena, &lenb );
	a.len = lena;
	b.len = lenb;
	char t;

	for ( int i = 1000 - lena; i < 1000; ++i ) {
		scanf( "%c", &t );
		a.data[ i ] = t - '0';
	}
	for ( int i = 1000 - lenb; i < 1000; ++i ) {
		scanf( "%c", &t );
		b.data[ i ] = t - '0';
	}

	print( a );
	print( b );	
	bignum sum = add( a, b );
	print( sum );

	return 0;
}
