#include <stdio.h>
int main(void)
{
	int low = -40, high = 140, step = 2, c = low;
	float f;
	printf("low = %d, high = %d, step = %d\n\n%6s \t %6s\n",low,high,step,"c","f");
	while (c <= high)
	{
		f = 32.+9.*c/5.;
		printf("%6d \t %6.2f\n", c, f);
		c = c + step;
	}
	return 0;
}