#include <cstdio>
#include <queue>
#include <cmath>

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
	return pdist + nedist < next;
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
		for ( i = -1; i < 2; ++i ) {
			for ( j = -1; j < 2; ++j ) {
				int xx = p.x + i, yy = p.y + j;
				if ( i * i + j * j == 1 ) {
					if ( check( xx, yy, dist[ p.x ][ p.y ], array[ xx ][ yy ], dist[ xx ][ yy ] ) ) {
						q.push( ( cord ) { xx, yy } );
						dist[ xx ][ yy ] = dist[ p.x ][ p.y ] + array[ xx ][ yy ];
					}
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
			scanf( "%d", &array[ i ][ j ] );
		}
	}

	dijkstra( array );

	return 0;
}
