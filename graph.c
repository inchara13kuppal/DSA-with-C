//Program to implement a GRAPH using Adjacency Matrix1
#include <stdio.h>
#include <stdlib.h>

int adj[10][10];
int visit[5];

void creategraph(int);
void dfs(int,int);
void display(int);

void main()
{
	int n,i,v;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	creategraph(n);
	
	for (i=1;i<=n;i++)
		visit[i]=0;
	
	printf("Enter the start vertex: ");
	scanf("%d",&v);
	
	printf("DFS Traversal: ");
	dfs(v,n);  //function to traverse --- depth first search---------
	printf("\n");
	display(n);
}

void creategraph(int n)
{
	int i,j;
	while(1)
	{
		printf("Enter the source and destination vertex: ");
		scanf("%d%d",&i,&j);
		if (i==0 & j==0) break;

		//else adj[i][j]=1; //directed graph

        else { //undirected graph
            adj[i][j]=1;
            adj[j][i]=1;
        }
	}
}

void display(int n)
{
	int p,q;
	printf("The Graph contains.. (adjancency matrix)\n");
	for(p=1;p<=n;p++)
	{
		for(q=1;q<=n;q++)
			printf("%d\t",adj[p][q]);
		printf("\n");
	}
}

void dfs(int v,int n)
{
	int w;
	visit[v]=1;
	printf("%d  ",v);
	
	for (w=1;w<=n;w++)
	{
		if (visit[w]==0 && adj[v][w]==1) //v is start vertex w are neighbours
			dfs(w,n);
	}	
}