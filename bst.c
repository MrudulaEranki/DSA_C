#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, char data)
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

struct Node *deleteNode(struct Node *root, char key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *root = NULL;
    char data;
    printf("Enter the characters for the nodes:\n");
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &data);
        root = insert(root, data);
    }

    printf("Post-order Traversal of the Binary Search Tree: ");
    postOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 'A');
    root = deleteNode(root, 'C');

    printf("Post-order Traversal after deleting 'A' and 'C': ");
    postOrderTraversal(root);
    printf("\n");

    int nodeCount = countNodes(root);
    printf("Number of nodes in the tree: %d\n", nodeCount);

    return 0;
}
