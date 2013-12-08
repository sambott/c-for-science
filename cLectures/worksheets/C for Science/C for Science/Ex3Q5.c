#include <stdio.h>
#include <stdlib.h>

void printSqMatrix(double ** matrix, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++) printf("%f ", matrix[i][j]);
		printf("\n");
	}
}
void freeMatrix(double ** matrix)
{
	free(matrix[0]);
	free(matrix);
}

double ** matrixI(unsigned int n)
{
	double ** matrix;
	unsigned int i, j;

	matrix = (double **) malloc (n*sizeof(double *));
	if (!matrix) return NULL; /* failed */

	matrix[0] = (double *) malloc (n*n*sizeof(double));
	if (!matrix[0])
	{
		free(matrix); /* we don’t need matrix any more */
		return NULL; /* failed */
	}
	
	for (j = 0; j < n; j++) matrix[0][j] = (0 == j);

	for (i = 1; i < n; i++)
	{
		matrix[i] = matrix[i-1] + n;
		for (j = 0; j < n; j++)
			matrix[i][j] = (i == j);
	}

	return matrix;
}

int main(void)
{
	unsigned int n;
	double** I;
	
	printf("\nWhat size would you like I_n?\nn = ");
	scanf("%u",&n);

	I = matrixI(n);
	printSqMatrix(I,n);
	freeMatrix(I);

	return 0;
}