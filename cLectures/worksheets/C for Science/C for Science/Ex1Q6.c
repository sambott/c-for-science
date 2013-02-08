#include <stdio.h>
#include <math.h>

#define MY_EPSILON 1e-15

int main(void)
{
	double a0, a1, x;

	printf("Enter coefficients of Linear Equation a1*x + a0 = 0\n"
	"in the order a1, a0, separated by spaces:");
	scanf("%lf %lf", &a1, &a0);

	if (fabs(a1) < MY_EPSILON)
	{
		if (fabs(a0) < MY_EPSILON)
		{
			printf("No meaningful solution\n");
		}
		else
		{
			fprintf(stderr, "Not an Equation\n");
			return 1;
		}
	}
	else
	{
		x = -a0/a1;
		printf("x = %lf\n", x);
	}
	return 0;
}