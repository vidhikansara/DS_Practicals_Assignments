#include<stdio.h>
#include<stdlib.h>

struct Stnode
{
    int data;
    struct Stnode* next;
}*top=NULL;

FILE *ptr,*ft;

void insert()
{
    int info;
    ptr=fopen("stacklindedlistfile.txt","a");

    struct Stnode* newnode=(struct Stnode*)malloc(sizeof(struct Stnode));
    printf("\nEnter data : ");
    scanf("%d",&info);

    newnode->data=info;
    newnode->next=NULL;

    newnode->next=top;
    top=newnode;

    printf("\nINSERTED !");

    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);

}



void pop()
{
    int data,info;
    if(top==NULL)
        printf("\nStack is empty !");
    else
    {
        struct Stnode* temp;
        temp=top;

        data=temp->data;
        ptr=fopen("stacklindedlistfile.txt","r");
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
        remove("stacklindedlistfile.txt");
        rename("tempdata.txt","stacklindedlistfile.txt");

        printf("\nDeleted %d!",temp->data);
        top=temp->next;
        free(temp);
    }
}

void readdata()
{
    ptr=fopen("stacklindedlistfile.txt","r");

    int info;

    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct Stnode* newnode=(struct Stnode*)malloc(sizeof(struct Stnode));
        newnode->data=info;
        newnode->next=NULL;

        newnode->next=top;
        top=newnode;
    }

    printf("\nData Read !");
    fclose(ptr);
}

void Display()
{
    struct Stnode* temp;

    temp=top;

    while(temp!=NULL)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice;

    while(choice!=5)
    {
        printf("\n1.Push\n2.Pop\n3.display\n4.read from file\n5.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            readdata();
            break;
        case 5:
            break;
        }
    }
}

