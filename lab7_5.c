#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_OUTPUTS 500
#define MAX_DOC_LEN 1000

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char val)
{
    if (s->top < MAX_SIZE - 1)
    {
        s->data[++(s->top)] = val;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[(s->top)--];
    }
    return '\0';
}

void clearStack(Stack *s)
{
    s->top = -1;
}

int main()
{
    Stack undoStack;
    Stack redoStack;

    initStack(&undoStack);
    initStack(&redoStack);

    char outputs[MAX_OUTPUTS][MAX_DOC_LEN];
    int outputCount = 0;

    char cmd[20];

    while (1)
    {
        scanf("%s", cmd);

        if (strcmp(cmd, "END") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "WRITE") == 0)
        {
            char ch;
            scanf(" %c", &ch);
            push(&undoStack, ch);
            clearStack(&redoStack);
        }
        else if (strcmp(cmd, "UNDO") == 0)
        {
            if (!isEmpty(&undoStack))
            {
                char ch = pop(&undoStack);
                push(&redoStack, ch);
            }
        }
        else if (strcmp(cmd, "REDO") == 0)
        {
            if (!isEmpty(&redoStack))
            {
                char ch = pop(&redoStack);
                push(&undoStack, ch);
            }
        }
        else if (strcmp(cmd, "READ") == 0)
        {
            if (isEmpty(&undoStack))
            {
                strcpy(outputs[outputCount++], "Blank document");
            }
            else
            {
                int i;
                for (i = 0; i <= undoStack.top; i++)
                {
                    outputs[outputCount][i] = undoStack.data[i];
                }
                outputs[outputCount][i] = '\0';
                outputCount++;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < outputCount; i++)
    {
        printf("\n%s\n", outputs[i]);
    }

    return 0;
}
