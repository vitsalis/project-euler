#include <cstdio>

using namespace std;

int max;
int find[ 1000001 ];

int check( int num ) {
	int i, count = 0, j;
	int sum = 0, m = 0;
	for ( i = 0; i < max && find[ i ] <= num; ++i ) {
		sum += find[ i ];
		for ( j = i + 1; j < max && find[ j ] <= num; ++j ) {
			sum += find[ j ];
			++count;
			if ( sum > num ) {
				break;
			}
			if ( sum == num ) {
				if ( count > m ) {
					 m = count;
				}
				break;
			}
		}
		sum = 0;
		count = 0;
	}
	return m;
}

int main() {
	bool prime[ 1000001 ];
	int i, j;
	for ( i = 0; i <= 1000000; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i <= 1000000; ++i ) {
		for ( j = 2 * i; j <= 1000000; j += i ) {
			if ( j % i == 0 ) {
				prime[ j ] = false;
			}
		}
	}
	j = 0;
	for ( i = 2; i <= 1000000; ++i ) {
		if ( prime[ i ] ) {
			find[ j ] = i;
			++j;
		}
	}
	max = j;
	int most = 0;
	int found, king;
	for ( i = 2; i <= 1000000; ++i ) {
		if ( prime[ i ] ) {
			if ( ( found = check( i ) ) > most ) {
				king = i;
				most = found;
			}
		}
	}
	printf( "%d\n", king );
	

	return 0;
}
