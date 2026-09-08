#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isPalindrome(char s[],int l,int r)
{
    while(l<r)
    {
        if(tolower(s[l]) != tolower(s[r]))
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main()
{
    char s[101];
    int n,x;

    printf("Input : ");
    scanf("%100s",s);
    n = strlen(s);
    x = isPalindrome(s,0,n-1);
    if(x == 0)
        printf("No");
    else if(isPalindrome(s,0,n/2-1) && isPalindrome(s,n-n/2,n-1))
        printf("Double Palindrome");
    else
        printf("Palindrome");
    return 0;
}
