// NOT CORRECT DONT WRITE

#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) (A > B) ? A : B

int F[10][10];

int W; // Knapsack capacity
int n; // Number of items

int weights[10];
int values[10];

int i, j, k;

void input()
{
	printf("Enter knapsack capacity: ");
	scanf(" %d", &W);
	printf("Enter number of items: ");
	scanf(" %d", &n);
	for (i = 1; i < n + 1; ++i)
	{
		printf("Item [%d]; Enter weight: ", i);
		scanf(" %d", &weights[i]);
		printf("Item [%d]; Enter value: ", i);
		scanf(" %d", &values[i]);
	}
}

void printshit()
{
	printf("\nItem\t|\tWeight\t|\tValue\n");
	for (i = 1; i < n + 1; ++i)
	{
		printf("%d\t|\t%d\t|\t%d\n", i, weights[i], values[i]);
	}
	printf("-------------------------------\n");
	printf("\t\t\t\tCapacity j -> \n");
	printf("\t\t\ti | ");
	for (j = 0; j < W + 1; ++j)
		printf("%d\t", j);
	printf("\n");
	for (i = 0; i < n + 1; ++i)
	{
		if (i != 0)
			printf("  w[%d]=%d, v[%d]=%d;\t%d | ", i, weights[i], i, values[i], i);
		else
			printf("\t\t\t%d | ", i);
		for (j = 0; j < W + 1; ++j)
		{
			printf("%d\t", F[i][j]);
		}
		printf("\n");
	}
	printf("\nMaximum value you can fit in knapsack = %d\n", F[n][W]);
}

void exeggute_knapsack()
{
	for (j = 0; j < W + 1; ++j)
	{
		F[0][j] = 0;
	}
	for (i = 0; i < n + 1; ++i)
	{
		F[i][0] = 0;
	}
	F[1][1] = 0;
	for (j = 1; j < W + 1; ++j)
	{
		for (i = 1; i < n + 1; ++i)
		{
			if (j - weights[i] >= 0)
				F[i][j] = MAX(F[i - 1][j], values[i] + F[i - 1][j - weights[i]]);
			else
				F[i][j] = F[i - 1][j];
		}
	}
}

int main(int argc, char const *argv[])
{
	input();
	exeggute_knapsack();
	printshit();
	return 0;
}
