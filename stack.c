#include <stdio.h>
#include <stdlib.h>

// Structure for each node of the linked list
/*typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure for the stack
typedef struct Stack
{
    Node *top;
} Stack;

// Function to create an empty stack
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Elements in the stack: ");
    Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void destroyStack(Stack *stack)
{
    Node *current = stack->top;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main()
{
    Stack *stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    display(stack);

    printf("Top element: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    display(stack);

    destroyStack(stack);
    return 0;
}*/

// my implementation
