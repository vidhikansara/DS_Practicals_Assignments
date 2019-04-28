#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];


void push(char);
void pop();
void find_top();

FILE* ptr;

int main()
{
	int i;
	int rd;
	char exp[100];
	printf("\nRead data press 1 otherwise 0: ");
    scanf("%d",&rd);
    if(rd==1)
    {
        ptr=fopen("Paramthesis.txt","r");
        fscanf(ptr,"%s", exp);
        printf("%s",exp);
        fclose(ptr);
    }
    else
    {
        printf("enter expression : ");
        scanf("%s", exp);
        ptr=fopen("Paramthesis.txt","w");
        fprintf(ptr,"%s", exp);
        fclose(ptr);
        printf("Data written !");
    }

	for (i = 0; exp[i] != '\0';i++)
	{
		if (exp[i] == '(')
		{
			push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			pop();
		}
	}
	find_top();
}

void push(char s)
{
	stack[top] = s;
	top++;
}


void pop()
{
	if (top == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}
	else
	{
		top--;
	}
}

void find_top()
{
	if (top == -1)
		printf("\nexpression is valid\n");
	else
		printf("\nexpression is invalid\n");
}
