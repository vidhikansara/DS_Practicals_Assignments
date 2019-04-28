#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int data;
    struct llnode* next;
}*head=NULL;

int count=0;
void insertatB();
void Display();
void displaySets();
void readdata();


FILE *ptr;

int main()
{
    int choice;

   // int set[3] = {'a', 'b', 'c'};
   // displaySets(set, sizeof(set) / sizeof(set[0]));

    printf("1.Insert \n2.Display\n3.subset\n4.read from file\n5.exit\n");
    while(choice!=5)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatB();
            break;
        case 2:
            Display();
            break;
        case 3:
            displaySets();
            break;
        case 4:
            readdata();
            break;
        case 5:
            exit(0);
        }
    }
}

void insertatB()
{
    int info;
    struct llnode *newnode=(struct llnode*)malloc(sizeof(struct llnode));

    ptr=fopen("llsubset.txt","a");
    if(newnode==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter data:");
        scanf("%d",&info);
        newnode->data=info;
        newnode->next=head;
        head=newnode;
        count++;
        printf("\nNode Inserted successfully !");
    }
    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);

}

void readdata()
{
    int info;
    ptr=fopen("llsubset.txt","r");
    int count=0;
    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct llnode* newnode=(struct llnode*)malloc(sizeof(struct llnode));

        newnode->data = info;
        newnode->next = head;
        head = newnode;
        count++;
    }
    printf("\nData read !");
    fclose(ptr);

}

void Display()
{
    struct llnode* tmp;
    tmp=head;

    if(tmp==NULL)
    {
        printf("List is empty !");
    }
    else
    {
        while(tmp!=NULL)
        {
            printf("%d --> ",tmp->data);
            tmp=tmp->next;
        }
    }

}

void displaySets()
{
    int i,j;
    struct llnode* temp;
    temp=head;

     int info;
    ptr=fopen("llsubset.txt","r");
    int count=0;
    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct llnode* newnode=(struct llnode*)malloc(sizeof(struct llnode));

        newnode->data = info;
        newnode->next = head;
        head = newnode;
        count++;
    }

    while(temp!=NULL)
    {
        for ( i = 0; i < (1 << count); i++)
        {
        printf("{ ");

        for ( j = 0; j < count; j++)
        {
            if ((i & (1 << j)) > 0)
                printf("%d ", temp->data);
        }
        printf("}\n");
        }
        temp=temp->next;
    }
}
