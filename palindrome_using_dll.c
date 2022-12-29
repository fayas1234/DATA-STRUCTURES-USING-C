//Program to check for palindrome string using DoublyLinkedList

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node* llink;
	struct node* rlink;
	
};

typedef struct node NODE;

NODE* start=NULL;


void insert_beg_DLL(char item) /*Here DLL implemented like Stack*/
{
	NODE *new;
	
	new=(NODE*)malloc(sizeof(NODE));
	new->data=item;
	
	new->llink=NULL;
	
	if(start==NULL) //Empty Linked List
	{
		new->rlink=NULL;
		start=new;
	}
	else{
		
	new->rlink=start;
	start=new;
	}
	
	
}

char get_beg_DLL()
{
	NODE* ptr;
	
	if(start->rlink==NULL)
	{
		
		ptr=start;
		
		char item=ptr->data;
		
		free(ptr);
		
		return(item);
	}
	
	else
	{
		ptr=start;
	
		start=start->rlink;
		start->llink=NULL;
	
	
		char item=ptr->data;
	
		free(ptr); /*Freeing up node as no longer needed*/
	
		return(item);
	}
	
	
	
	
}

void main()
{
	char str[50];
	
	printf("Enter a string:");
	
	scanf("%s",str);
	
	int i;
	
	int length=strlen(str); /*To find the length of the string*/
	
	for(i=0;i<length;i++)
	{
		
		insert_beg_DLL(str[i]); /*Creation of DLL with the charcters of the string*/
		
	}
	
	
	int flag=1;
	
	for(i=0;i<length;i++)
	{
		char item=get_beg_DLL();
		
		
		if(str[i]!=item) /*Checking for unmatched characters*/
		{
			
			flag=0;
			break;
		}
		

	}
	

	if(flag==1)
	{
		printf("\nPalindrome string");
	}
	
	else
	{
		printf("\nNot a Palindrome string");
	}
}

	
	
