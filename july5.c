#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX 100

void insertQ(int *, int *, int *);
void delQ(int *, int *, int *);
void display(int *, int *, int *);
void peek(int *, int *, int *);

int main()
{
    int i, n, front, rear;
    front = rear = -1;
    char ch;
    int a[MAX];
    // system("cls");

    do
    {

        printf("MENU\n");
        printf("1.insert\n2.delete\n3.display\n4.peek\n5.exit\n");
        scanf("%c", &ch);

        switch (ch)
        {
        case '1':

            insertQ(a, &front, &rear);
            break;
        case '2':
            delQ(a, &front, &rear);
            break;
        case '3':
            display(a, &front, &rear);
            break;
        case '4':
            peek(a, &front, &rear);
            break;
        case '5':
            exit(1);
            break;
        default:
            printf("enter valid option\n\n");
            break;

            /* code */
        }
    } while (1);
    system("cls");
    fflush(stdin);
    return 0;
}

void insertQ(int *a, int *f, int *r)
{

    int n;
    if ((*r == MAX - 1 && *f == 0) || (*r + 1 == *f))
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        printf("enter the item\n");
        scanf("%d", &n);
        if (*r = MAX - 1)
            *r = 0;

        else
            *r++;

        a[*r] = n;
        if (*f == -1)
            *f = 0;
    }
}

void delQ(int *a, int *f, int *r)
{
    if (*f == -1)
    {
        printf("queue underflow");
    }
    int temp = a[*f];
    int pos = *f;
    if (*f == *r)
        *f = *r = -1;
    else
    {
        if (*f == MAX - 1)
            *f = 0;
        else
            *f++;
    }
    printf("deleted front is %d at %d position.\n new front is %d at %d positon\n", temp, pos, a[*f], *f);
}

void peek(int *a, int *f, int *r)
{
    if (*f == -1 && *r == -1)
    {
        printf("queue underflow");
    }
    else
    {
        int front = a[*f];
        printf("front element is %d at %d position\n", front, *f);
    }
}

void display(int *a, int *f, int *r)
{
    int i;
    int n;
    if (*f == -1)
    {
        printf("queue underflow");
    }
    if (*f < *r)
    {
        if (*r < MAX - 1 && *f > -1)
        {
            for (i = *f; i < *r; i++)
            {
                printf("%d", a[i]);
            }
        }
    }
    else
    {
        for (i = *f; i < MAX; i++)
            printf("%d", a[i]);
        for (i = 0; i <= *r; i++)
            printf("%d", a[i]);
    }
}