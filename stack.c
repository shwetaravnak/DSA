#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;  // Point the new node to the current top
    *top = newNode;        // Make the new node the top of the stack
    printf("Pushed %d onto the stack\n", value);
}
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Stack is empty.\n");
        return -1; // Return -1 when stack is empty
    } else {
        struct Node* temp = *top;
        int poppedValue = temp->data;
        *top = (*top)->next;  // Move the top pointer to the next element
        free(temp);           // Free the memory of the old top
        return poppedValue;
    }
}
// Peek function to view the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1; // Return -1 when stack is empty
    } else {
        return top->data;
    }   }
int isEmpty(struct Node* top) {
    return top == NULL;
}
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }  }
int main() {
    struct Node* stack = NULL;  // Initialize the stack as empty
    int choice, value;
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
