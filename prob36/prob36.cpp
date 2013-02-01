#include <cstdio>
#include <string>

using namespace std;

bool rev( int num ) {
	int reved = num;
	int save = 0;
	int k = 1;
	while ( reved > 0 ) {
		save = ( save * 10 ) + ( reved % 10 );
		reved /= 10;
	}
	if ( num == save ) {
		return true;
	}
	return false;
}

string inttobin( int num )
{
        string bin;
        while ( num > 0 ) {
                bin += ( num % 2 + '0');
                num /= 2;
        }
        return bin;
}

bool strrev( string bin ) {
	int beg = 0;
	while ( bin[ beg ] == 0 ) {
		++beg;
	}
	int end = bin.length();
	string pal;
	int i, j = 0;
	for ( i = end - 1; i >= beg; --i, ++j ) {
		pal[ j ] = bin[ i ];
	}

	for ( i = beg, j = 0; i < end; ++i, ++j ) {
		if ( bin[ i ] != pal[ j ] ) {
			return false;
		}
	}
	return true;
}


int main() {
	int i, count = 0;
	long long int sum = 0;
	string pal;

	for ( i = 1; i <= 1000000; ++i ) {
		if ( rev( i ) ) {
			pal = inttobin( i );
			if ( strrev( pal ) ) {
				sum += i;
			}
		}
	}
	printf( "%lld\n", sum );
}
