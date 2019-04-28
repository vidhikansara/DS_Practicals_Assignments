#include<stdio.h>
#include<stdlib.h>


struct dbnode
{
    int data;
    struct dbnode* next;
    struct dbnode* prev;
}*head=NULL;

FILE *ptr,*ft;

void insertatB();
void insertatL();
void insertatpos();
void display();
void deleteatB();
void deleteatL();
void deleteatpos();
void readdata();

int main()
{
    int choice;


    while(choice!=9)
    {
        printf("\n1.Insert at beginning\n2.Insert at last\n3.Insert at position\n4.Delete at beginning\n5.Delete at last\n6.Delete at position\n7.Display\n8.read from file\n9.exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatB();
            break;
        case 2:
            insertatL();
            break;
        case 3:
            insertatpos();
            break;
        case 4:
            deleteatB();
            break;
        case 5:
            deleteatL();
            break;
        case 6:
            deleteatpos();
            break;
        case 7:
            display();
            break;
        case 8:
            readdata();
            break;
        case 9:
            exit(0);
        }
    }
}

void insertatB()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));

    int info;
    printf("Enter Data: ");
    scanf("%d",&info);

    ptr=fopen("doublyllfile.txt","a");

    if(newnode==NULL)
    {
        printf("Overflow !");
    }
    else
    {
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            newnode->data=info;
            head=newnode;
        }
        else
        {
            newnode->data=info;
            newnode->next=head;
            newnode->prev=NULL;
            head->prev=newnode;
            head=newnode;
        }
        printf("\nINSERTED AT FIRST");
    }

    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);
}



void insertatL()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* tmp;

    int info;
    printf("\nEnter data: ");
    scanf("%d",&info);

    ptr=fopen("doublyllfile.txt","a");

    if(newnode==NULL)
    {
        printf("\nOverflow !");
    }
    else
    {
        newnode->data=info;
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
        }
        else
        {
            tmp=head;
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            tmp->next=newnode;
            newnode->prev=tmp;
            newnode->next=NULL;
        }
        printf("\nINSERTED AT LAST");
    }

    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);
}

void insertatpos()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* tmp;

    int loc,i;
    int info;

    ptr=fopen("doublyllfile.txt","a");

    if(newnode==NULL)
    {
        printf("\nOverflow !");
    }
    else
    {
        printf("\nEnter location: ");
        scanf("%d",&loc);
        printf("\nEnter data: ");
        scanf("%d",&info);
        tmp=head;
        for(i=1;i<loc;i++)
        {
            tmp=tmp->next;
            if(tmp==NULL)
            {
                printf("\nList is empty !");
            }
        }
        newnode->data=info;
        newnode->next=tmp->next;
        newnode->prev=tmp;
        tmp->next=newnode;
        tmp->next->prev=newnode;
        printf("\nNODE INSERTED !");
    }

    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);
}

void display()
{
    struct dbnode* tmp;

    if(head==NULL)
    {
        printf("\nList is empty !");
    }
    else
    {
        tmp=head;
        while(tmp!=NULL)
        {
            printf("%d ==> ",tmp->data);
            tmp=tmp->next;
        }
    }
}

void deleteatB()
{
    int data,info;
    struct dbnode* tmp;

    if(head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if(head->next == NULL)
    {
        data=head->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        tmp = head;
        head = head -> next;
        head -> prev = NULL;
        data=tmp->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        free(tmp);
        printf("\nNode Deleted\n");
    }
}

void readdata()
{

        ptr=fopen("doublyllfile.txt","r");

        int info;
        struct dbnode* temp;
        temp=head;
        if(temp!=NULL)
        {
            while(temp!=NULL)
            {
                deleteatB();
            }
        }

        while(fscanf(ptr,"%d\n",&info)!=EOF)
        {
            struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));

            if(head==NULL)
            {
                newnode->next=NULL;
                newnode->prev=NULL;
                newnode->data=info;
                head=newnode;
            }
            else
            {
                newnode->data=info;
                newnode->next=head;
                newnode->prev=NULL;
                head->prev=newnode;
                head=newnode;
            }
        }

        printf("\nData Read !");

    fclose(ptr);

}

void deleteatL()
{
    int data,info;
    struct dbnode* tmp;

    if(head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if(head->next == NULL)
    {
        data=head->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        tmp = head;
        if(tmp->next != NULL)
        {
            tmp = tmp -> next;
        }
        data=tmp->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        tmp -> prev -> next = NULL;
        free(tmp);
        printf("\nNode Deleted\n");
    }
}

void deleteatpos()
{
    struct dbnode *pre,*tmp;
    int data,info;

    int val;
    printf("Enter the value");
    scanf("%d",&val);
    tmp = head;
    while(tmp -> data != val)
    tmp = tmp -> next;
    if(tmp -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(tmp -> next -> next == NULL)
    {
        data=tmp->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        tmp ->next = NULL;
        printf("\nNode Deleted\n");
    }
    else
    {
        pre = tmp -> next;
        tmp -> next = pre -> next;
        pre -> next -> prev = tmp;
        data=pre->data;
        ptr=fopen("doublyllfile.txt","r");
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
        remove("doublyllfile.txt");
        rename("tempdata.txt","doublyllfile.txt");

        free(pre);
        printf("\nNode Deleted\n");
    }
}

