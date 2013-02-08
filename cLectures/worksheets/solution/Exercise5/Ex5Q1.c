#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrix(double ** matrixA, double ** matrixB, double ** matrixC, int rowsA, int colsA, int colsB)
{
	int i,j,k;

#pragma omp parallel for private(j,k)
	for (i = 0; i < rowsA; i++)
		for (j = 0; j < colsB; j++)
		{
			matrixC[i][j] = 0;
			for (k = 0; k < colsA; k++)
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
		}
}

void randomMatrix(double ** matrix, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			matrix[i][j] = (double)rand()/RAND_MAX;
}

double ** allocMatrix(int rows, int cols)
{
	double ** matrix;
	int i;
	matrix = (double **) malloc (rows*sizeof(double *));
	if (!matrix) return NULL;
	matrix[0] = (double *) malloc (rows*cols*sizeof(double));
	if (!matrix[0])
	{
		free(matrix);
		return NULL;
	}
	for (i = 1; i < rows; i++)
	{
		matrix[i] = matrix[i-1] + cols;
	}
	return matrix;
}

void freeMatrix(double ** matrix)
{
	free(matrix[0]);
	free(matrix);
}

int main(void)
{
	double ** matrixA, ** matrixB, ** matrixC, ticks;
	int size = 1600;

	matrixA = allocMatrix(size,size); randomMatrix(matrixA, size, size);
	matrixB = allocMatrix(size,size); randomMatrix(matrixB, size, size);
	matrixC = allocMatrix(size,size);

	printf("Two random matricies generated, now multiplying...\n\n");
	ticks = clock();
	multiplyMatrix(matrixA, matrixB, matrixC, size, size, size);
	printf("Multiplication of two square matricies of size %d took %g seconds\n",size,(clock() - ticks)/CLOCKS_PER_SEC);

	freeMatrix(matrixA);
	freeMatrix(matrixB);
	freeMatrix(matrixC);

	return 0;
}