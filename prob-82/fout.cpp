#include <cstdio>
#include <cctype>

using namespace std;

int main() {
	freopen( "in.in", "r", stdin );
	freopen( "prob82.in", "w", stdout );
	char c;
	while ( c != '.' ) {
		scanf( "%c", &c );
		if ( c == ',' ) {
			printf( " " );
		}
		else {
			printf( "%c", c );
		}
	}
	return 0;
}
