// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <limits.h>
// #include <ctype.h>

// typedef struct Node
// {
//     int data;
//     struct Node *next;
// } node;

// typedef struct Stack
// {
//     struct Node *top;
// } stack;

// // Function to create a new node
// node *newNode(int data)
// {
//     node *new = (struct Node *)malloc(sizeof(node));
//     new->data = data;
//     new->next = NULL;
//     return new;
// }

// // Function to create a new stack
// stack *createStack()
// {
//     stack *stack_open = (stack *)malloc(sizeof(stack));
//     stack_open->top = NULL;
//     return stack_open;
// }

// // Function to check if stack is empty
// int isEmpty(stack *st)
// {
//     return !st->top;
// }

// // Function to push a value onto the stack
// void push_data(stack *st, int data)
// {
//     printf("\n Push data %d", data);
//     struct Node *node = newNode(data);
//     node->next = st->top;
//     st->top = node;
// }

// // Function to pop a value from the stack
// int pop_data(stack *st)
// {
//     if (isEmpty(st))
//     {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     node *temp = st->top;
//     int popped = temp->data;
//     st->top = temp->next;
//     free(temp);
//     return popped;
// }

// int precedence(char op)
// {
//     switch (op)
//     {
//     case '+':
//     case '-':
//         return 1;
//     case '*':
//     case '/':
//         return 2;
//     case '^':
//         return 3;
//     default:
//         return -1;
//     }
// }

// int isOp(char ch)
// {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
// }

// char *infixToPostfix(char *infix)
// {
//     int i, j;

//     int len = strlen(infix);

//     char *postfix = (char *)malloc(sizeof(char) * (len + 2));

//     stack *newStack = createStack();

//     for (i = 0, j = 0; i < len; i++)
//     {
//         if (i == ' ' || i == '\t')
//             continue;

//         if (i == isalnum(infix[i]))
//             postfix[j++] = infix[i];

//         else if (infix[i] == '(')
//             push_data(newStack, infix[i]);

//         else if (infix[i] == ')')
//         {
//             while (newStack->top != NULL && newStack->top != '(')
//                 postfix[j++] = pop_data(newStack);
//             if (top > -1 && stack[top] != '(')
//                 return "invalid expression";
//             else
//                 top--;
//         }

//         else if (isOp(infix[i]))
//         {
//             while (top != NULL && precendence(stack[top]) >= precendence(infix[i]))
//             {
//                 postfix[j++] = pop_data(newStack);
//             }
//             push_data(newStack, infix[i]);
//         }
//     }

//     while (top != NULL)
//     {
//         if (infix[i] == "(")
//             return "invalid expression";
//         postfix[j++] = pop_data(newStack);
//     }

//     postfix[j] = '\0';
//     return postfix;
// }

// int main()
// {
//     char infix[200];
//     scanf("%d", infix);
//     printf("postfix expression is:\n");
//     char *postfix = infixToPostfix(infix);
//     printf("%s\n", postfix);
//     free(postfix);
//     return 0;
// }

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main()
{
    char exp[100];
    char *infix, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    infix = exp;

    while (*infix != '\0')
    {
        if (isalnum(*infix))
            printf("%c ", *infix);
        else if (*infix == '(')
            push(*infix);
        else if (*infix == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*infix))
                printf("%c ", pop());
            push(*infix);
        }
        infix++;
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}