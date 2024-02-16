#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Stack
{
    struct Node *top;
} stack;

// Function to create a new node
node *newNode(int data)
{
    node *new = (struct Node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

// Function to create a new stack
stack *createStack()
{
    stack *stack_open = (stack *)malloc(sizeof(stack));
    stack_open->top = NULL;
    return stack_open;
}

// Function to check if stack is empty
int isEmpty(stack *st)
{
    return !st->top;
}

// Function to push a value onto the stack
void push_data(stack *st, int data)
{
    printf("\n Push data %d", data);
    struct Node *node = newNode(data);
    node->next = st->top;
    st->top = node;
}

// Function to pop a value from the stack
int pop_data(stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }
    node *temp = st->top;
    int popped = temp->data;
    st->top = temp->next;
    free(temp);
    return popped;
}
int main()
{
    stack *stack1 = createStack();
    push_data(stack1, 1);
    push_data(stack1, 2);
    push_data(stack1, 3);
    push_data(stack1, 4);
    printf("\n\n Pop data: %d", pop_data(stack1));
    printf("\n Pop data: %d", pop_data(stack1));
    printf("\n Pop data: %d", pop_data(stack1));
    int random = pop_data(stack1);
    printf("\n Pop data: %d", random);

    printf("\n\n Check a stack is empty or not?\n");
    stack *stack2 = createStack();
    push_data(stack2, random);
    if (isEmpty(stack2))
    {
        printf(" Stack is empty!\n");
    }
    else
    {
        printf(" Stack is not empty!\n");
    }
}
