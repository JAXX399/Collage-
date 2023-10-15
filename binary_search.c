#include <stdio.h>

int main()
{
    int n;
    printf("Enter the lenght of the array:");
    scanf("%d", &n);

    int a[n];
    printf("please enter the number for the array:");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &a[i]);
    }

    int target;

    printf("please enter the number you  need to find : ");

    scanf("%d", &target);

    int start = 0;
    int end = n-1;
    int middle = (start + end) / 2;

    while (start <= end)
    {
        if (a[middle] == target)
        {
            printf("the number is foun at %d index:\n",middle);
            return 1;
        }
        if (target > a[middle])
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
    printf("No not found\n");
    return 0;
}
