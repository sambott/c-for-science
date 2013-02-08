#include <stdlib.h>
#include <stdio.h>

#define N 3

double *** alloc3Tensor(unsigned int dim)
{
	unsigned int i, j;
	double *** tensor;
	tensor = (double ***) malloc(dim*sizeof(double **));
	if (!tensor) return NULL;
	tensor[0] = (double **) malloc(dim*dim*sizeof(double *));
	if (!tensor[0])
	{
		free(tensor);
		return NULL;
	}
	tensor[0][0] = (double *) malloc(dim*dim*dim*sizeof(double));
	if (!tensor[0][0])
	{
		free(tensor[0]); free(tensor);
		return NULL;
	}
	for (i = 1; i < dim; i++)
		tensor[0][i] = tensor[0][i-1]+dim;
	for (i = 1; i < dim; i++)
	{
		tensor[i] = tensor[i-1] + dim;
		tensor[i][0] = tensor[i-1][0] + dim * dim;
		for (j = 1; j < dim; j++)
			tensor[i][j] = tensor[i][j-1] + dim;
	}
	return tensor;
}

void free3Tensor(double *** tensor)
{
	free(tensor[0][0]);
	free(tensor[0]);
	free(tensor);
}

int main()
{
	double *** tensor;
	unsigned int i, j, k;
	tensor = alloc3Tensor(N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				tensor[i][j][k] = i+j+k;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
				printf("%8.4lf ", tensor[i][j][k]);
			printf("\n");
		}
		printf("\n\n");
	}

	free3Tensor(tensor);
	return 0;
}

