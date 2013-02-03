#include <cstdio>

using namespace std;

int check( int num ) {
	int sum = 0;

	for ( int i = 1; i <= num / 2; ++i ) {
		if ( num % i == 0 ) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int i = 0, max, j;
	int num = 0;
	int abu[ 20000 ];
	for ( num = 1; num <= 28124; ++num ) {
		if ( check( num ) > num ) {
			abu[ i ] = num;
			++i;
		}
	}
	max = i;
	long long int sum = 0;
	bool found = false;
	for ( num = 1; num <= 28123; ++num ) {
		for ( i = 0; abu[ i ] <= num && i <= max; ++i ) {
			for ( j = 0; abu[ j ] <= num && j <= max; ++j ) {
				if ( num == abu[ i ] + abu[ j ] ) {
					found = true;
					break;
				}
			}
			if ( found ) break;
		}
		if ( !found ) {
			sum += num;
		}
		found = false;
	}
	printf( "%lld\n", sum );

}
