#include <cstdio>

using namespace std;

int divCount( long long int num ) {
	int i, count = 0;

	for ( i = 1; i <= num / 2; ++i ) {
		if ( num % i == 0 ) {
			++count;
		}
	}
	return count;
}

int main() {
	long long int num = 1;
	int add = 2;

	while ( divCount( num ) < 500 ) {
		num += add;
		++add;
	}

	printf( "%lld\n", num );
}
