/*Given a singly linked list and a key, count the number of occurrences of given key in the linked list.

Input Format

First line of input contains n the size of linked list. Next line of input contains n integers the elements of linked list Next line of input contains x whose occurence is needed to be count

Constraints

0 ≤ N ≤ 10^4

Output Format

Print the number of occurrences of given key in the linked list.

Sample Input 0

7
1 2 3 4 1 6 7
1
Sample Output 0

2
Sample Input 1

5
1 2 3 4 5
8
Sample Output 1

0*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct list
{
    struct node *head;
    struct node *item;
};

int main()
{
    struct list ll = NULL;
    int arr[10000];

    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        if (ll = null)
        {
            ll->head = temp;
            temp->data = a;
            temp->link = NULL;
        }
        else
        {
        }
    }
    return 0;
}

// checl it out later