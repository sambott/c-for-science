#include <stdio.h>

void v3cross (double *, double *, double *);
void v3fprint (FILE *, double *);

int main(void)
{
	double a[3], b[3], c[3], ri[3], r[3];
	FILE * openedFile;
	
	printf("\nEnter the 3 components of vector a, separated by spaces:");
	scanf("%lf %lf %lf", a, a+1, a+2);
	printf("\nEnter the 3 components of vector b, separated by spaces:");
	scanf("%lf %lf %lf", b, b+1, b+2);
	printf("\nEnter the 3 components of vector c, separated by spaces:");
	scanf("%lf %lf %lf", c, c+1, c+2);

	openedFile = fopen("results1.txt", "w");
	if (!openedFile)
	{
		fprintf(stderr, "Could not open results1.txt");
		return -1;
	}

	fprintf(openedFile, "\nThe triple vector cross-product of a x (b x c) is:\n");
	v3cross(b,c,ri);
	v3cross(a,ri,r);
	v3fprint(openedFile,r);

	fclose(openedFile);

	openedFile = fopen("results2.txt", "w");
	if (!openedFile)
	{
		fprintf(stderr, "Could not open results2.txt");
		return -1;
	}

	fprintf(openedFile, "\nThe triple vector cross-product of (a x b) x c is:\n");
	v3cross(a,b,ri);
	v3cross(ri,c,r);
	v3fprint(openedFile,r);

	fclose(openedFile);

	return 0;
}