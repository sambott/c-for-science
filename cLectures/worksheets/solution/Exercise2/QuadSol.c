#include <stdio.h>
#include <math.h>

#define MY_EPSILON 1e-15

int quad_roots(double * A, double * roots)
{
	if (fabs(A[2]) < MY_EPSILON)
	{
		if (fabs(A[1]) < MY_EPSILON)
		{
			if (fabs(A[0]) < MY_EPSILON)
			{
				//No meaningful sol
				return -2;
			}
			else
			{
				//Not an equation
				return -3;
			}
		}
		else
		{
			//linear
			roots[0] = -A[0]/A[1];
			return -1;
		}
	}
	else
	{
		//quadratic
		if (fabs(A[0]) < MY_EPSILON)
		{
			//one root is 0
			roots[0] = 0;
			if (fabs(A[1]) < MY_EPSILON)
			{
				//so is the other
				roots[1] = 0;
				return 2;
			}
			else
			{
				roots[1] = -A[1]/A[2];
				return 0;
			}
		}
		else
		{
			if (fabs(A[1]) < MY_EPSILON)
			{
				if (A[0] * A[2] < 0)
				{
					// one +- real
					roots[0] = sqrt(-A[0]/A[2]);
					roots[1] = -roots[0];
					return 0;
				}
				else
				{
					// one imaginary
					roots[0] = 0;
					roots[1] = sqrt(A[0]/A[2]);
					return 1;
				}
			}
			//all A[x] are positive...
			//store this here for a mo
			roots[0] = A[1]*A[1] - 4.*A[2]*A[0];
			if (fabs(roots[0]) < MY_EPSILON)
			{
				//one real
				roots[0] = -A[1] / (2. * A[2]);
				roots[1] = roots[0];
				return 2;
			}
			else if (roots[0] > 0)
			{
				//two real
				if (A[1] > 0)
				{
					roots[1] = (-1. * (A[1] + sqrt(roots[0]))) / (2. * A[2] );
				}
				else
				{
					roots[1] = ((-1. * A[1]) + sqrt(roots[0])) / (2. * A[2] );
				}
				roots[0] = A[0] / (A[2] * roots[1]);

				return 0;
			}
			else
			{
				//complex conjugates
				roots[1] = sqrt(-roots[0]) / (2. * A[2]);
				roots[0] = -A[1] / (2. * A[2]);
				return 1;
			}
		}
	}
}