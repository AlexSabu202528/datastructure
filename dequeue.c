#include <stdio.h>
#define SIZE 10

int deque[SIZE];
int front = -1, back = -1;

int isFull() {
    return ((front == 0 && back == SIZE - 1) || (front == back + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int key) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at front.\n", key);
        return;
    }

    if (isEmpty()) {
        front = back = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    deque[front] = key;
    printf("Inserted %d at front.\n", key);
}

void insertBack(int key) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at back.\n", key);
        return;
    }

    if (isEmpty()) {
        front = back = 0;
    } else if (back == SIZE - 1) {
        back = 0;
    } else {
        back++;
    }

    deque[back] = key;
    printf("Inserted %d at back.\n", key);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }

    int data = deque[front];

    if (front == back) {
        front = back = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Deleted %d from front.\n", data);
}

void deleteBack() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }

    int data = deque[back];

    if (front == back) {
        front = back = -1;
    } else if (back == 0) {
        back = SIZE - 1;
    } else {
        back--;
    }

    printf("Deleted %d from back.\n", data);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == back)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete Back\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &value);
                insertBack(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteBack();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
