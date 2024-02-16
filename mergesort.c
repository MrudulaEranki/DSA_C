#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = a[beg + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
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

    mergesort(arr, 0, n - 1);

    printf("Sorted array is \n");
    printArray(arr, n);
}