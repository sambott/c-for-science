#include <stdio.h>
int main(void)
{
	float x1=1.0e5, x2=3.1415926, x3, x4, x5, x6, X1=1.0e25, X2=3.0e10, X3, X4, X5, X6;
	x3 = x1 + x2;
	x4 = x1 * x2;
	x5 = x1 / x2;
	x6 = x2 / x1;
	X3 = X1 + X2;
	X4 = X1 * X2;
	X5 = X1 / X2;
	X6 = X2 / X1;
	printf("x3 - x6 = %f %f %f %f\n", x3, x4, x5, x6);
	printf("X3 - X6 = %f %f %f %f\n", X3, X4, X5, X6);
	return 0;
}