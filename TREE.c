/*#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void initializeArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

void insert(int arr[], int value, int index)
{
    if (arr[index] == -1)
    {
        arr[index] = value;
    }
    else
    {
        printf("Error: Array index already contains a value.\n");
    }
}

// Function to display the binary tree array representation
void display(int arr[], int size)
{
    printf("Binary Tree Array Representation:\n");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != -1)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int binaryTreeArray[MAX_SIZE];
    int size = 5;
    initializeArray(binaryTreeArray, size);


    for (int i = 0; i < size; i++)
    {
        printf("enter element %d\n", i + 1);
        int ins;
        scanf("%d", &ins);
        insert(binaryTreeArray, ins, i);
    }

    display(binaryTreeArray, size);

    return 0;
}*/

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//////////linked list rep of bin tree

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the binary tree
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// // Function to create a new node
// struct Node *createNode(int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // Function to insert a node into the binary tree
// struct Node *insert(struct Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return createNode(data);
//     }
//     else
//     {
//         if (data <= root->data)
//         {
//             root->left = insert(root->left, data);
//         }
//         else
//         {
//             root->right = insert(root->right, data);
//         }
//         return root;
//     }
// }

// // Function to print the binary tree in inorder traversal
// void inorderTraversal(struct Node *root)
// {
//     if (root != NULL)
//     {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }
// void postorderTraversal(struct Node *root)
// {
//     if (root != NULL)
//     {
//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         printf("%d ", root->data);
//     }
// }
// void preorderTraversal(struct Node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d ", root->data);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// }

// // Function to free the memory allocated for the binary tree
// void freeBinaryTree(struct Node *root)
// {
//     if (root != NULL)
//     {
//         freeBinaryTree(root->left);
//         freeBinaryTree(root->right);
//         free(root);
//     }
// }

// int main()
// {
//     // Create an empty binary tree
//     struct Node *root = NULL;

//     // Insert elements into the binary tree
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root = insert(root, 80);

//     // Print the binary tree in inorder traversal
//     printf("Inorder Traversal of the Binary Tree: ");
//     inorderTraversal(root);
//     printf("\n");
//     printf("Postorder Traversal of the Binary Tree: ");
//     postorderTraversal(root);
//     printf("\n");

//     printf("Preorder Traversal of the Binary Tree: ");
//     preorderTraversal(root);
//     printf("\n");

//     // Free the memory allocated for the binary tree
//     freeBinaryTree(root);

//     return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// // Node structure for the expression tree
// struct Node {
//     char data;
//     struct Node* left;
//     struct Node* right;
// };

// // Function to create a new node
// struct Node* createNode(char data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // Function to build an expression tree from the postfix expression
// struct Node* buildExpressionTreePostfix(char postfix[]) {
//     struct Node* stack[100];
//     int top = -1;

//     for (int i = 0; postfix[i]; i++) {
//         struct Node* newNode = createNode(postfix[i]);
//         if (isalnum(postfix[i])) {
//             stack[++top] = newNode;
//         } else {
//             newNode->right = stack[top--];
//             newNode->left = stack[top--];
//             stack[++top] = newNode;
//         }
//     }
//     return stack[top];
// }

// // Function to build an expression tree from the prefix expression
// struct Node* buildExpressionTreePrefix(char prefix[], int* idx) {
//     char c = prefix[*idx];
//     (*idx)++;

//     if (isalnum(c)) {
//         return createNode(c);
//     } else {
//         struct Node* newNode = createNode(c);
//         newNode->left = buildExpressionTreePrefix(prefix, idx);
//         newNode->right = buildExpressionTreePrefix(prefix, idx);
//         return newNode;
//     }
// }

// // Function to evaluate the expression tree
// int evaluateExpressionTree(struct Node* root) {
//     if (root == NULL) {
//         return 0;
//     }

//     if (isdigit(root->data)) {
//         return root->data - '0';
//     }

//     int leftOperand = evaluateExpressionTree(root->left);
//     int rightOperand = evaluateExpressionTree(root->right);

//     switch (root->data) {
//         case '+':
//             return leftOperand + rightOperand;
//         case '-':
//             return leftOperand - rightOperand;
//         case '*':
//             return leftOperand * rightOperand;
//         case '/':
//             return leftOperand / rightOperand;
//         default:
//             printf("Error: Invalid operator\n");
//             exit(EXIT_FAILURE);
//     }
// }

// // Function to free the memory allocated for the expression tree
// void freeExpressionTree(struct Node* root) {
//     if (root != NULL) {
//         freeExpressionTree(root->left);
//         freeExpressionTree(root->right);
//         free(root);
//     }
// }

// int main() {
//     char postfixExpr[] = "82+3*";
//     struct Node* postfixRoot = buildExpressionTreePostfix(postfixExpr);
//     printf("Postfix Expression Result: %d\n", evaluateExpressionTree(postfixRoot));
//     freeExpressionTree(postfixRoot);

//     char prefixExpr[] = "+8*23";
//     int idx = 0;
//     struct Node* prefixRoot = buildExpressionTreePrefix(prefixExpr, &idx);
//     printf("Prefix Expression Result: %d\n", evaluateExpressionTree(prefixRoot));
//     freeExpressionTree(prefixRoot);

//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


