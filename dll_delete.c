#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *perv;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

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
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    head->perv = NULL;
    free(ptr);

    return head;
}
// Case 2
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        p->perv->next = NULL;
    }
    else
    {
        p->next->perv = p->perv;
        p->perv->next = p->next;
    }
    free(p);
    return head;
}

// Case 3
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->perv->next = NULL;
    free(p);
    return head;
}

int main()
{
    int f;

    struct Node *head;

    head = (struct Node *)malloc(sizeof(struct Node));

    // printf("Enter the no of elements: ");

    // scanf("%d", &f);

    // printf("Enter the elements: ");

    // for (int i = 0; i < f; i++)

    // {
    //     int data = 0;
    //     scanf("%d", &data);
    //     if (i == 0)
    //     {
    //         head->data = data;
    //         head->next = NULL;
    //         head->perv = NULL;
    //     }
    //     else
    //     {
    //         insertAtEnd(head, data);
    //     }
    // }
    // printf("Linked list:-\n ");
    // linkedListTraversal(head);
    int x;
    while (x != -1)
    {

        printf("\n1)Display   2)Traversal with direction  3)delete at first   4)delete at index   5)Delete at End\n");
        printf("Press -1 to exit the program\n");
        scanf("%d", &x);
        if (x == 1)
        {
            linkedListTraversal(head);
        }
        else if (x == 2)
        {
            traversalwithdirection(head);
        }
        else if (x == 3)
        {
            head = deleteFirst(head);
            linkedListTraversal(head);
        }
        else if (x == 4)
        {
            int b;
            printf("Enter the index:");
            scanf("%d", &b);
            head = deleteAtIndex(head, b);
            linkedListTraversal(head);
        }
        else if (x == 5)
        {
            head = deleteAtLast(head);
            linkedListTraversal(head);
        }

        else
        {
            printf("Termi");
        }
    }

    return 0;
}