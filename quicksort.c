#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 45, 60, 34, 55, 12, 74, 89, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, 8);

    printf("Sorted array is \n");
    printArray(arr, n);
}