#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

int getHeight(Node* root)
{
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getBalanceFactor(Node* root)
{
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

bool isAVL(Node* root)
{
    if (root == NULL) return true;

    int bf = getBalanceFactor(root);
    if (bf < -1 || bf > 1)
    {
        return false;
    }

    return isAVL(root->left) && isAVL(root->right);
}

int main()
{
    Node* root = NULL;
    int val;

    while (scanf("%d", &val) == 1)
    {
        if (val < 0)
        {
            break;
        }
        root = insert(root, val);
    }

    if (isAVL(root))
    {
        printf("an AVL Tree\n");
    }
    else
    {
        printf("Not an AVL Tree\n");
    }

    return 0;
}
