#include <stdio.h>

double v3dot (double * a, double * b)
{
	return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}

void v3cross (double * a, double * b, double * r)
{
	r[0] = a[1]*b[2] - a[2]*b[1];
	r[1] = a[2]*b[0] - a[0]*b[2];
	r[2] = a[0]*b[1] - a[1]*b[0];
}

void v3crosscross (double * a, double * b, double * c, double * r)
{
	double dac, dab;
	dac = v3dot(a,c);
	dab = v3dot(a,b);
	r[0] = dac*b[0] - dab*c[0];
	r[1] = dac*b[1] - dab*c[1];
	r[2] = dac*b[2] - dab*c[2];
}

void v3fprint (FILE * str, double * a)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		fprintf(str, "( %5g )\n", *(a+i));
	}
}