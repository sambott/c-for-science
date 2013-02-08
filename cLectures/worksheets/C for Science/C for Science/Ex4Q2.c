#include "eratosthenes.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	int max_number;
	float ticks;
	char * PrimeNumbers;

	printf("\nMaximum number: ");
	scanf("%u",&max_number);

	PrimeNumbers = (char *) calloc(max_number % 16 == 0 ? max_number / 16 : 1 + max_number / 16, 1);
	if (!PrimeNumbers)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		return -1;
	}

	ticks = clock();

	findPrimes(PrimeNumbers, max_number);
	//printf("2\n");printPrimes(PrimeNumbers, max_number);

	printf("Found %u primes between 2 and %u in %g seconds\n",countPrimes(PrimeNumbers, max_number),max_number,(clock() - ticks)/CLOCKS_PER_SEC);

	free(PrimeNumbers);

	return 0;
}