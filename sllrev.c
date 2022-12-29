//Program to reverse a singly linked list

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

void reverse(ll* ptr)
{
	ll *prev;
	
	prev=start;
	start=start->link;
	ptr=start;
	prev->link=NULL;
	
	
	while(start!=NULL)
	{
		start=start->link;
		
		ptr->link=prev;
	
		prev=ptr;
		ptr=start;
	}
	start=prev;
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
	
	reverse(start);
	
}

	