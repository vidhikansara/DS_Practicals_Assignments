#include<stdio.h>
#include<stdlib.h>

FILE *ptr;
int visited[10];
int adj_mat[50][50];
int vertex;
int edges;
char filename[10];
int queue[100];
int front=0,rear=-1;
//float popular[20][2]={0.0};

void dfs(int vertex,int i)
{
    int j;
    visited[i]=1;
	printf("%d ",i);
	for(j=0;j<vertex;j++)
    {
        if(!visited[j]&&adj_mat[i][j]==1)
        {
            dfs(vertex,j);
        }
    }

}

void dfsundirected(int vertex, int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < vertex; j++)
    {
        if (!visited[j] && adj_mat[i][j] != 0)
        {
            dfsundirected(vertex, j);
        }
    }
    for (j = 0; j < vertex; j++)
    {
        if (!visited[j] && adj_mat[j][i] != 0)
        {
            dfsundirected(vertex, j);
        }
    }
}

void bfs(int vertex,int v,int front,int rear)
{
    int i;
    printf("%d ", v);
	for(i = 0; i <=vertex; i++)
    {
        if(adj_mat[v][i]!=0 && visited[i]==0)
        {
            queue[++rear] = i;
        }
    }
	if(front <= rear && visited[queue[front]]==0)
    {
		visited[queue[front]] = 1;
		front++;
		bfs(vertex,queue[front-1],front,rear);
	}

}

void bfsundirected()
{
    int i;
    printf("%d ", i);
    int j, k;
}
void readUnidrected(int adj_mat[50][50],int vertex,int edges)
{
    int i, j;
    int node1,node2,distance;
    ptr=fopen(filename,"r");
    for ( i = 0 ; i < vertex ; i++ )
    {
        for ( j = 0 ; j < vertex ; j++ )
        {
                adj_mat[i][j] = 0;
        }
    }
   // fseek(ptr,1,SEEK_CUR);
    for(i=0;i<edges;i++)
    {
        fscanf(ptr, "%d %d %d", &node1, &node2, &distance);
                adj_mat[node1][node2]=distance;
    }
    fclose(ptr);
}

int read_graph ( int adj_mat[50][50], int vertex ,int edges)
{
    int i, j;
    int node1,node2;
    ptr=fopen(filename,"r");
    for ( i = 0 ; i < vertex ; i++ )
    {
        for ( j = 0 ; j < vertex ; j++ )
        {
                adj_mat[i][j] = 0;
        }
    }
   // fseek(ptr,1,SEEK_CUR);
    for(i=0;i<edges;i++)
    {
        fscanf(ptr, "%d %d", &node1, &node2);
                adj_mat[node1][node2]=1;
    }
    fclose(ptr);
    return 0;
}
void printDirected(int vertex)
{
    float popular[20];
    read_graph(adj_mat,vertex,edges);
    float in_deg=0.0, out_deg=0.0;
    int i, j;

        for (i = 0; i < vertex ; i++ )
        {
            in_deg = out_deg = 0;
            for ( j = 0 ; j < vertex ; j++ )
            {
                if ( adj_mat[j][i] == 1 )
                {
                    in_deg+=1;
                }
                if (adj_mat[i][j] == 1 )
                {
                    out_deg+=1;
                }
            }

            popular[i]=in_deg/out_deg;
          if(popular[i]>=2)
            {
                printf("\nPerson %d IS POPULAR. Popularity score: %0.1f. Followed by: %.0f. Follows: %.0f.\n",i,popular[i],in_deg,out_deg);
            }
            else
            {
                printf("\nPerson %d NOT POPULAR. Popularity score: %0.1f. Followed by: %.0f. Follows: %.0f.\n",i,popular[i],in_deg,out_deg);
            }
        }

}

void printfUndirected()
{
    int friend_present, i, j;
    int distance[50];
    readUnidrected(adj_mat, vertex,edges);
   // printf("\n Vertex \t Degree\t Distance ");
    for ( i = 0 ; i < vertex ; i++ )
    {
        friend_present = 0;
        for ( j = 0 ; j < vertex ; j++ )
        {
            adj_mat[i][j]=adj_mat[j][i]=distance[i];
            if ( adj_mat[i][j] == 1)
                friend_present++;
        }
        printf("\nPerson %d has %d friends and days %d",i,friend_present,distance[i]);
    }
}

void directed_unweighted()
{
    int i;

    read_graph(adj_mat, vertex,edges);
        for(i=0;i<vertex;i++)
                visited[i]=0;

        printf("\nDFS Traversal :- ");
        dfs(vertex,0);
        printf("\nBFS Traversal :- ");
        for (i = 0; i < vertex; i++)
        {
            visited[i] = 0;
        }
        visited[0] = 1;
        bfs(vertex, 0, 0, -1);
}


void Unidrected_traversal()
{
    readUnidrected(adj_mat,vertex,edges);
    printf("\nDFS Traversal :- ");
        dfsundirected(vertex,0);

}


int main()
{
    int ifdirected,ifweighted;

    while(filename[4]!="EXIT")
    {
        printf("\nEnter the name of a social media graph file (EXIT when finished): ");
        scanf("%s",filename);
        ptr=fopen(filename,"r");

        if (ptr != NULL)
        {

            printf("\nUsing file : %s",filename);

            fscanf(ptr, "%d %d\n",&ifdirected,&ifweighted);
            printf("\nGraph is ");
            if(ifdirected==1)
            {
                printf("directed, ");
            }
            else
                printf("Undirected, ");
            if(ifweighted==0)
                printf("unweighted ");
            else
                printf("weighted ");


            fscanf(ptr, "%d %d\n",&vertex,&edges);
            printf("and has %d nodes and %d edges .",vertex,edges);

            if(ifdirected && !ifweighted)
            {
                directed_unweighted();
                printDirected(vertex);
            }
            if(ifdirected==0 && ifweighted==1)
            {
                Unidrected_traversal();
                printfUndirected();
            }

            fclose(ptr);

        }
        else
        {
            printf("\nFile not found !");
        }

    }



    return 0;
}

