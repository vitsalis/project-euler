#include <cstdio>
#include <string>

using namespace std;

int main() {
	freopen( "prob42.in", "r", stdin );
	char ab[ 27 ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string names[ 2000 ];
	bool triangle[ 100000 ];
	char s[ 400 ];
	int i, j, k;
	for ( i = 0; i <= 1785; ++i ) {
		scanf( "%s", s );
		names[ i ] = s;
	}
	int n = 1, tri;
	for ( i = 0; i < 100000; ++i ) {
		triangle[ i ] = false;
	}
	tri = ( n * ( n + 1 ) ) / 2;
	++n;
	while ( tri < 100000 ) {
		triangle[ tri ] = true;
		++n; 
		tri = ( n * ( n + 1 ) ) / 2;
	}
	int sum, count = 0;
	for ( i = 0; i <= 1785; ++i ) {
		for ( j = 0; j < names[ i ].length(); ++j ) {
			for ( k = 0; k < 26; ++k ) {
				if ( names[ i ][ j ] == ab[ k ] ) {
					sum += k + 1;
					break;
				}
			}
		}
		if ( sum < 100000 && triangle[ sum ] ) {
			++count;
		}
		sum = 0;
	}
	printf( "%d\n", count );

	return 0;
}
