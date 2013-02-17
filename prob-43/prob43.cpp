#include <cstdio>
#include <map>

using namespace std;

int val( int array[], int i ) {
	int k = 1;
	int num = 0;
	while ( k <= 100 ) {
		num += ( array[ i-- ] * k );
		k *= 10;
	}
	return num;
}

bool check( long long int num ) {
	long long int save = num;
	int array[ 10 ];
	int i = 9;
	while ( save > 0 ) {
		array[ i-- ] = save % 10;
		save /= 10;
	}
	if ( val( array, 3 ) % 2 != 0 ) return false;
	if ( val( array, 4 ) % 3 != 0 ) return false;
	if ( val( array, 5 ) % 5 != 0 ) return false;
	if ( val( array, 6 ) % 7 != 0 ) return false;
	if ( val( array, 7 ) % 11 != 0 ) return false;
	if ( val( array, 8 ) % 13 != 0 ) return false;
	if ( val( array, 9 ) % 17 != 0 ) return false;
	return true;
}

bool panDigit( long long int num ) {
	bool visited[ 10 ];
	int i;
	for ( i = 0; i < 10; ++i ) {
		visited[ i ] = false;
	}

	while ( num > 0 ) {
		int n = num % 10;
		num /= 10;
		if ( visited[ n ] ) {
			return false;
		}
		visited[ n ] = true;
	}
	return true;
}

int main() {
	long long int num;
	long long int sum = 0;

	for ( num = 1234567890; num < 10000000000; ++num ) {
		if ( panDigit( num ) ) {
			if ( check( num ) ) {
				sum += num;
				printf( "%lld\n", sum );
			}
		}
	}
	printf( "%lld\n", sum );
}
