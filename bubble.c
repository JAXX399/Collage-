#include <stdio.h>

void sorting(int arr[], int n)
{    int i=0;
    while(i<n-1)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                temp = 0;
            }
        }
        i++;
    }
}

int main()
{
    int n;
    printf("Please enter the length of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Please enter the elements of the array:");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The orignal array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The sorted array is:");

    sorting(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}