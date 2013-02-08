#include <stdio.h>
#include "linearsolver.h"

int main()
{
	double A, B, x;
	int result;
	printf("Please enter A and B for Ax + B = 0\n");
	scanf("%lf %lf", &A, &B);

	result = linearsolve(A, B, &x);
	if (result == 0)
	{
		printf("x = %g\n", x);
	}
	else
		printf("Invalid equation");

	return 0;
}