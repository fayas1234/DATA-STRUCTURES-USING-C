//Program to implement two stacks in an array

#include<stdio.h>

int arr[50];
int topa=-1,topb=50;


void pusha(int item)
{
	if(topa==topb-1)
		printf("Stack A overflow");
	
	else
	{
		topa++;
		arr[topa]=item;
		
	}
}

void pushb(int item)
{
	if(topb==topa+1)
		printf("Stack B overflow");
	else
	{
		topb--;
		arr[topb]=item;
	}
	
}

int popa()
{
	if(topa==-1)
		printf("Stack A underflow");
	else
	{
		int item=stack[topa];
		topa--;
		return(item);
	}
}

int popb()
{
	if(topb==50)
		printf("Stack A underflow");
	else
	{
		int item=stack[topa];
		topa++;
		return(item);
	}
}

