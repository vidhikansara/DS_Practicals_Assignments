#include <stdio.h>
#include <stdlib.h>

struct llnode
{
    int data;
    struct llnode *next;
} *head = NULL;

FILE *ptr;

void insertatB();
void Display();
void find_duplicate();
void readdata();

int main()
{
    int choice;

    printf("1.Insert at Beginning\n2remove duplicate\n3.display\n4.read from file\n5.exit\n");
    while (choice != 5)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatB();
            break;
        case 2:
            find_duplicate();
            break;
        case 3:
            Display();
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
    struct llnode *newnode = (struct llnode *)malloc(sizeof(struct llnode));

    ptr=fopen("deletell.txt","a");
    if (newnode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter data:");
        scanf("%d", &info);
        newnode->data = info;
        newnode->next = head;
        head = newnode;
        printf("\nNode Inserted successfully !");
    }
    fprintf(ptr,"%d\n",info);
    printf("\nData written !");
    fclose(ptr);
}

void readdata()
{
    int info;
    ptr=fopen("deletell.txt","r");

    while(fscanf(ptr,"%d\n",&info)!=EOF)
    {
        struct llnode* newnode=(struct llnode*)malloc(sizeof(struct llnode));

        newnode->data = info;
        newnode->next = head;
        head = newnode;
    }
    printf("\nData read !");
    fclose(ptr);

}

void find_duplicate()
{
    struct llnode *temp;
    struct llnode *temp1;
    struct llnode *duplicate_node;

    temp = head;

    while (temp != NULL)
    {
        temp1 = temp;

        while (temp1->next != NULL)
        {
            if (temp->data == temp1->next->data)
            {
                duplicate_node = temp1->next;
                if (temp->next->next != NULL)
                {
                    temp1->next = temp1->next->next;
                }
                else
                {
                    temp1->next = NULL;
                }
                free(duplicate_node);
                printf("Node Deleted");
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        temp = temp->next;
    }
}

void Display()
{
    struct llnode *tmp;
    tmp = head;

    if (tmp == NULL)
    {
        printf("List is empty !");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("%d --> ", tmp->data);
            tmp = tmp->next;
        }
    }
}
