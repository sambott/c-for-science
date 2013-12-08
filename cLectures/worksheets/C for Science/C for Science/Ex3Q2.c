#include <stdio.h>

double v3dot (double *, double *);
void v3cross (double *, double *, double *);
void v3crosscross (double *, double *, double *, double *);
void v3fprint (FILE *, double *);

int main(void)
{
	double a[3], b[3], c[3], r[3];
	
	printf("\nEnter the 3 components of vector a, separated by spaces:");
	scanf("%lf %lf %lf", a, a+1, a+2);
	printf("\nEnter the 3 components of vector b, separated by spaces:");
	scanf("%lf %lf %lf", b, b+1, b+2);
	printf("\nEnter the 3 components of vector c, separated by spaces:");
	scanf("%lf %lf %lf", c, c+1, c+2);

	printf("\nThe scalar product of a and b is %f\n", v3dot(a,b));

	printf("\nThe vector products of a and b is:\n");
	v3cross(a, b, r);
	v3fprint(stdout, r);

	printf("\nThe triple vector cross-product of a, b and c is:\n");
	v3crosscross(a,b,c,r);
	v3fprint(stdout, r);

	return 0;
}