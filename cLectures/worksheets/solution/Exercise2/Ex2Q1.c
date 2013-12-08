#include <stdio.h>

int quad_roots(double * A, double * roots);

int main(void)
{
	double A[3], roots[2];

	printf("Enter coefficients of Quadratic Equation a2*x*x + a1*x + a0 = 0\n"
	"in the order a2, a1, a0, separated by spaces:");
	scanf("%lf %lf %lf", A+2, A+1, A);

	switch(quad_roots(A, roots))
	{
	case -3:	//not an equation
		fprintf(stderr,"Not an equation\n");
		return -1;
	case -2:	//no meaningful solution
		fprintf(stderr,"no meaningful solution\n");
		return -1;
	case -1:	//linear
		printf("x = %f\n",roots[0]);
		break;
	case 0:		//2 real
		printf("x = %f\nx = %f\n",roots[0], roots[1]);
		break;
	case 1:		//complex conj
		printf("x = %f + i %f\nx = %f - i %f\n",roots[0],roots[1],roots[0],roots[1]);
		break;
	case 2:		//1 real
		printf("x = %f\n",roots[0]);
		break;
	default:	//Something is really wrong
		fprintf(stderr,"Unknown Equation Type\n");
		return -1;
	}
	return 0;
}