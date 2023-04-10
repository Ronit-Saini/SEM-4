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

/*if(duplicate(a,ub)!=0)
        {
            printf("blashh");
            for(i=0;i<ub;i++)
            {
                printf("%d ",a[i]);
            }
        }*/

void merge(int a[MAX], int lb, int mid, int ub)
{
    int i, j, k, b[100];
    i = k = lb;
    j = mid + 1;

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for (i = 0; i <= ub; i++)
    {
        a[i] = b[i];
        printf("\n::: %d", a[i]);
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
