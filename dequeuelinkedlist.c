#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} N;

typedef struct dqueue
{
    N *f;
    N *r;
} DQ;

void addAtEnd(DQ *p, int item)
{
    N *temp;
    temp = (N *)malloc(sizeof(N));
    temp->data = item;
    temp->link = NULL;
    if (p->f == NULL)
        p->f = temp;
    else
        p->r->link = temp;
    p->r = temp;
}
void addAtFront(DQ *p, int item)
{
    N *temp;
    int *q;
    temp = (N *)malloc(sizeof(N));
    temp->data = item;
    temp->link = NULL;

    if (p->f == NULL)
        p->f = p->r = temp;
    else
    {
        temp->link = p->f;
        p->f = temp;
    }
}

void display(DQ *dq)
{
    N *temp = dq->f;
    while (temp != NULL)
    {
        if (temp->link == NULL)
        {
            printf("%d ", temp->data);
        }
        else
            printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    DQ queue;
    queue.f = NULL;
    queue.r = NULL;
    int i, a, b, n, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        addAtFront(&queue, a);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b);
        addAtEnd(&queue, b);
    }
    display(&queue);
    printf("\n");

    N *temp = queue.f->link;

    while (temp != queue.r)
    {

        printf("%d ", temp->data);
        temp = temp->link;
    }

    return 0;
}