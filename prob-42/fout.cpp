#include <cstdio>
#include <cctype>

using namespace std;

int main() {
	freopen( "in.in", "r", stdin );
	freopen( "prob42.in", "w", stdout );
	char c;
	int count = 0;
	while ( 1 ) {
		scanf( "%c", &c );
		if ( isalpha( c ) ) {
			printf( "%c", c );
		}
		else if ( c == ',' ) {
			printf( " " );
			++count;
		}
		else if ( c == '.' ) {
			break;
		}
	}
	fprintf( stdout, "%d\n", count );

	return 0;
}
