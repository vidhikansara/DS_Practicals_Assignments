#include<stdio.h>
#define SIZE 50

int queue[SIZE];
int front=-1,rear=-1;

FILE *ptr,*ft;

int isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}

void insert()
{
    int val;
    if(!isFull())
    {
            ptr=fopen("queuefile.txt","a");
            if(front==-1)
                front=0;

            printf("\nEnter value : ");
            scanf("%d",&val);
            rear++;
            queue[rear]=val;
             printf("\nINSERTED !\n");

             fprintf(ptr,"%d\n",val);
            printf("\nData written !");
            fclose(ptr);
    }
    else
    {
        printf("\nQueue is full !");
    }

}



void display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}

void dequeue()
{
    int data,info;
    if(!isEmpty())
    {
        data=queue[front];
        ptr=fopen("queuefile.txt","r");
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
        remove("queuefile.txt");
        rename("tempdata.txt","queuefile.txt");
        printf("\nDeleted : %d",queue[front]);
        front++;

    }
    else
    {
        printf("\nQueue is empty !");
    }
}

void readdata()
{
    if(!isFull())
    {
        ptr=fopen("queuefile.txt","r");

        int info;

        int i;
        for(i=front;i<=rear;i++)
        {
            dequeue();
        }

        while(fscanf(ptr,"%d\n",&info)!=EOF)
        {
            if(front==-1)
                front=0;
            rear++;
            queue[rear]=info;
        }

        printf("\nData Read !");
    }
    fclose(ptr);

}

int main()
{
    int choice;

    while(choice!=5)
    {
        printf("\n1.insert\n2.display\n3.Delete\n4.read from file\n5.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            readdata();
            break;
        case 5:
            break;
        }
    }
}

