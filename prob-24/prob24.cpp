#include <cstdio>

using namespace std;

bool lexPerm( long long int num ) {
	bool nums[ 10 ];
	int i;
	for ( i = 0; i <= 9; ++i ) {
		nums[ i ] = false;
	}

	while ( num > 0 ) {
		if ( !nums[ num % 10 ] ) {
			nums[ num % 10 ] = true;
		}
		else {
			return false;
		}
		num /= 10;
	}
	for ( i = 1; i <= 9; ++i ) {
		if ( !nums[ i ] ) {
			return false;
		}
	}
	return true;
}

int main() {
	long long int num;
	int count = 0;

	if ( lexPerm( 123456789 ) ) {
		printf( "0\n" );
	}

	for ( num = 123456789; num < 9999999999; num += 9 ) {
		if ( lexPerm( num ) ) {
			++count;
		}
		if ( count == 1000000 ) {
			printf( "%lld\n", num );
			break;
		}
	}
	printf( "%d\n", count );

	return 0;
}
