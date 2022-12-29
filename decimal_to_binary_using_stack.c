//Program to convert decimal to binary using stack
#include <stdio.h>
int stack[50];
int top=-1;





void main()
{
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	
	int d;
	
	while(n>0)
	{
		d=n%2;
		n=n/2;
		
		stack[++top]=d;
	}
	
	while(top!=-1)
	{
		int item=stack[top--];
		printf("%d\t",item);
	
	}
	printf("\n");
	
	
}
