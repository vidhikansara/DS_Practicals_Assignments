#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

FILE *ptr;

void push(char st)
{
    top++;
    stack[top] = st;
}

void pushString(char *s)
{
    int i;
    top = -1;
    for (i = 0; i < strlen(s); i++)
    {
        push(s[i]);
    }
}

int isEmpty()
{
    if (top < 0)
        return 1;
    else
        return 0;
}

char pop()
{
    return stack[top--];
}

char *readdata()
{
    int i;
    char *info = (char *)malloc(1024 * sizeof(char));
    ptr = fopen("str_palindrome.txt", "r");

    fgets(info, 1024, ptr);

    fclose(ptr);

    return info;
}

int checkPalindrome(char *str)
{
    int i, flag = 1;
    char ch;

    for (i = 0; i <= (strlen(str) / 2); i++)
    {
        if ((ch = pop()) != str[i])
        {
            flag = 0;
            break;
        }
    }

    top = -1;

    return flag;
}

int main()
{
    int choice = 1, i;
    char str[100];
    int ans;
    char *s;

    while (choice != 0)
    {

        system("cls"); // To clear console

        printf("\nRead string from file ? y=1/n=0 : ");
        scanf("%d", &ans);
        if (ans == 1)
        {
            s = readdata();

            pushString(s);

            if (checkPalindrome(s))
            {
                printf("\nString is Palindrome !");
            }
            else
            {
                printf("\nString is Not Palindrome !");
            }
        }
        else
        {
            printf("\nEnter string: ");
            scanf("%s", str);
            ptr = fopen("str_palindrome.txt", "w");
            if (ptr == NULL)
            {
                printf("\nError in handling file !");
                exit(0);
            }
            fputs(str, ptr);
            fclose(ptr);
            printf("\nData written in file !");

            pushString(str);

            if (checkPalindrome(str))
            {
                printf("\nString is Palindrome !");
            }
            else
            {
                printf("\nString is Not Palindrome !");
            }
        }

        printf("\n\nIf you wish to continue press 1 otherwise 0:");
        scanf("%d", &choice);
    }
}
