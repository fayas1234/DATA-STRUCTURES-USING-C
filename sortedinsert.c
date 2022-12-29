//Program to implement SortedInsert()

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

void SortedInsert(ll *node)
{
	ll *ptr,*after;
	int item=node->data;
	
	if(start==NULL)
		printf("\nNo linked list exists");
	
	else if(item<start->data)
	{
		node->link=start;
		start=node;
	}
	
	else
	{
		ptr=start;
		after=ptr->link;
		
		while(after!=NULL)
		{
			if(item>after->data){
			ptr=ptr->link;
			after=after->link;
			}
			else
				break;
		}
		
		ptr->link=node;
		node->link=after;
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
	
	printf("\nEnter the item to be inserted:");
	scanf("%d",&node->data);
	
	SortedInsert(node);
	
}