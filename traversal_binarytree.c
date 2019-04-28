#include<stdio.h>
#include<stdlib.h>


struct Btree
{
    int data;
    struct Btree* left;
    struct Btree* right;
};

FILE *ptr;
int count=0;
struct Btree* newnode()
{
    struct Btree* node=(struct Btree*)malloc(sizeof(struct Btree));
    int info;
    int rd;
    int cnt=0;
    printf("\nRead from file 1 otherwise 0 : ");
    scanf("%d",&rd);
    if(rd==1)
    {
        ptr=fopen("binarytraversal.txt","r");
        while(fscanf(ptr,"%d",&info)!=EOF)
        {
            if(count==cnt)
            {
                node->data=info;
                count++;
                break;
            }
            cnt++;
        }
    }
    else
    {
         printf("\nenter data: ");
        scanf("%d",&info);
        ptr=fopen("binarytraversal.txt","a");
        fprintf(ptr,"%d\n",info);
        fclose(ptr);
        node->data=info;
    }

    node->left=NULL;
    node->right=NULL;
    fclose(ptr);
    return(node);
}

struct Btree* queue[100];
int rear=0;
int front=-1;

void enqueue(struct Btree* node)
{
    queue[rear++]=node;
}
struct Btree* dequeue()
{
    return queue[++front];
}

void levelOrder(struct Btree* root)
{
    struct Btree* temp=root;
    while(temp)
    {
        printf("%d\t",temp->data);
        if(temp->left)
            enqueue(temp->left);
        if(temp->right)
            enqueue(temp->right);
        temp=dequeue();
    }
}

void preorder(struct Btree* temp)
{
    if(temp!=NULL)
    {
        printf(" %d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

int main()
{
    struct Btree* root=newnode();

    root->left=newnode();
    root->right=newnode();

    root->left->left=newnode();

    printf("\nTree is created !");

    printf("\n");
    printf("\nLEVEL ORDER : ");
    levelOrder(root);

    printf("\nPre Order : ");
    preorder(root);

}
