#include <cstdio>
#include <queue>

using namespace std;

struct cord {
	int x;
	int y;
};

bool check( int pos, int pdist, int nedist, int next ) {
	if ( pos >= 80 || pos < 0 ) {
		return false;
	}
	if ( pdist + nedist < next ) return true;
	return false;
}

void dijkstra( int array[][ 80 ] ) {
	long long int dist[ 80 ][ 80 ];
	int i, j;

	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			dist[ i ][ j ] = 1000000000;
		}
	}

	queue< cord > q;
	q.push( ( cord ) { 0, 0 } );

	dist[ 0 ][ 0 ] = array[ 0 ][ 0 ];

	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		for ( i = p.x - 1; i < p.x + 2; ++i ) {
			for ( j = p.y - 1; j < p.y + 2; ++j ) {
				if ( i == p.x && j == p.y ) continue;
				if ( i == p.x + 1 && ( j == p.y + 1 || j == p.y - 1 ) ) continue;
				if ( i == p.x - 1 && ( j == p.y - 1 || j == p.y + 1 ) ) continue;
				if ( i != p.x ) {
					if ( check( i, dist[ p.x ][ p.y ], array[ i ][ j ], dist[ i ][ j ] ) ) {
						q.push( ( cord ) { i, j } );
						dist[ i ][ j ] = dist[ p.x ][ p.y ] + array[ i ][ j ];
					}
				}
				else {
					if ( check( j, dist[ p.x ][ p.y ], array[ i ][ j ], dist[ i ][ j ] ) ) {
						q.push( ( cord ) { i, j } );
						dist[ i ][ j ] = dist[ p.x ][ p.y ] + array[ i ][ j ];
					}
				}
			}
		}
	}

	printf( "%lld\n", dist[ 79 ][ 79 ] );

}

int main() {
	freopen( "prob83.in", "r", stdin );
	int array[ 80 ][ 80 ];
	int i, j;

	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			scanf( "%d", array[ i ] + j );
		}
	}

	dijkstra( array );

	return 0;
}
