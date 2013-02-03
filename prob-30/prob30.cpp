#include <cstdio>
#include <cmath>

using namespace std;

long long int powDigitSum( int num ) {
	long long int sum = 0;

	while ( num > 0 ) {
		if ( num % 10 != 0 ) {
			sum = sum + ( pow( num % 10, 5 ) );
		}
		num /= 10;
	}

	return sum;
}

int main() {
	int len = 1, k = 10, curr = 2;
	long long int sum = 0;

	while ( 1 ) {
		if ( len * pow( 9, 5 ) < curr ) {
			break;
		}
		if ( curr == powDigitSum( curr ) ) {
			sum += curr;
		}
		++curr;
		if ( curr / k > 0 ) {
			k *= 10;
			++len;
		}
	}

	printf( "%lld\n", sum );

	return 0;
}
