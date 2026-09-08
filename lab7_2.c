#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *Top = NULL;

bool isEmpty()
{
    if (Top == NULL)
        return true;
    return false;
}

void push(int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("\nStack Overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = Top;
    Top = newnode;
}

int pop()
{
    int data = -1;
    if (isEmpty())
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        struct Node *ptr = Top;
        data = Top->data;
        Top = Top->next;
        free(ptr);
    }
    return data;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nStack is Empty\n");
        return -1;
    }
    else
    {
        return Top->data;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nStack is Empty");
    }
    else
    {
        struct Node *temp = Top;
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int item, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH\n 2. POP\n 3. PEEK\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            item = pop();
            if (item != -1)
                printf("\nThe value deleted from stack is: %d", item);
            break;

        case 3:
            item = peek();
            if (item != -1)
                printf("\nThe value stored at top of stack is: %d", item);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Bye ...\n");
            break;

        default:
            printf("Unknown option\n");
            break;
        }
    }
    while(option != 5);

    return 0;
}
