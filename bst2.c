#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *root = NULL;
    int data;
    printf("Enter the characters for the nodes:\n");
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("inorder Traversal of the Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
