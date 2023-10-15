#include <stdio.h>

int priorityQ[100];
int front = -1, rear = -1;
int deque[100];
int deque_f = -1, deque_r = -1;

void insert(int element)
{
    if (rear == 100 - 1)
    {
        printf("Priority Queue is full\n");
    }
    else if (front == -1)
    {
        front++;
        rear++;
        priorityQ[rear] = element;
    }
    else
    {
        rear++;
        priorityQ[rear] = element;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Priority Queue is empty\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("Queue has been emptied");
    }
    else
    {
        int max = priorityQ[front];
        int i;
        int max_index;
        for (i = front; i <= rear; i++)
        {
            if (priorityQ[i] > max)
            {
                max = priorityQ[i];
                max_index = i;
            }
        }
        printf("The Number deleted : %d\n", max);
        printf("At index : %d", max_index);
        for (int j = max_index; j <= rear; j++)
        {
            priorityQ[j] = priorityQ[j + 1];
        }
        rear--;
    }
}

void insertFront(int element)
{
    if (deque_f == -1)
    {
        deque_f = deque_r = 0;
        deque[deque_f] = element;
    }
    else if (deque_f > 0)
    {
        deque_f--;
        deque[deque_f] = element;
    }
    else
    {
        printf("Deque is full at the front.\n");
    }
}

void insertRear(int element)
{
    if (deque_r == 100 - 1)
    {
        printf("Deque is full at the rear.\n");
    }
    else
    {
        deque_r++;
        deque[deque_r] = element;
    }
}

void deleteFront()
{
    if (deque_f == -1)
    {
        printf("Deque is empty at the front.\n");
    }
    else
    {
        if (deque_f == deque_r)
        {
            deque_f = deque_r = -1;
            printf("Queue emptied");
        }
        else
        {
            deque_f++;
        }
    }
}

void deleteRear()
{
    if (deque_r == -1)
    {
        printf("Deque is empty at the rear.\n");
    }
    else
    {
        if (deque_f == deque_r)
        {
            deque_f = deque_r = -1;
            printf("Queue emptied");
        }
        else
        {
            deque_r--;
        }
    }
}

void displayPriorityQ()
{
    if (front == -1)
    {
        printf("Priority Queue is empty.\n");
    }
    else
    {
        printf("Priority Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", priorityQ[i]);
        }
        printf("\n");
    }
}

void displayDeque()
{
    if (deque_f == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deque: ");
        for (int i = deque_f; i <= deque_r; i++)
        {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    int element;
    
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. insert (Priority Queue)\n");
        printf("2. delete (Priority Queue)\n");
        printf("3. Insert Front (Deque)\n");
        printf("4. Insert Rear (Deque)\n");
        printf("5. Delete Front (Deque)\n");
        printf("6. Delete Rear (Deque)\n");
        printf("7. Display Priority Queue\n");
        printf("8. Display Deque\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter element to insert: ");
            scanf("%d", &element);
            insert(element);
        }
        else if (choice == 2)
        {
            delete ();
        }
        else if (choice == 3)
        {
            printf("Enter element to insert at the front of the deque: ");
            scanf("%d", &element);
            insertFront(element);
        }
        else if (choice == 4)
        {
            printf("Enter element to insert at the rear of the deque: ");
            scanf("%d", &element);
            insertRear(element);
        }
        else if (choice == 5)
        {
            deleteFront();
        }
        else if (choice == 6)
        {
            deleteRear();
        }
        else if (choice == 7)
        {
            displayPriorityQ();
        }
        else if (choice == 8)
        {
            displayDeque();
        }
        else if (choice == 9)
        {
            printf("Exiting the program.\n");
            return 0;
        }
        else
        {
            printf("Please KYS\n");
        }
    }
    return 0;
}