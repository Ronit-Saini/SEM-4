#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int duplicate(int a[MAX], int ub)
{
    int i;
    for (i = 0; i < ub; i++)
    {
        for (int j = i + 1; j < ub; j++)
        {
            if (a[j] == a[i])
            {
                return a[j];
            }
        }
    }
    return 0;
}

void merge(int a[MAX], int lb, int mid, int ub)
{
    int i = 0;
    if (duplicate(a, mid) != 0)
    {
        for (i = lb; i < ub; i++)
        {
            printf("%d ", a[i]);
        }
    }
}

void mergesort(int a[MAX], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (ub + lb) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int n, i, j;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int dup = duplicate(a, n);
    printf("Duplicate digit found : %d\n", dup);

    mergesort(a, 0, n - 1);
    printf("Sorted list : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}
