#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// for traversing
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// for insertion in the head place
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// for insertion in last place
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// for insertion in middle (index)
struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// main code
void main()
{
    struct node *head;
    struct node *second;

    
    // allocate memory in the dynamic memory in heap
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    int n;
    printf("Please no of elements ");
    scanf("%d", &n);
    printf("enter elements: ");
    int x=0;
    for(int i=1; i<=n; i++) {
       scanf("%d", &x);
       insertatindex(head, x, i);
    }
    traversal(head);
}
