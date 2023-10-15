#include <stdio.h>
void main()
{
    int n;
    printf("Please enter the lenght of the array:");
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
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        for (j; j >= 0; j--)
        {
            if (arr[j] < current)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = current;
    }
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}