/*#include <stdio.h>

void merge(int a[], int beg, int mid, int end);
void mergesort(int a[], int beg, int end);

int main()
{
    int n, i, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    return 0;
}

void mergesort(int a[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void merge(int arr[], int l, int m, int r)
{

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
*/

// QUICK SORT

#include <stdio.h>
int a[100];
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int low, int high);
int quicksort(int array[], int low, int high);

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    return 0;
}

int partition(int a[], int low, int high)
{
    int i = low, j = high, p;
    p = a[i];

    while (i < j)
    {
        while (a[i] <= p)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}
int quicksort(int a[], int low, int high)
{

    if (low < high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, low + 1, high);
    }
}