//Program to check for balanced brackets

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stack[50];
int top=-1;

int same(char c1,char c2);

void main()
{
	char str[50];
	printf("Enter a string of brackets:");
	scanf("%s",str);
	
	
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='{' || str[i]=='[' || str[i]=='(')
			stack[++top]=str[i];
		
		else
		{
			if(top==-1)
			{
				printf("\nNot balanced");
				exit(0);
				break;
			}
			
			else
			{
				if(same(stack[top--],str[i])!=1)
				{
					printf("\nNot balanced");
					exit(0);
					break;
				}
			}
		}
	
	}
	if(top==-1)
		printf("\nBalanced");
	else
		printf("\nNot balanced");
}


int same(char c1,char c2)
{
	if(c1=='[' && c2==']')
		return(1);
	else if(c1=='{' && c2=='}')
		return 1;
	else if(c1=='(' && c2==')')
		return 1;
	
}
