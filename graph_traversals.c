//Program to implement BFS and DFS

#include <stdio.h>

int adj[30][30];
int stack[30],queue[30];
int ver,top=-1,front=-1,rear=-1;


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




void dfs(int v)
{	
	top=-1;
	char dvisited[30];
    for(int i=0;i<30;i++)
		dvisited[i]='\0';
    int pop_v,j;
    top++;
    stack[top]=v;
    
    while(top>=0)
    {
        pop_v=stack[top];
        top--;
        
        printf("%d\t",pop_v);
        dvisited[pop_v]='t';
        
        for(j=ver;j>=1;j--)
        {
                if(adj[pop_v][j]==1 && dvisited[j]=='\0')
                {
                        top++;
                        stack[top]=j;
                 }
                 
        }
        
     }
     
     printf("\n");
    
}




void bfs(int v)
{
	front=-1;
	rear=-1;
	
		char bvisited[30];
        for(int i=0;i<30;i++)
			bvisited[i]='\0';
        int pop_v,j;
        front++;
        rear++;
        
        queue[rear]=v;
        bvisited[v]='t';
        
        printf("%d\t",v);
        
        while(front<=rear)
        {
                pop_v=queue[front];
                front++;
                
                for(j=1;j<=ver;j++)
                {
                        
                        if(adj[pop_v][j]==1 && bvisited[j]=='\0')
                        {
                                printf("%d\t",j);
                                bvisited[j]='t';
                                rear++;
                                queue[rear]=j;
                         }
                    
                 
                }
              
        }
        printf("\n");    
        
}




void main()
{
        printf("!!!Creation!!!\n\n");
        
        int e;
        printf("Enter the number of edges:");
        scanf("%d",&e);
        
        printf("\nEnter the number of vertices:");
        scanf("%d",&ver);
        
        creation(e);
        
        int n=1;
        
        printf("\n1-DFS\n2-BFS\n3-exit\n");
        
        while(n)
        {
                int ch;
                
                printf("\nEnter your choice:");
                scanf("%d",&ch);
                
                switch(ch)
                {
                        case 1:
                        {
                                int v;
                                printf("\nEnter the starting vertex:");
                                scanf("%d",&v);
                                dfs(v);
                                break;
                        }
                        
                        
                        case 2:
                        {
                              int v;
                              printf("\nEnter the starting vertex:");
                              scanf("%d",&v);
                              bfs(v);
                              break;  
                        
                        }
                        
                        case 3:
                        {
                                n=0;
                                break;
                        }
                        
                 }
                 
         }
}
