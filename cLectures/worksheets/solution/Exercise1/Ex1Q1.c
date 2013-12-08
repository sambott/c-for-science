#include <stdio.h>
#include <string.h>

int main(void)
{
	char * MyChars = " \n\t\b\f\\\"\'";
	unsigned int i;
	for (i = 0; i < strlen(MyChars); i++)
	{
		printf("Hello%cWorld\n", MyChars[i]);
	}
	return 0;
}