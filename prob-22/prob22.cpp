#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

bool operator <( string a, string b ) {
	char s1[ 100 ], s2[ 100 ];
	int len1 = a.length();
	int len2 = b.length();
	strcpy( s1, a.data() );
	strcpy( s2, b.data() );
	if ( lexicographical_compare( s1, s1 + len1, s2, s2 + len2 ) ) {
		return true;
	}
	return false;
}

int main() {
	freopen( "prob22.in", "r", stdin );
	char s[ 100 ];
	int i;
	string names[ 5200 ];

	for ( i = 0; i < 5164; ++i ) {
		scanf( "%s", s );
		names[ i ] = s;
	}
	sort( names, names + 5164 );
	long long int sum = 0;
	int j, k;
	int mult = 0;
	char ab[ 27 ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for ( i = 0; i <= 5163; ++i ) {
		mult = 0;
		for ( j = 0; j < names[ i ].length(); ++j ) {
			for ( k = 0; k < 26; ++k ) {
				if ( names[ i ][ j ] == ab[ k ] ) {
					mult += k + 1;
					break;
				}
			}
		}
		sum = sum + ( mult * ( i ) );
	}
	printf( "%lld\n", sum );
	return 0;
}
