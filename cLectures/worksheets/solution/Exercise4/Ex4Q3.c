#include <stdio.h>

int quad_roots(double * A, double * roots);

int cubic_roots(double * a, double * roots);

int main(void)
{
	double A[3], roots[3];

	printf("Enter coefficients of the Reduced Cubic Equation x*x*x + a2*x*x + a1*x + a0 = 0\n"
	"in the order a2, a1, a0, separated by spaces:");
	scanf("%lf %lf %lf", A+2, A+1, A);

	switch(cubic_roots(A, roots))
	{
	case 0:		//3 real
		printf("x = %f\nx = %f\nx = %f\n",roots[0], roots[1], roots[2]);
		break;
	case 1:		//1 real, 1 complex conj pair
		printf("x = %f\nx = %f + i %f\nx = %f - i %f\n",roots[0],roots[1],roots[2],roots[1],roots[2]);
		break;
	case 2:		//2 real
		printf("x = %f\nx = %f\n",roots[0],roots[1]);
		break;
	case 3:		//1 real
		printf("x = %f\n",roots[0]);
		break;
	default:	//Something went wrong in Quad_Sol
		fprintf(stderr,"x=%f\nOther values of x could not be found from the remaining Quadratic.",roots[0]);
		return -1;
	}
	return 0;
}
