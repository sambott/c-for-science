#include <math.h>
#define MY_EPSILON 1e-15

int quad_roots(double * A, double * roots);

int cubic_roots(double * a, double * roots)
{
	double q, r, q3, r2, tmpval, A[3];

	if (fabs(a[0]) < MY_EPSILON)
	{
		//one root = 0
		if (fabs(a[1]) < MY_EPSILON)
		{
			//two roots = 0
			if (fabs(a[2]) < MY_EPSILON)
			{
				//all roots = 0
				roots[0] = 0;
				roots[1] = 0;
				roots[2] = 0;
				return 0;
			}
			//rest is linear
			roots[0] = -a[2];
			roots[1] = 0;
			roots[2] = 0;
			return 0;
		}
		//rest is quadratic
		roots[0] = 0;
		A[2] = 1.;
		A[1] = a[2];
		A[0] = a[1];
		return quad_roots(A, roots+1);
	}

	//can't simplyfy to lower order polynomial
	q = (a[2]*a[2] - 3.*a[1]) / 9.;
	q3 = q*q*q;
	r = (2.*a[2]*a[2]*a[2] - 9.*a[1]*a[2] + 27.*a[0]) / 54.;
	r2 = r*r;

/*START - OPTIONAL SIMPLE ROOTS FROM Q & R - remove this --> */
	if ((fabs(r) < MY_EPSILON) && (fabs(q) < MY_EPSILON))
	{
		roots[0] = -a[2] / 3.;
		roots[1] = -a[2] / 3.;
		roots[2] = -a[2] / 3.;
		return 3;
	}
	else if (fabs(r2 - q3) < MY_EPSILON)
	{
		tmpval = sqrt(q);
		if (r > 0)
		{
			roots[0] = -2. * tmpval - a[2] / 3.;
			roots[1] = tmpval - a[2] / 3.;
			roots[2] = roots[1];
		}
		else
		{
			roots[0] = 2. * tmpval - a[2] / 3.;
			roots[1] = - tmpval - a[2] / 3.;
			roots[2] = roots[1];
		}
		return 2;
	}
	else
/*END - OPTIONAL SIMPLE ROOTS FROM Q & R*/

	if (q3 - r2 < 0)
	{
		//two complex
		tmpval = pow(sqrt(r2 - q3) + fabs(r),(1./3.));
		roots[0] = tmpval + q / (tmpval);
		if (r>=0)
		{
			roots[0] *= -1;
		}
		roots[0] -= a[2]/3.;
	}
	else
	{
		//3 real
		roots[0] = -2 * sqrt(q) * cos(acos(r/sqrt(q3))/3.) - a[2] / 3.;
	}

	A[2] = 1;
	A[1] = a[2] + roots[0];
	A[0] = -a[0] / roots[0];
	return quad_roots(A,roots+1);
}
