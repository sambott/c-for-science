#include <stdio.h>

int main()
{
	int loop;

	for (loop = 0; loop < 10; loop++)
	{
		printf("\nloop = %d ", loop);

		if (loop % 2)
		{
			break; /* continue; */
		}

		printf("(even)");
	}
	
	return 0;
}