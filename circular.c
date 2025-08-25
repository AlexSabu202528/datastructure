#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

typedef struct {
    int arr[MAX];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}


int isFull(CircularQueue* queue) {
    if ((queue->rear + 1) % MAX == queue->front)
        return 1;
}

int isEmpty(CircularQueue* queue) {
    if (queue->front == -1)
        return 1; 
    return 0;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }

    if (queue->front == -1) {  
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {  
        queue->front = queue->rear = -1;  
    } else {
        queue->front = (q
