#include <stdio.h>

int main()
{
	int input;

	printf("Please enter [-1, 0 or 1]:");
	scanf("%d", &input);

	switch(input)
	{
	case -1:
		printf("first choice entered\n");
		break;

	case 0:
		printf("second choice entered\n");
		break;

	case 1:
		printf("last choice entered\n");
		break;

	default:
		printf("Invalid input!\n");
	}

	printf("Out of switch statement\n");

	return 0;
}