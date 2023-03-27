#include <stdlib.h>
#include<stdio.h>
int opcount=0;

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && arr[i] <= pivot)
            i++;
        while (j >= left && arr[j] > pivot)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int left, int right) {
    opcount++;
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

void main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int * arr = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Sorted array: ");
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("opcount is %d",opcount);
}