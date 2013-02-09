#include <cstdio>
#include <queue>

using namespace std;

long long int m = 1000000000;

struct cord {
	int x;
	int y;
};

void dijkstra( int array[][ 80 ], int beg ) {
	long long int dist[ 80 ][ 80 ];
	bool visited[ 80 ][ 80 ];
	int i, j;
	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			dist[ i ][ j ] = 10000000000;
			visited[ i ][ j ] = false;
		}
	}
	queue< cord > q;
	q.push( ( cord ) { beg, 0 } );
	dist[ beg ][ 0 ] = array[ beg ][ 0 ];
	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		visited[ p.x ][ p.y ] = true;
		if ( p.x + 1 < 80 && dist[ p.x ][ p.y ] + array[ p.x + 1 ][ p.y ] < dist[ p.x + 1 ][ p.y ]  ) {
			dist[ p.x + 1 ][ p.y ] = dist[ p.x ][ p.y ] + array[ p.x + 1 ][ p.y ];
			q.push( ( cord ) { p.x + 1, p.y } );
		}
		if ( p.x - 1 >= 0 && dist[ p.x ][ p.y ] + array[ p.x - 1 ][ p.y ] < dist[ p.x - 1 ][ p.y ] ) {
			dist[ p.x - 1 ][ p.y ] = dist[ p.x ][ p.y ] + array[ p.x - 1 ][ p.y ];
			q.push( ( cord ) { p.x - 1, p.y } );
		}
		if ( p.y + 1 < 80 && dist[ p.x ][ p.y ] + array[ p.x ][ p.y + 1 ] < dist[ p.x ][ p.y + 1 ] ) {
			dist[ p.x ][ p.y + 1 ] = dist[ p.x ][ p.y ] + array[ p.x ][ p.y + 1 ];
			q.push( ( cord ) { p.x, p.y + 1 } );
		}
		
	}
	for ( i = 0; i < 80; ++i ) {
		if ( dist[ i ][ 79 ] < m ) {
			m = dist[ i ][ 79 ];
		}
	}
}

int main() {
	freopen( "prob82.in", "r", stdin );
	int array[ 80 ][ 80 ];
	int i, j;

	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			scanf( "%d", array[ i ] + j );
		}
	}

	for ( i = 0; i < 80; ++i ) {
		dijkstra( array, i );
	}
	printf( "%lld\n", m );

	return 0;
}
