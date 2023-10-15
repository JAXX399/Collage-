// insertion and traversal
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *perv;
};



struct Node *linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

    return head;
}

struct Node *traversalwithdirection(struct Node *head)
{
    struct Node *ptr = head;
    int x = 0;
    printf("You are at head and the element is %d\n", ptr->data);
    while (x != 3)
    {

        printf("1)Next          2)previous:         3)For exit");
        scanf("%d", &x);
        if (x == 1)
        {
            if (ptr->next == NULL)
            {
                printf("Out of the List ......");
                break;
            }
            ptr = ptr->next;

            printf("The element is:%d\n", ptr->data);
        }
        else if (x == 2)
        {
            if (ptr->perv == NULL)
            {
                printf("Out of the list.......");
                break;
            }
            ptr = ptr->perv;
            printf("The element is:%d\n", ptr->data);
        }
    }

    return head;
}

// Case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->perv = NULL;
    return ptr;
}

// Case 2
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    ptr->perv = p;
    p->next = ptr;
    p->next->perv = ptr;

    return head;
}

// Case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->perv = p;
    return head;
}

int main()
{
    int f;

    struct Node *head;

    head = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the no of elements: ");
    scanf("%d", &f);

    printf("Enter the elements: ");

    for (int i = 0; i < f; i++)
    {
    
        int data = 0;
        scanf("%d", &data);
        if (i == 0)
        {
            head = data;
            head->next = NULL;
            head->perv = NULL;
        }
        else
        {
            head = insertAtEnd(head, data);
        }
    }
    int x = 0;

    printf("Double Linked list :-\n");

    head = linkedListTraversal(head);
    while (x != -1)
    {

        printf("\n1)Display   2)traversal with direction  3)Insert at first   4)Insert at index   5)Insert at End    \n");
        printf("Press -1 to exit the program\n");
        scanf("%d", &x);
        if (x == 1)
        {
            head = linkedListTraversal(head);
        }
        else if (x == 2)
        {
            traversalwithdirection(head);
        }
        else if (x == 3)
        {
            int n;
            printf("Enter the data:");
            scanf("%d", &n);
            head = insertAtFirst(head, n);
            head = linkedListTraversal(head);
        }
        else if (x == 4)
        {
            int a;
            int b;
            printf("Enter the data:");
            scanf("%d", &a);
            printf("Enter the index:");
            scanf("%d", &b);
            head = insertAtIndex(head, a, b);
            head = linkedListTraversal(head);
        }
        else if (x == 5)
        {
            int a;
            printf("Enter the data: ");
            scanf("%d", &a);
            head = insertAtEnd(head, a);
            head = linkedListTraversal(head);
        }

        else
        {
            printf("Terminated.................");
        }
    }

    return 0;
}