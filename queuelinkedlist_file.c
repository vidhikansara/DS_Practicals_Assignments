#include<stdio.h>
#include<stdlib.h>

struct Qnode
{
    int data;
    struct Qnode* next;
}*front=NULL,*rear=NULL;

FILE *ptr,*ft;

void insert()
{
    struct Qnode* newnode=(struct Qnode*)malloc(sizeof(struct Qnode));
    int info;

    ptr=fopen("queuelindedlistfile.txt","a");
    printf("\nEnter data: ");
    scanf("%d",&info);

    newnode->data=info;
    newnode->next=NULL;

    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("\n INSERTED !");
    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);

}



void removedata()
{
    int data,info;
    if(front==NULL)
        printf("\nQueue is empty !");
    else
    {
        struct Qnode* temp;
        temp=front;

        data=temp->data;
        ptr=fopen("queuelindedlistfile.txt","r");
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
        remove("queuelindedlistfile.txt");
        rename("tempdata.txt","queuelindedlistfile.txt");

        front=front->next;

        printf("\n Deleted %d ",temp->data);
        free(temp);
    }
}

void readdata()
{
    ptr=fopen("stacklindedlistfile.txt","r");

    int info;

    struct Qnode* temp;
    temp=front;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            removedata();
        }
    }
    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct Qnode* newnode=(struct Qnode*)malloc(sizeof(struct Qnode));
        newnode->data=info;
        newnode->next=NULL;
        if(front==NULL)
        {
            front=rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }

    printf("\nData Read !");
    fclose(ptr);
}

void display()
{
    struct Qnode* temp;
    temp=front;

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
        printf("\n1.insert \n2.remove\n3.display\n4.read from file\n5.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            removedata();
            break;
        case 3:
            display();
            break;
        case 4:
            readdata();
            break;
        case 5:
            break;
        }
    }
}

