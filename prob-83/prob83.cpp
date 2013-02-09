#include <cstdio>
#include <queue>

using namespace std;

struct cord {
	int x;
	int y;
};

const int N = 80;
const long int INF = 100000000;

bool check( int i, int j, int pdist, int nedist, int next ) {
	if ( i >= N || i < 0 || j >= N || j < 0 ) {
		return false;
	}
	if ( pdist + nedist < next ) return true;
	return false;
}

void dijkstra( int array[][ 80 ] ) {
	long long int dist[ N ][ N ];
	int i, j;

	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			dist[ i ][ j ] = INF;
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
				if ( check( i, j, dist[ p.x ][ p.y ], array[ i ][ j ], dist[ i ][ j ] ) ) {
					q.push( ( cord ) { i, j } );
					dist[ i ][ j ] = dist[ p.x ][ p.y ] + array[ i ][ j ];
				}
			}
		}
	}

	printf( "%lld\n", dist[ N - 1 ][ N - 1 ] );

}

int main() {
	freopen( "prob83.in", "r", stdin );
	int array[ N ][ N ];
	int i, j;

	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < N; ++j ) {
			scanf( "%d", array[ i ] + j );
		}
	}

	dijkstra( array );

	return 0;
}
