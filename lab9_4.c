#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main()
{
    int n;
    if(scanf("%d", &n) != 1)
    {
        return 0;
    }
    int T[MAX_SIZE];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
    }
    int low, high;
    scanf("%d %d", &low, &high);
    int stack[MAX_SIZE];
    int top = -1;
    int node = 0;
    bool isBST = true;
    long long prev = -1;
    long long sum = 0;
    while(top != -1 || node < n)
    {
        if(node < n && T[node] != 0)
        {
            stack[++top] = node;
            node = 2 * node + 1;
        }
        else
        {
            if(top == -1)
            {
                break;
            }
            node = stack[top--];
            if(prev != -1 && T[node] <= prev)
            {
                isBST = false;
            }
            prev = T[node];

            if(T[node] >= low && T[node] <= high)
            {
                sum += T[node];
            }
            node = 2 * node + 2;
        }
    }
    if(isBST)
    {
        printf("1\n");
        printf("%lld\n", sum);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
