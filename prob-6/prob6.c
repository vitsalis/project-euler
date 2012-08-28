#include <stdio.h>

int square(int );
int main(){

	int tot1, tot2, dif, num1, num2;
	num1 = num2 = tot1 = tot2 = dif = 0;
	while( num1 <= 100 ){
		tot1 += square( num1 );
		++num1;
	}
	
	while( num2 <= 100 ){
		tot2 += num2;
		++num2;
	}
	tot2 = square( tot2 );

	dif = tot2 - tot1;
	printf( "%d\n", dif );
	return 0;
}

int square(int i)
{
	i = i * i;
	return i;
}
