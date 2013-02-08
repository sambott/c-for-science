#include <stdio.h>
#include <math.h>

typedef double (* fx)(double x);


double F(double x)
{
	return x*x-2;
}

double dF(double x)
{
	return 2*x;
}


int Newton(double * x, fx f, fx df, int max_its, double tol)
{
	int i;
	double dfx, xn;
	for (i = 0; i < max_its; i++)
	{
		dfx = df(*x);
		if (fabs(dfx) < tol) break;
		xn = *x;
		*x -= f(*x) / df(*x);
		if (fabs(*x - xn) < tol) break;
	}
	return i;
}

int main(void)
{
	double init, tol;
	int maxit;

	printf("F(x) = x*x - 2 = 0");

	printf("\n\nNewton-Raphson Method\n\nEnter initial guess: ");
	scanf("%lf", &init);
	printf("\nEnter maximum iterations: ");
	scanf("%d", &maxit);
	printf("\nEnter algorithm tolerance: ");
	scanf("%lf", &tol);
	
	printf("\nUsing %d iterations, the root of F(x) = 0 has been calculated as:\n\n", Newton(&init, F, dF, maxit, tol));
	printf("x = %.12f\n\nThis has a residue of %.10g\n", init, F(init));
	return 0;
}