#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail = NULL;

int del_array[2000];
int top = -1;

void add_into_LL(int data);

int delete_from_LL();

int count_LL();

int count_array();

void display_LL();

int main()
{
    int n;
    printf("enter number of items to be inserted into linked list\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int j;
        scanf("%d", &j);
        add_into_LL(j);
    }

    display_LL();

    printf("the number of elements = %d\n", count_LL());

    printf("enter number of elements you want to delete:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        delete_from_LL();
    }
    printf("number of deleted elements are %d\n", count_array());
    printf("delete elements are:\n");
    for (int i = 0; i < count_array(); i++)
    {
        printf("%d\n", del_array[i]);
    }
    printf("the current elements are:\n");
    display_LL();

    return 0;
}

void add_into_LL(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
    }

    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

int delete_from_LL()
{
    // from the end.
    // head, tail,data,next

    int item = tail->data;
    struct node *temp = head;

    int n = count_LL();
    for (int i = 1; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;

    if (top == -1)
    {
        top = 0;
        del_array[top] = item;
    }
    else
    {
        top++;
        del_array[top] = item;
    }
}

int count_LL()
{
    int count = 0;

    struct node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int count_array()
{
    int count = 0;

    int p = del_array[0];

    for (int i = 0; i < 100; i++)
    {
        if (del_array[i] != '\0')
            count++;
        else
            break;
    }
    return count;
}

void display_LL()
{
    struct node *now = head;

    if (head == NULL)
    {
        printf("empty list!!\n");
        return;
    }

    printf("the items are:\n");

    while (now != NULL)
    {
        /* code */
        printf("%d\n", now->data);
        now = now->next;
    }
    // printf("\n");
}