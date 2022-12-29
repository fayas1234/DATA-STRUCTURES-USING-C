//Program to check for palindrome string using a stack
#include <stdio.h>
#include <string.h>

int stack[50],top=-1;

void push(int item)
{
	top++;
	stack[top]=item;
}

char pop()
{
	char item=stack[top];
	top--;
	
	return(item);

}


void main()
{
	char str[50];
	printf("Enter the string:");
	scanf("%s",str);
	
	int len=strlen(str);
	
	for(int i=0;i<len;i++)
		push(str[i]);
	
	int flag=1;
	for(int i=0;i<len;i++)
	{
		if(str[i]!=pop())
		{
			flag=0;
			break;
		}
	}
	
	if(flag==1)
		printf("Palindrome");
	else
		printf("Not a palindrome");
}
	
