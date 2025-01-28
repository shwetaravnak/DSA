#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5  
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}
int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        // If the queue is empty, set front to 0
        if (q->front == -1) {
            q->front = 0;
        }
        // Move the rear pointer circularly
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = value;
        printf("Enqueued %d\n", value);
    } }
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Return -1 if the queue is empty
    } else {
        int dequeuedValue = q->items[q->front];
        // If there's only one element, reset the queue to empty
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            // Move the front pointer circularly
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return dequeuedValue;
    }   }
// Function to get the front element of the queue
int front(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->items[q->front];
    }   }
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", q->items[q->rear]);
    }   }
int main() {
    struct CircularQueue q;
    initQueue(&q);
    int choice, value;
    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Check Front Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                value = front(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
