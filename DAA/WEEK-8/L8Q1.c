#include <stdio.h>
#include <stdlib.h>

int op = 0;

void topdown(int arr[], int currIndex)
{
    int parent = (currIndex) / 2;
    op++;
    while (parent > 0)
    {
        op++;
        if (arr[parent] < arr[currIndex])
        {
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;
            parent = (currIndex) / 2;
        }
        else
            return;
    }
}

int main()
{
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d", &n);
    int h[n];
    printf("\nEnter elements : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
        topdown(h, i);
    }
    printf("\nThe heap created is : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\n");
    printf("\nThe Opcount is : %d", op);
    return 0;
}

/*

Enter number of elements : 7

Enter elements : 48
10
23
43
28
26
1

The heap created is : 48 43 26 10 28 23 1

The Opcount is : 15%
*/