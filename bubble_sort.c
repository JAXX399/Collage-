#include <stdio.h>

void swaping(int *a, int *b)
{
    int clone = *a;
    *a = *b;
    *b = clone;
}

void sorting(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swaping(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    printf("please enter the size of the array:");
    scanf("%d ", &n);
    int arr[n];
    printf("please enter elements of array:");
    for (int i = 0; i < n; i++)
    {

        scanf("%d ", &arr[i]);
    }

    printf("The Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    sorting(arr, n);

    printf("\nThe Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
