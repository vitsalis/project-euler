#include <cstdio>

using namespace std;

int main() {
	freopen( "prob67.in", "r", stdin );
	int array[ 101 ][ 101 ];
	int dist[ 101 ][ 101 ];
	int i, len = 1, l, j, count = 0;
	for ( i = 1; i <= 100; ++i ) {
		for ( j = 1; j <= len; ++j ) {
			scanf( "%d", array[ i ] + j );
			dist[ i ][ j ] = 0;
			++count;
		}
		++len;
	}
	len = 2;
	dist[ 1 ][ 1 ] = array[ 1 ][ 1 ];
	for ( i = 1; i <= 99; ++i ) {
		for ( j = 1; j < len; ++j ) {
			if ( dist[ i ][ j ] + array[ i + 1 ][ j ] > dist[ i + 1 ][ j ] ) {
				dist[ i + 1 ][ j ] = dist[ i ][ j ] + array[ i + 1 ][ j ];
			}
			if ( dist[ i ][ j ] + array[ i + 1 ][ j + 1 ] > dist[ i + 1 ][ j + 1 ] ) {
				dist[ i + 1 ][ j + 1 ] = dist[ i ][ j ] + array[ i + 1 ][ j + 1 ];
			}
		}
		++len;
	}		
	long long int max = 0;
	for ( j = 1; j <= 100; ++j ) {
		if ( dist[ 100 ][ j ] > max ) {
			max = dist[ 100 ][ j ];
		}
	}
	printf( "%lld\n", max );
	return 0;
}
