//Program to implement stack using two queues

#include<stdio.h>
int q1[50],q2[50];

int f1=-1;int r1=-1;
int f2=-1;int r2=-1;

void Enqueue1(int item);
int Dequeue1();

void Enqueue2(int item);
int Dequeue2();

void push(int item);
void pop();


void main()
{
	int n=1;
	
	while(n)
	{
		int ch;
		printf("\n1-push\n2-pop\n3-display\n4-exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				int item;
				printf("Enter the item:");
				scanf("%d",&item);
				
				push(item);
				break;
			}
			
			case 2:
			{
				pop();
				break;
			}
			
			case 3:
			{
				for(int i=f1;i<=r1;i++)
					printf("%d\t",q1[i]);
				printf("\n");
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



void push(int item)
{
	Enqueue2(item);
	
	while(f1!=-1)
	{
		int item=Dequeue1();
		Enqueue2(item);
	}
	
	while(f2!=-1)
	{
		int item=Dequeue2();
		Enqueue1(item);
	}
	
}

void pop()
{
	if(f1==-1)
		printf("\nStack Underflow");
	
	else
	{
		int item=Dequeue1();
		printf("The element poped is:%d",item);
	}
}


void Enqueue1(int item)
{
	if(f1==-1)
		f1++;
	r1++;
	q1[r1]=item;
}

int Dequeue1()
{
	int item=q1[f1];
	if(f1==r1)
		f1=r1=-1;
	else
		f1++;

	return(item);
	
}


void Enqueue2(int item)
{
	if(f2==-1)
		f2++;
	r2++;
	q2[r2]=item;
}

int Dequeue2()
{
	int item=q2[f2];
	if(f2==r2)
		f2=r2=-1;
	else
		f2++;

	return(item);
	
}
