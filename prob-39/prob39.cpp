#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int p = 1;
	int i, j;
	int count = 0, m = 0, num = 0;

	while ( p <= 1000 ) {
		for ( i = 1; i < p; ++i ) {
			for ( j = i + 1; j < p; ++j ) {
				if ( p - ( i + j ) <= j || p - ( i + j ) <= i || j <= i ) {
					continue;
				}
				if ( p - ( i + j ) > 0 ) {
					if ( pow( i, 2 ) + pow( j, 2 ) == pow( p - ( i + j ), 2 ) ) {
						++count;
					}
				}
			}
		}
		if ( count > m ) {
			m = count;
			num = p;
		}
		count = 0;
		++p;
	}

	printf( "%d\n", num );

	return 0;
}
