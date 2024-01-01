#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Function to initialize an empty stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push.\n");
        return;
    }

    stack->items[++stack->top] = value;
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }

    int poppedItem = stack->items[stack->top--];
    printf("Popped: %d\n", poppedItem);
    return poppedItem;
}

// Function to display the elements in the stack
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    displayStack(&myStack);

    pop(&myStack);
    pop(&myStack);
    displayStack(&myStack);

    return 0;
}
