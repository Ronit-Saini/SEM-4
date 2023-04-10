// Q2
#include <stdio.h>
#include <stdlib.h>
int opCount = 0;

void heapifyBottomUp(int heapArray[], int left, int size)
{
    int i;
    int k;
    int trace;
    int heapifyMenu;
    int j;

    for (i = (size / 2); i >= left; i--)
    {
        k = i;
        trace = heapArray[k];
        heapifyMenu = 0;
        while (heapifyMenu == 0 && 2 * k <= size)
        {
            j = 2 * k;
            opCount++;
            if (j < size)
                if (heapArray[j] < heapArray[j + 1])
                    j = j + 1;
            if (trace >= heapArray[j])
                heapifyMenu = 1;
            else
            {
                heapArray[k] = heapArray[j];
                k = j;
            }
        }
        heapArray[k] = trace;
    }
    return;
}

void HeapSortUsingBottomUp(int heapArray[], int size)
{
    int j = 0;
    for (int i = 1; i <= size; i++)
    {
        heapifyBottomUp(heapArray, 1, size - j);
        int temp = heapArray[1];
        heapArray[1] = heapArray[size - j];
        heapArray[size - j] = temp;
        j++;
    }
}

void main()
{
    int heapArray[20];
    int size;
    int i;

    printf("Enter the size of Elemets : ");
    scanf("%d", &size);
    printf("\n\n");
    printf("Enter the Elements : ");
    for (i = 1; i <= size; i++)
        scanf("%d", &heapArray[i]);
    HeapSortUsingBottomUp(heapArray, size);
    printf("\n\n");
    printf("The Heap Sort Array is : \n");
    printf("\n");
    for (i = 1; i <= size; i++)
        printf("%d ", heapArray[i]);
    printf("\n\n");
    printf("The Opcount is = %d\n", opCount);
    printf("\n\n");
}

/*
Enter the size of Elemets : 7


Enter the Elements : 48
10
23
43
28
26
1


The Heap Sort Array is :

1 10 23 26 28 43 48

The Opcount is = 14
*/