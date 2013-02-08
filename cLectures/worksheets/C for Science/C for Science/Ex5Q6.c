#include <stdio.h>
#include <math.h>
#include <gsl/gsl_sf_bessel.h>

typedef double (* fx)(double x);

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

	printf("\nF(x) = J_0(x)\nF'(x) = J_1(x)");

	printf("\n\nNewton-Raphson Method\n\nEnter initial guess: ");
	scanf("%lf", &init);
	printf("\nEnter maximum iterations: ");
	scanf("%d", &maxit);
	printf("\nEnter algorithm tolerance: ");
	scanf("%lf", &tol);
	
	printf("\nUsing %d iterations, the root of F(x) = 0 has been calculated as:\n\n", Newton(&init, gsl_sf_bessel_J0, gsl_sf_bessel_J1, maxit, tol));
	printf("x = %.12f\n\nThis has a residue of %.10g\n", init, gsl_sf_bessel_J0(init));
	return 0;
}