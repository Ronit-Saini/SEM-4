#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of an array : ");
    scanf("%d", &n);
    int Arr[n];
    int i, j, k, temp, opcount = 0;
    printf("\nEnter the elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }

    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n - j - 1; k++)
        {
            opcount++;
            if (Arr[k] > Arr[k + 1])
            {
                temp = Arr[k];
                Arr[k] = Arr[k + 1];
                Arr[k + 1] = temp;
            }
        }
    }

    printf("\nSorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\nOperation Count %d\n", opcount);

    return 0;
}