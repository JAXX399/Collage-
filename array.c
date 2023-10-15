#include <stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //auxilary array
        int arr_pointer[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            printf("0\t");
        }
        else
        {
            printf("1\t");
        }
    }

    int m;
    printf("\n");
    printf("Enter the value of m:\n");
    scanf("%d", &m);
    printf("For insertion press 1 ,for deletion press 0\n");
    int a;
    int target;
    int inserting;

    printf("Do you want to insert or delete array:");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("The location of the number you need to insert:");
        scanf("%d", &target);
        printf("The number you need to insert:");
        scanf("%d", &inserting);

        for (int i = m; i >= target; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[target] = inserting;
        printf("The array is:");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    else
    {
        printf("The location of the number you need to delete:");
        scanf("%d", &target);
        for (int i = target; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("The array is:");
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}