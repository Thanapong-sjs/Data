#include<stdio.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}
void infixTopostfix(char infix[], char postfix[])
{
    int i,j = 0;
    char x;
    for(i = 0 ; infix[i] != '\0' ; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1)
                pop();
        }
        else
        {
            x = infix[i];
            while(top != -1 && peek() != '(' && priority(peek()) >= priority(x))
            {
                postfix[j++] = pop();
            }
            push(x);
        }
    }
    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Input : ");
    scanf("%s",infix);

    infixTopostfix(infix,postfix);

    printf("Output : %s\n",postfix);

    return 0;
}
