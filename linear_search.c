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

    printf("please enter the number you need to find: ");

    scanf("%d", &target);

    for (int i = 0; i <= n; i++)
    {
        if (a[i] == target)
        {
            printf("the nummber is at %d index: \n", i);
            return 0;
        }
    }
    printf("No not present in array\n");
    return 0;
}
