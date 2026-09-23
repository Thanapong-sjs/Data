#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int data;
    struct Treenode *leftChild,*rightChild;
    struct Treenode *mother;
}Treenode;
struct Treenode *Root;

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void Tree_insert(int data)
{
     Treenode *y = NULL;
     Treenode *t = Root;
     Treenode *x = createNode(data);
     while(t != NULL)
     {
         y = t;
     }
     if(data < t -> data)
     {
         t = t -> leftChild;
     }
     else
     {
         t = t -> rightChild;
     }
     if(y == NULL)
     {
         Root = x;
     }
     else
     {
         if(x -> data < y -> data)
         {
             y -> leftChild = x;
         }
         else
         {
             y -> rightChild = x;
         }
     }
}

void Inorder(Treenode* Root)
{
    if(Root != NULL)
    {
        Inorder(Root -> leftChild);
        printf("%d ",Root -> data);
        Inorder(Root -> rightChild);
    }
    else
    {
        return;
    }
}

int Tree_Find(Treenode *t,int key)
{
    while(t != NULL)
    {
        if(t -> data == key)
        {
            return t;
        }
        if(t -> data < key)
        {
            t = t -> rightChild;
        }
        else
        {
            t = t -> leftChild;
        }
    }
    return NULL;
}

int FindMin(Treenode *t)
{
    while(t -> leftChild != NULL)
    {
        t = t -> leftChild;
    }
    return t;
}

int FindMax(Treenode *t)
{
    while(t -> leftChild != NULL)
    {
        t = t -> rightChild;
    }
    return t;
}

Tree_delete(, )
{
    struct Treenode *x,*y;
    x = Tree_find();
    if()
    {
        printf("value is not found in the tree\n");
    }
    else
    {

    }
}

int main()
{
    int a[]= {56,26,200,18,28,190,213,12,24,27};
    int i,size;
    size=sizeof(a)/sizeof(a[0]);

    for(i=0; i<size; i++)
        Tree_insert(a[i]);

    printf("Min=%d\n",FindMin(Root)->data);
    printf("Max=%d\n",FindMax(Root)->data);

    struct Treenode *p;
    p=Tree_find(Root,190);

    if(p!=NULL)
        printf("Found\n");
    else
        printf("Not found\n");

    Tree_delete(Root,190);
    Tree_delete(Root,26);

    Inorder(Root);
}
