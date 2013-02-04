#include <cstdio>

using namespace std;

struct limit {
	int x;
	int y;
};

int main() {
	int spiral[ 1001 ][ 1001 ];
	limit limits;
	limits.x = 1, limits.y = 1;
	spiral[ 500 ][ 500 ] = 1;
	int i, j;
	bool visited[ 1001 ][ 1001 ];
	for ( i = 0; i <= 1000; ++i ) {
		for ( j = 0; j <= 1000; ++j ) {
			visited[ i ][ j ] = false;
			spiral[ i ][ j ] = 0;
		}
	}
	visited[ 500 ][ 500 ] = true;
	i = 500;
	j = 500;
	int count = 0;
	int end = 8;
	int center = 500;
	int num = 1;
	
	while ( num <= 1001 * 1001 ) {
		visited[ i ][ j ] = true;
		if ( j + 1 <= center + limits.y && !visited[ i ][ j + 1 ] ) {
			spiral[ i ][ ++j ] = num + 1;
			++num;
			++count;
		}
		else if ( i + 1 <= center + limits.x &&  !visited[ i + 1 ][ j ] ) {
			spiral[ ++i ][ j ] = num + 1;
			num += 1;
			++count;
		}
		else if ( j - 1 >= center - limits.y && !visited[ i ][ j - 1 ] ) {
			spiral[ i ][ --j ] = num + 1;
			num += 1;
			++count;
		}
		else if ( i - 1 >= center - limits.x && !visited[ i - 1 ][ j ] ) {
			spiral[ --i ][ j ] = num + 1;
			num += 1;
			++count;
		}
		else {
			printf( "%d %d %d %d %d\n", spiral[ i ][ j ], i, j, limits.x, limits.y );
			break;
		}
		if ( count == end ) {
			end += 8;
			limits.x += 1;
			limits.y += 1;
			count = 0;
		}
	}
	long long int sum = 0;
	i = 0;
	j = 0;
	while ( i <= 1000 ) {
		sum += spiral[ i ][ j ];
		++i;
		++j;
	}
	printf( "%lld\n", sum );
	i = 1000, j = 0;
	while ( i >= 0 ) {
		sum += spiral[ i ][ j ];
		--i;
		++j;
	}
	printf( "%lld\n", sum + 1 );
	return 0;
}
