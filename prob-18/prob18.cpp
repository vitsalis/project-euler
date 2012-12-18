#include <cstdio>
#include <cmath>

using namespace std;

int findSum( int multarray[][15], int, int );

int main() {
	FILE *fin = fopen( "prob18.in", "r" );
	int count = 0;
	int triangle[ 15 ][ 15 ];
	int i, j, act = 0;

	for ( i = 0; i < 15; ++i ) {
		for ( j = 0; j < 15; ++j; ) {
			if ( j == i + 1 ) {
				act = 1;
			}
			if ( act == 0 ) {
				fscanf( fin, "%d", &triangle[ i ][ j ] );
			}
			else {
				triangle[ i ][ j ] = 0;
			}
		}
		act = 0;
	}
	int sum = 0;

	sum = findSum( triangle, 0, 0 );
	printf( "%d\n", sum );
}

int findSum( int triangle[][15], int pos, int row ) {
	if ( row == 14 ) {
		return triangle[ 14 ][ pos ];
	}
	int i = row, j = pos;
	int sum1 = triangle[ row ][ pos ], sum2 = triangle[ row ][ pos ];

	sum1 += FindSum( triangle, j, i + 1 );
	sum2 += FindSum( triangle, j + 1, i + 1 );

	return max( sum1, sum2);
}
