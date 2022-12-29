//Program to implement queue using stack

#include <stdio.h>

int s1[50],s2[50];
int top1=-1;int top2=-1;

void Enqueue(int item)
{
	while(top1!=-1)
	{
		s2[++top2]=s1[top1--];
	}
	
	s2[++top2]=item;
	
	while(top2!=-1)
	{
		s1[++top1]=s2[top2--];
	}
	
}

void Dequeue()
{
	if(top1==-1)
		printf("\nQueue underflow");
	
	else
	{
		int item=s1[top1--];
		printf("\nThe element Dequeued from the queue is:%d",item);
	}
}


void display()
{
	if(top1==-1)
		printf("\nQueue underflow");
	
	else
	{
		for(int i=top1;i>=0;i--)
		{
			printf("%d\t",s1[i]);
		}
		printf("\n");
	}
}


void main()
{
	int n=1;
	
	while(n)
	{
		int ch;
		printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				int item;
				printf("Enter the item:");
				scanf("%d",&item);
				
				Enqueue(item);
				break;
			}
			
			case 2:
			{
				Dequeue();
				break;
			}
			
			case 3:
			{
				display();
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
