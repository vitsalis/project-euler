#include <cstdio>
#include <queue>
#include <stack>

using namespace std;
int main() {
	long long int array[ 21 ][ 21 ];
	int i, j;
	for ( i = 0; i <= 20; ++i ) {
		for ( j = 0; j <= 20; ++j ) {
			array[ i ][ j ] = 1;
		}
	}
	for ( i = 1; i <= 20; ++i ) {
		for ( j = 1; j <= 20; ++j ) {
			array[ i ][ j ] = array[ i - 1][ j ] + array[ i ][ j - 1 ];
		}
	}
	printf( "%lld\n", array[ 20 ][ 20 ] );
}
