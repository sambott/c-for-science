#include <stdio.h>
#include <float.h>

int main(void)
{
	double a = 1.0 + DBL_EPSILON;
	double b = (1.0 + DBL_EPSILON / 2.0) + DBL_EPSILON / 2.0;
	double c = 1.0 + (DBL_EPSILON / 2.0 + DBL_EPSILON / 2.0);

	printf("\na = %.17lf\nb = %.17lf\nc = %.17lf\n", a, b, c);

	return 0;
}