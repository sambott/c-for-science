#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	FILE * fout;
	char filename[1024];
	time_t tn;

	time(&tn);
	sprintf(filename, "mydate-%d.txt", tn);

	fout = fopen(filename, "w");
	if (!fout)
	{
		fprintf(stderr, "Unable to open output file");
		return -1;
	}

	fprintf(fout, "This should be in the file.");
	fclose(fout);

	printf("Done!\n");

	return 0;
}