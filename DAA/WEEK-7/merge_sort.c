#include <stdio.h>

int mergesort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int merge(int a[], int lb, int mid, int ub)
{
    int b[100];
    int i, j, k;
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
            i++;
            k++;
        }
    }

    for (i = lb; i <= ub; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements :");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        printf("::::%d \n", a[i]);
    }

    printf("Sorted list is : \n");
    mergesort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}