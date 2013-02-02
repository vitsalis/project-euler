#include <cstdio>
#include <cctype>

using namespace std;

int main() {
	freopen( "in.in", "r", stdin );
	freopen( "prob22.in", "w", stdout );
	char c;
	while ( 1 ) {
		scanf( "%c", &c );
		if ( isalpha( c ) ) {
			printf( "%c", c );
		}
		else if ( c == ',' ) {
			printf( " " );
		}
		else if ( c == '.' ) {
			break;
		}
	}


	return 0;
}
