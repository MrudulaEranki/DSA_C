#include <stdio.h>
#define MAX_STACK_SIZE 100

// Stack operations
void push(int stack[], int *top, int element)
{
    if (*top == MAX_STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = element;
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char expression[])
{
    int stack[MAX_STACK_SIZE];
    int top = -1;
    int i = 0;
    int operand1, operand2, result;

    while (expression[i] != '\0')
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            push(stack, &top, expression[i] - '0');
        }
        else
        {
            operand2 = pop(stack, &top);
            operand1 = pop(stack, &top);

            switch (expression[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid operator\n");
                return -1;
            }
            push(stack, &top, result);
        }
        i++;
    }
    return pop(stack, &top);
}

// Example usage
int main()
{
    char postfixExpression[100];

    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("%d\n", result);

    return 0;
}
