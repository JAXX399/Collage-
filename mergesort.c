#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
        
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid =  (high + low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low,mid, high);
        printf("Intermediate steps:\n");
        for(int i=low;i<=high;i++){
            printf("%d\t",A[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the no of elements for the array:");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements for the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("The unsorted array is:");
    printArray(A, n);
    mergeSort(A, 0, n-1);
    printf("The sorted array is:");
    printArray(A, n);
    return 0;
}