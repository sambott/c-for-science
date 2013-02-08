#include <assert.h>

/*
 linearsolve returns: -1 invalid equation
                      0 answer stored in x
*/

int linearsolve(double R, double S,
				double * x)
{
	if (R == 0.0)
		return -1;

	*x = -S/R;
	return 0;
}