#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int x;
	int y;
	int w;
};

bool operator <( edge a, edge b ) {
	return a.w < b.w;
}

long long int sum = 0;

void dijkstra( int array[][ 80 ] ) {
	int dist[ 80 ][ 80 ];
	int i, j;
	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			dist[ i ][ j ] = 10000000;
		}
	}
	dist[ 0 ][ 0 ] = 0;
	priority_queue< edge > q;
	q.push( ( edge ){ 0, 0, array[ 0 ][ 0 ] } );
	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();
		int x = p.x, y = p.y;
		if ( x + 1 < 80 && dist[ x ][ y ] + array[ x + 1 ][ y ] < dist[ x + 1 ][ y ] ) {
			dist[ x + 1 ][ y ] = dist[ x ][ y ] + array[ x + 1 ][ y ];
			q.push( ( edge ){ x + 1, y, array[ x + 1 ][ y ] } );
		}
		if ( y + 1 < 80 && dist[ x ][ y ] + array[ x ][ y + 1 ] < dist[ x ][ y + 1 ] ) {
			dist[ x ][ y + 1 ] = dist[ x ][ y ] + array[ x ][ y + 1 ];
			q.push( ( edge ){ x, y + 1, array[ x ][ y + 1 ] } );
		}
	}
	printf( "%d\n", dist[ 79 ][ 79 ] + array[ 0 ][ 0 ] );
}

int main() {
	freopen( "prob81.in", "r", stdin );
	int i, j, w;
	int pos;
	int array[ 80 ][ 80 ];
	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			scanf( "%d", &w );
			array[ i ][ j ] = w;
		} 
	}
	dijkstra( array );
	printf( "%lld\n", sum );
}
