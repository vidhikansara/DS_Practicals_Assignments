#include<stdio.h>

FILE *ptr;

int swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf(" swap %d %d",a,b);

    int d=0;
    while(a!=0)
    {
        d=d*10;
        d=d+a%10;
        a=a/10;
    }

    if(d==b)
        printf("\nPalindrome number !");
    else
        printf("\nNot palindrome number !");

    return 0;
}


int main()
{
    int n1,n2;
    int rd;
    printf("\nRead values from file press 1 otherwise 0 : ");
    scanf("%d",&rd);
    if(rd==1)
    {
        ptr=fopen("swappalindrome.txt","r");
        while(fscanf(ptr, "%d %d", &n1, &n2)!=EOF)
        {
            printf(" %d %d ",n1,n2);
        }
        printf("\ndata read !");
        fclose(ptr);
        int (*pt)(int,int)=&swap;
            (*pt)(n1,n2);

    }
    else
    {
        ptr=fopen("swappalindrome.txt","w");
        printf("Enter four values: ");
        scanf("%d %d",&n1,&n2);
        fprintf(ptr,"%d %d",n1,n2);
        printf("\ndata written !");
        fclose(ptr);
        int (*pt)(int,int)=&swap;
        (*pt)(n1,n2);
    }


    return 0;
}
