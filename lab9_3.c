#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node
{
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char key)
{
    if(root == NULL)
    {
        return createNode(key);
    }
    if(key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMin(Node* root)
{
    while(root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root)
{
    while(root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, char key, bool *found)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(key < root->key)
    {
        root->left = deleteNode(root->left, key, found);
    }
    else if(key > root->key)
    {
        root->right = deleteNode(root->right, key, found);
    }
    else
    {
        *found = true;
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, found);
    }
    return root;
}

int searchLevel(Node* root, char key, int level)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->key == key)
    {
        return level;
    }

    if(key < root->key)
    {
        return searchLevel(root->left, key, level + 1);
    }
    else
    {
        return searchLevel(root->right, key, level + 1);
    }
}

void preorder(Node* root)
{
    if(root != NULL)
    {
        printf("%c", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%c", root->key);
        inorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->key);
    }
}

int main()
{
    char input[1000];
    if(scanf("%s", input) != 1)
    {
        return 0;
    }
    Node* root = NULL;
    int i = 0;
    int n = strlen(input);

    while(i < n)
    {
        char ch = input[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            root = insert(root, ch);
            i++;
        }
        else if(ch == '0')
        {
            if(i + 1 < n)
            {
                char target = input[i + 1];
                bool found = false;
                root = deleteNode(root, target, &found);
                if (!found)
                {
                    printf("-1");
                }
                i += 2;
            }
            else
            {
                i++;
            }
        }

        else if(ch == '1')
        {
            if (i + 1 < n)
            {
                char target = input[i + 1];
                int lvl = searchLevel(root, target, 0);
                printf("%d", lvl);
                i += 2;
            }
            else
            {
                i++;
            }
        }
        else if(ch == '2')
        {
            preorder(root);
            i++;
        }
        else if(ch == '3')
        {
            inorder(root);
            i++;
        }
        else if(ch == '4')
        {
            postorder(root);
            i++;
        }
        else if(ch == '5')
        {
            if (root != NULL)
            {
                Node* minNode = findMin(root);
                Node* maxNode = findMax(root);
                printf("%c%c", minNode->key, maxNode->key);
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("\n");
    return 0;
}
