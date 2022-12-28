//Program to implement priority queue
#include <stdio.h>
#define size 10


struct pq
{
	int item;
	int priority;
};

struct pq queue[size]; /*Queue which is an array of structure*/
int rear=-1,front=-1;
struct pq temp;


void display()
{
	printf("\nitem||priority\n");
	if(front==-1)
		printf("\nQueue Underflow");
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d||%d\t",queue[i].item,queue[i].priority);
			
		}
		printf("\n");
	}
}

void Enqueue(int item,int priority)
{
	if(rear==size-1)
		printf("\nQueue overflow");
	
	else	
	{
		rear++;
		queue[rear].item=item;
		queue[rear].priority=priority;
		
		if(front==-1)
			front++;
	}
	
	/* Sorting based on priority by using Selection sort*/
	
	int i,j,index;
		
	for(i=front;i<rear;i++)
	{
		index=i;
		for(j=i+1;j<=rear;j++)
		{
			if(queue[j].priority<queue[index].priority) /*Sorting in ascending order by the assumption that minimum number has the highest priority*/ 
			{
					index=j;
			}
		}
		temp=queue[i];
		queue[i]=queue[index];
		queue[index]=temp;
			
	}
	
	display();
}


void Dequeue()
{
	if(front==-1)
	{
		printf("\nQueue underflow");
		return;
	}
	else
	{
		int item;
		item=queue[front].item;
		
		printf("\nThe item removed from the queue is:%d\n",item);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front++;
		}
	}
	display();	
}



void Find()
{
	if(front==-1)
	{
		printf("\nQueue underflow");
		return;
	}
	else
	{
		int item;
		item=queue[front].item;
		
		printf("\nThe item having highest priority from the queue is:%d\n",item);
	}	
}

void main()
{
	printf("1-Enqueue\n2-Dequeue\n3-Find item with highest priority\n4-Exit\n");  
	
	int ch,n=1,item,key;
	
	while(n)
	{
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				int item,priority;
				
				printf("Enter the item and priority in order:");
				scanf("%d %d",&item,&priority);
				
				Enqueue(item,priority);
				break;
			}
			
			case 2:
			{
				Dequeue();
				break;
			}
			
			case 3:
			{
				Find();
				break;
			}
			
			case 4:
			{
				n=0;
				break;
			}
				
		}
		
	}
	
}