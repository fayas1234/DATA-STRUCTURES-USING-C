/*Program to Represent a graph using adjacency matrix and calculate the in_degree and out_degree*/

#include <stdio.h>

int adj[30][30];
int ver;

/* Creation of graph  */
void creation(int e)
{
        int i=0,x,y;
        
        printf("Enter the edges:\n\n");
        
        for(i;i<e;i++)
        {
                printf("Enter the edge %d :",i+1);
                scanf("%d",&x);
                scanf("%d",&y);
                
                adj[x][y]=1;
         }
         
}

void main()
{
        
    int e;
    printf("Enter the number of edges:");
    scanf("%d",&e);
        
    printf("\nEnter the number of vertices:");
    scanf("%d",&ver);
        
    creation(e);
	
	int i,out_degree=0,in_degree=0,key;
	
	printf("\nEnter the element whose in_degree and out_degree need to be found:");
	scanf("%d",&key);
	
	for(i=1;i<=ver;i++)
	{
		 out_degree=out_degree+adj[key][i]; /*Row sum*/

	}
	
	for(i=1;i<=ver;i++)
	{
		 in_degree=in_degree+adj[i][key]; /*Column sum*/

	}
	
	printf("in_degree:%d || out_degree:%d\n",in_degree,out_degree);
       
}
