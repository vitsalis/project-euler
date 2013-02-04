#include <cstdio>

using namespace std;

int main() {
	freopen( "prob81.in", "r", stdin );
	int i, j, w;
	int dist[ 81 ][ 81 ];
	int array[ 80 ][ 80 ];
	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			scanf( "%d", &w );
			array[ i ][ j ] = w;
			dist[ i ][ j ] = 10000000;
		}
	}
	dist[ 0 ][ 0 ] = array[ 0 ][ 0 ];
	dist[ 80 ][ 80 ] = 0;
	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			if ( i - 1 >= 0 && j - 1 >= 0 ) {
				if ( dist[ i - 1 ][ j ] + array[ i ][ j ] < dist[ i ][ j ] ) {
					dist[ i ][ j ] = dist[ i - 1 ][ j ] + array[ i ][ j ];
				}
				if ( dist[ i ][ j - 1 ] + array[ i ][ j ] < dist[ i ][ j ] ) {
					dist[ i ][ j ] = dist[ i ][ j - 1 ] + array[ i ][ j ];
				}
			}
			else if ( i - 1 >= 0 ) {
				if ( dist[ i - 1 ][ j ] + array[ i ][ j ] < dist[ i ][ j ] ) {
					dist[ i ][ j ] = dist[ i - 1 ][ j ] + array[ i ][ j ];
				}
			}
			else if ( j - 1 >= 0 ) {
				if ( dist[ i ][ j - 1 ] + array[ i ][ j ] < dist[ i ][ j ] ) {
					dist[ i ][ j ] = dist[ i ][ j - 1 ] + array[ i ][ j ];
				}
			}
		}
	}
	printf( "%d\n", dist[ 79 ][ 79 ] );
	return 0;
}
