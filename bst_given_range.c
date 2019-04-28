#include <stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

FILE *ptr;

struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        else
            root->left = CreateBST(root->left,item);

        return(root);
    }
}

void Printvalues(struct tnode *root, int v1, int v2)
{
   if ( root==NULL )
      return;

   if ( v1 < root->data )
     Printvalues(root->left, v1, v2);

   if ( v1 <= root->data && v2 >= root->data )
     printf("%d ", root->data );

   if ( v2 > root->data )
     Printvalues(root->right, v1, v2);
}

int main()
{
    int v1,v2;
    int n,i,item;
    int rd;
    struct tnode *root = NULL;

    printf("\nRead from file press 1 otherwise 0: ");
    scanf("%d",&rd);
    if(rd==1)
    {
        ptr=fopen("bstprint.txt","r");
        while(fscanf(ptr,"%d\n",&item)!=EOF)
        {
            root = CreateBST(root,item);
        }
        printf("\nData read !");
        fclose(ptr);

    }
    else
    {
        ptr=fopen("bstprint.txt","a");
        printf("\n\nHow Many Nodes ? ");
        scanf("%d",&n);

        for(i = 1; i <= n; i++)
        {
            printf("\nEnter data : ");
            scanf("%d",&item);
            fprintf(ptr,"%d\n",item);
            root = CreateBST(root,item);
        }

        fclose(ptr);
    }


    printf("\nEnter value for v1 and v2: ");
    scanf("%d %d",&v1,&v2);

    Printvalues(root,v1,v2);
}
