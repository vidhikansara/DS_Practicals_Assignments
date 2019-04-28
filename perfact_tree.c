#include<stdio.h>
#include<stdlib.h>

FILE *ptr;

struct Btree
{
    int data;
    struct Btree* left;
    struct Btree* right;
};
int d;

struct Btree* newnode()
{
    struct Btree* node=(struct Btree*)malloc(sizeof(struct Btree));
    int info;
    int rd;
    printf("\nRead from file 1 otherwise 0 : ");
    scanf("%d",&rd);
    if(rd==1)
    {
        ptr=fopen("Perfacttree.txt","r");
        fscanf(ptr,"%d\n",info);
        node->data=info;
        fclose(ptr);
    }
    else
    {
         printf("\nenter data: ");
        scanf("%d",&info);
        ptr=fopen("Perfacttree.txt","w");
        fprintf(ptr,"%d\n",info);
        fclose(ptr);
        node->data=info;
    }

    node->left=NULL;
    node->right=NULL;

    return(node);
}

int depth(struct Btree* temp)
{
    d=0;
    while(temp!=NULL)
    {
        d++;
        temp=temp->left;
    }
    return d;
}

int perfact(struct Btree* root, int d, int level)
{
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return (d == level+1);

    if (root->left == NULL || root->right == NULL)
        return 0;

    return perfact(root->left, d, level+1) &&
           perfact(root->right, d, level+1);
}

int isPerfect(struct Btree *root)
{
   int d = depth(root);
   return perfact(root, d,0);
}

int main()
{
   // struct Btree* arr[10]={NULL};;
    struct Btree* root=newnode();

    root->left=newnode();
    root->right=newnode();

    root->left->left=newnode();

    printf("\nTree is created !");

    printf("\n");
    if(isPerfect(root))
        printf("\nPefact tree !");
    else
        printf("\nNot perfact tree !");
}


