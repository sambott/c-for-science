#include <stdio.h>
#include <stdlib.h>
#define PRIME_LIST_SIZE 10
#define NUM_TYPE unsigned int
#define BITS_PER_NUM (sizeof(NUM_TYPE)*8)

void findPrimes(NUM_TYPE * Prime_List, int max_num)
{
	int current_num = 3;
	NUM_TYPE Mask=1;

	while(current_num*current_num <= max_num)
	{
		int Pnum = current_num/(2 * BITS_PER_NUM);
		int Pbit = (current_num-Pnum * 2 * BITS_PER_NUM)/2;
		/* Current Number is prime so strike out multiples */
		if(~Prime_List[Pnum] & (Mask <<Pbit))
		{
			int strike = current_num * current_num;
			while(strike <= max_num)
            {
				int Snum = strike/(2*BITS_PER_NUM);
				int Sbit = (strike - Snum * 2 * BITS_PER_NUM)/2;
				Prime_List[Snum] |= (Mask << Sbit);
				strike += 2 * current_num;
			}			
		}
		current_num += 2;
	}
}

void printPrimes(NUM_TYPE * Prime_List, int max_num)
{
	int i;
	NUM_TYPE Mask=1;

	for(i=3;i<=max_num;i=i+2)
	{
		int Pnum=i/(2*BITS_PER_NUM);
		int Pbit=(i-Pnum*2*BITS_PER_NUM)/2;
		if(~Prime_List[Pnum] & (Mask <<Pbit))
			printf("%d\n",i);
	}
}

int main(void)
{
	NUM_TYPE *Prime_List;
	int max_num;
	Prime_List=(NUM_TYPE *)calloc(PRIME_LIST_SIZE,sizeof(NUM_TYPE));

	/* Scan list for primes and strike out multiples */
	max_num = 2 * BITS_PER_NUM * PRIME_LIST_SIZE - 1;
	printf("\n max_num = %d\n",max_num);

	findPrimes(Prime_List, max_num);
	printPrimes(Prime_List, max_num);

	return 0;
}
 