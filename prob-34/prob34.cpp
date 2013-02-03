#include <cstdio>

using namespace std;

int factorial( int num ) {
	if ( num == 0 ) {
		return 1;
	}
	int fact = 1;

	while ( num > 1 ) {
		fact = fact * num;
		--num;
	}
	return fact;
}

int factSum( int num ) {
	int sum = 0;

	while ( num > 0 ) {
		sum += factorial( num % 10 );
		num /= 10;
	}

	return sum;
}

int main() {
	int len = 1, curr = 3, fact = factorial( 9 ), k = 10;
	long long int sum = 0;

	while ( 1 ) {
		if ( curr > fact ) {
			break;
		}
		if ( factSum( curr ) == curr ) {
			sum += curr;
		}
		++curr;
		if ( curr / k > 0 ) {
			++len;
			k *= 10;
			fact = len * factorial( 9 );
		}
	}

	printf( "%lld\n", sum );

	return 0;
}
