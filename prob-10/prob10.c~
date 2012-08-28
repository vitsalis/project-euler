#include <stdio.h>

main()
{
	int num, i;
	long long int sum;

	num = 2;
	i = 2;
	sum = 0;

	while(num < 2000000){
		if(num % i == 0.0){
			if(num == i){
				sum += num;
			}
			i = 2;
			num++;
		}
		else{
			i++;
		}
	}
	printf("%lld\n", sum);
}
