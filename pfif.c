#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

/*
  polish notation/prefix notation:-
    operator placed before 2 operands
  reverse polish/postfix:-
    operator after 2operands

 3 levels of hierarchy of precedence:-
       highesstttt= ^
       next highest = * and /
       lowest = + and -
*/

int precendence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
int isOp(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix)
{
    int i, j;

    int len = strlen(infix);

    char *postfix = (char *)malloc(sizeof(char) * (len + 2));

    char stack[200]; // change it to create stack later!!!!
    int top = -1;

    for (i = 0, j = 0; i < len; i++)
    {

        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }

        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "invalid expression";
            else
                top--;
        }

        else if (isOp(infix[i]))
        {
            while (top > -1 && precendence(stack[top]) >= precendence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[top++] = infix[i];
        }
    }

    while (top > -1)
    {
        if (stack[top] == '(')
        {
            return "invalid expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[200];
    scanf("%d", infix);
    printf("postfix expression is:\n");
    char *postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}