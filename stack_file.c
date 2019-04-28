#include<stdio.h>
#include<stdlib.h>
int stack[100],top=-1,sz;

FILE *ptr,*ft;

void push();
int Isfull();
int Isempty();
void pop();
void peep();
void update();
void display();
void readdata();

int main()
{
    printf("Enter size: ");
    scanf("%d",&sz);

    int choice;
    printf("1.Push\n2.Pop\n3.Peep\n4.Update\n5.Display\n6.read from file\n7.exit\n");

    while(choice!=7)
    {
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            update();
            break;
        case 5:
            display();
            break;
        case 6:
            readdata();
            break;
        case 7:
            exit(0);
        default:
            printf("Opps! wrong choice ...");
        }
    }
}
int Isfull()
{
    if(top>=sz)
        return 1;
    else
        return 0;
}
int Isempty()
{
    if(top<0)
        return 1;
    else
        return 0;
}
void push()
{
    int data;

    ptr=fopen("stackfile.txt","a");

    if(Isfull()==1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        printf("Enter data you want to enter: ");
        scanf("%d",&data);
        top++;
        stack[top]=data;
        fprintf(ptr,"%d\n",data);
        printf("\nData written !");
        fclose(ptr);
    }
}


void pop()
{
    int data,info;
    if(Isempty()==1)
    {
        printf("Stack Underflow !");
    }
    else
    {
        data=stack[top];
        ptr=fopen("stackfile.txt","r");
        ft=fopen("tempdata.txt","w+");
        rewind(ptr);
        while(fscanf(ptr,"%d\n",&info)!=EOF)
        {
            if(info!=data)
            {
                fprintf(ft,"%d\n",info);
            }
        }
        fclose(ptr);
        fclose(ft);
        remove("stackfile.txt");
        rename("tempdata.txt","stackfile.txt");
        printf("Value removed from stack is : %d",data);
        top--;
    }
}

void readdata()
{
    ptr=fopen("stackfile.txt","r");

    int info,i;

    if(!Isempty())
    {
        for(i=top;i>=0;--i)
            pop();
    }

    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        top++;
        stack[top]=info;
    }

    printf("\nData Read !");
    fclose(ptr);
}

void peep()
{
    int ind;
    printf("Enter index number :");
    scanf("%d",&ind);
    if(top-ind==0)
    {
        printf("Stack overflow !");
    }
    else
    {
        printf("Element from top of the stack is : %d",stack[top-ind]);
    }
}
void update()
{
    int flag=0;
    int ind;
    int newdata;
    printf("Enter index for update: \n");
    scanf("%d",&ind);
    printf("Enter new data : \n");
    scanf("%d",&newdata);
    if(top-ind==0)
        printf("Stack overflow !\n");
    else
    {
        flag=1;
        stack[top-ind]=newdata;
        printf("updated successfully !\n");
    }
}
void display()
{
    int i;
    if(Isempty()==1)
        printf("Stack underflow !");
    else
    {
        for(i=top;i>=0;--i)
            printf("| %d |\n",stack[i]);
    }
}



