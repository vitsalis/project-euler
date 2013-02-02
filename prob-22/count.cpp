#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	freopen( "prob22.in", "r", stdin );
	char s[ 100 ];
	char m[ 10 ] = "ALONSO";
	int count = 0;
	while ( 1 ) {
		scanf( "%s", s );
		if ( strcmp( s, m ) == 0 ) {
			++count;
			break;
		}
		++count;
	}
	printf( "%d\n", count );

	return 0;
}
