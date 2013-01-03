#include <cstdio>

using namespace std;

int main () {

	long long int num = 600851475143;
	int i, j;
	bool prime[ 1000001 ];

	for ( i = 2; i <= 1000000; ++i ) {
		prime[ i ] = true; 
	}
	for ( i = 2; i <= 1000000; ++i ) {
		for ( j = i * 2; j <= 1000000; j += i ) {
			if ( j % i == 0 ) {
				prime[ j ] = false;
			}
		}
	}
	int pos = 0;
	for ( i = 2; i <= 1000000; ++i ) {
		if ( prime[ i ] ) {
			if ( num % i == 0 ) {
				pos = i;
			}
		}
	}
	printf( "%d\n", pos );
	return 0;
}
