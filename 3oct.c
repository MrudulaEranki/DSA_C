#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    /* data */
} Node;

void *inorder(Node *root)
{
    if (root == NULL)
        return root;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void *preorder(Node *root)
{
    if (root == NULL)
        return root;
    printf("%d ", root->data);
    preorder(root->left);

    preorder(root->right);
}
void *postorder(Node *root)
{
    if (root == NULL)
        return root;
    postorder(root->left);

    postorder(root->right);
    printf("%d ", root->data);
}

Node *createnode(int value)
{
    Node *nn = malloc(sizeof(Node));
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = createnode(value);
        return root;
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
// program 1
int main()
{
    int i, n, a;
    Node *root = NULL;
    printf("enter number of elements you want to enter\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("enter %d nummber--->", i);
        int a;
        scanf("%d", &a);
        root = insert(root, a);
    }
    printf("INORDER TRAVERSAL:\n");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL:\n");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL:\n");
    postorder(root);
    printf("\n");

    return 0;
}
