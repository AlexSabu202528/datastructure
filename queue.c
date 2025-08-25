#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int n)
{
    if (rear == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = n;
        printf("Successfully added %d\n", n);
    } 
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        int item = queue[front];
        printf("The deleted item is %d\n", item);
        front++;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Add\n2. Delete\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            printf("Exiting program.\n");
            return 0;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }
}
