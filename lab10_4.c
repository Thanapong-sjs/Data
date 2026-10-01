#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(Node* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int getBalance(Node* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node* createNode(char key)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insert(Node* node, char key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int findLevel(Node* root, char key, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->key == key)
    {
        return level;
    }
    if (key < root->key)
    {
        return findLevel(root->left, key, level + 1);
    }
    else
    {
        return findLevel(root->right, key, level + 1);
    }
}

void preOrder(Node* root)
{
    if (root != NULL)
    {
        printf("%c", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%c", root->key);
        inOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->key);
    }
}

int main()
{
    char input[1000];
    if (scanf("%s", input) != 1)
    {
        return 0;
    }
    Node* root = NULL;
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        char ch = input[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            root = insert(root, ch);
        }
        else if (ch == '1')
        {
            if (i + 1 < len)
            {
                char target = input[++i];
                int level = findLevel(root, target, 0);
                printf("%d", level);
            }
        }
        else if (ch == '2')
        {
            preOrder(root);
        }
        else if (ch == '3')
        {
            inOrder(root);
        }
        else if (ch == '4')
        {
            postOrder(root);
        }
    }

    printf("\n");
    return 0;
}
