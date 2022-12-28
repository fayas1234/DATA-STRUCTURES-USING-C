//Program to reverse the contengt of a queue using stack

#include <stdio.h>
#define s 50

int front=-1,rear=-1,top=-1,newfront=0;



int stack[s],queue[s];

void display()
{
	if(front==-1)
		printf("Queue Underflow\n");
	
	else
	{
		int i;
		
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
		
		
	}
}


void Enqueue(int item)
{
	if(rear==s-1)
	{
		printf("Queue overflow\n");
	}
	
	else
	{
		rear++;
		
		queue[rear]=item;
		
		if(front==-1)
			front=0;
		
	}
	
	
}

int Dequeue()
{
	if(front==-1)
		return(-1);
    
	else
	{
		int item=queue[front];
		
		
		
		if(front==rear)
	    {
			front=-1;
			
		}
		
		else
		{
			front++;
		}
		
		return(item);
		
	}
}


void push(int item)
{
	top++;
	stack[top]=item;
}


int pop()
{
	int item=stack[top];
	
	top--;
	return(item);
	
}



void main()
{
	
	
	int n=1;
	int ch;
	
	
	while(n)
	{
		printf("\n1-Create a queue or Insert element to an existing queue\n2-Reverse a queue using stack\n3-Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
				
				
			    int num=1;
				
				while(num)
				{
					
					printf("\nEnter your choice:");
					scanf("%d",&ch);
					
					switch(ch)
					{
						case 1:
						{
							int item;
							
							printf("\nEnter the element:");
							scanf("%d",&item);
							
							Enqueue(item);
							break;
						}
						
						case 2:
						{
							Dequeue();
							
							newfront=front;
							break;
						}
						
						case 3:
						{
							display();
							
							
							break;
						}
						
						case 4:
						{
							num=0;
							break;
						}
					}
				}
				
				break;
			}
			
			case 2:
			{
				
				
				int item;
				
				
				while(front!=-1)
				{
					item=Dequeue();
					
					push(item);
					
					
				
				}
				
				front=newfront;
				
				int i=front;
				while(top!=-1)
				{
					item=pop();
					
					
					queue[i]=item;
					i++;
		
				}
				printf("The reversed queue is:\n");
				for(i=front;i<=rear;i++)
				{
						item=queue[i];
						printf("%d\t",item);
						
				}
				printf("\n");
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