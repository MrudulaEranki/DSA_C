#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Circular Queue Structure
typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
    bool isFull;
} CircularQueue;

// Initialize the Circular Queue
void initialize(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
    queue->isFull = false;
}

// Check if the Circular Queue is empty
bool isEmpty(CircularQueue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the Circular Queue is full
bool isFull(CircularQueue *queue)
{
    return queue->isFull;
}

// Enqueue an element into the Circular Queue
void enqueue(CircularQueue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Circular Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = element;

    // Check if the queue is full after enqueue
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
    {
        queue->isFull = true;
    }
}

// Dequeue an element from the Circular Queue
int dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int element = queue->data[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
        queue->isFull = false;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return element;
}

// Get the front element of the Circular Queue
int front(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is empty. No front element.\n");
        return -1;
    }

    return queue->data[queue->front];
}

// Get the rear element of the Circular Queue
int rear(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is empty. No rear element.\n");
        return -1;
    }

    return queue->data[queue->rear];
}

int main()
{
    CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(&queue)); // Output: Front element: 10
    printf("Rear element: %d\n", rear(&queue));   // Output: Rear element: 30

    dequeue(&queue);
    printf("Front element after dequeue: %d\n", front(&queue)); // Output: Front element after dequeue: 20

    return 0;
}
