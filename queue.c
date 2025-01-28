#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5  
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};
// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct Queue* q) {
    return q->front == -1;
}
int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {  // If the queue is empty, set front to 0
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued %d\n", value);
    } }
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Return -1 if the queue is empty
    } else {
        int dequeuedValue = q->items[q->front];
        // If there's only one element in the queue, reset to empty
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return dequeuedValue;
    }  }
// Function to get the front element of the queue
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return q->items[q->front];
    }  }
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }   }
int main() {
    struct Queue q;
    initQueue(&q);
    int choice, value;
    do {
        printf("\nQueue Operations Menu:\n");
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
