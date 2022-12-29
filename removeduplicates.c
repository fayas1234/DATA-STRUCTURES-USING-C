//Program to implement RemoveDuplicates()

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
	int data;
	struct node *link;
};

typedef struct node ll;
ll *start=NULL;


void create()
{
	ll *new,*ptr;
	
	new=(ll*)malloc(sizeof(ll));
	new->link=NULL;
	
	printf("\nEnter the first element:");
	scanf("%d",&new->data);
	start=new;
	ptr=new;
	
	char ch;
	do
	{
		
		
		new=(ll*)malloc(sizeof(ll));
		new->link=NULL;
		
		printf("\nEnter the next element:");
		scanf("%d",&new->data);
		
		ptr->link=new;
		ptr=new;
		
		printf("Do you want to continue:");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
	
	ptr=start;
	
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}

void RemoveDuplicates()
{
	ll *ptr,*after,*prev;
	
	ptr=start;
	after=ptr->link;
	
	if(start==NULL)
		printf("\nNo linked list exists");
	
	else
	{
		if(start->data == after->data)
		{
			prev=start;
			start=start->link;
			free(prev);
			after=after->link;
			ptr=start;
		}
		
		while(after!=NULL)
		{
			if(ptr->data==after->data)
			{
				ptr->link=after->link;
				prev=after;
				after=after->link;
				free(prev);
			}
			
			else
			{
				after=after->link;
				ptr=ptr->link;
			}
		}
		
	}
	
	ptr=start;
	
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}

void main()
{
	create();
	
	ll* node;
	node=(ll*)malloc(sizeof(ll));
	
	RemoveDuplicates();
	
}
