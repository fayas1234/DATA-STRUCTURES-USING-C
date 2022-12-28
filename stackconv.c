//Program to implemet stack conversions 
#include <stdio.h>
#include <string.h>
#include <math.h>
#define s 50
char input[50],stack[s];
int top=-1;

float evaluate(char symbol, float x, float y)
{

 switch (symbol)
 {

  case '+': return(x+y);

  case '-': return(x-y);

  case '*': return(x*y);

  case '/': return(x/y);
  
  case '^': return(pow(x,y));

 }

}

void push(char item)
{
	top++;
	stack[top]=item;
}

void reverse(char str[])
{
		int length,i,j;
		j=0;
		
		length=strlen(str);
	
		
		char temp;
		
		for(i=length-1;i>j;i--)
		{
			temp=str[j];
			str[j]=str[i];
			
			str[i]=temp;
			j++;
		}
		

		
		
}

char pop()
{
	char item;
	
	item=stack[top];
	top--;
	return(item);
}

int prec(char symbol)
{
	switch(symbol)
	{
		
		case '+':
		{
			return 1;
			
		}
			
		case '-':
		{
			return 1;	
		}
			
		case '*':
		{
			return 2;	
		}
			
		case '/':
		{
			return 2;	
		}
			
		case '^':
		{
			return 3;
		}
		
		case '(':
		{
			return 0;
		}
		
		case ')':
		{
			return 0;
		}
	}
	
}
	

void infix_to_postfix(char infix[])
{
	int length,i=0,pos=0;
	char symbol,temp;
	
	char postfix[50];
	length=strlen(infix);
	
	while(i<length)
	{
		symbol=infix[i];
		
		switch(symbol)
		{
			case '(':
			{
				push(symbol);
				break;
				
			}
			case ')':
			{
				temp=pop();
				while(temp!='(')
				{
					postfix[pos]=temp;
					pos++;
					temp=pop();
				}
			
				break;
			}
			
			case '+':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '-':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '*':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '/':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '^':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			default:
			{
				postfix[pos]=symbol;
				pos++;
				break;
			}
		}
		i++;
		
		
	}
	while(top>=0)
	{
		temp=pop();
		postfix[pos]=temp;
		pos++;
	}
		
	postfix[pos]='\0';
	printf("The postfix expression is:");
	puts(postfix);
	
}


void infix_to_prefix(char infix[])
{
	int length,i=0,pos=0;
	char symbol,temp;
	
	char prefix[50];
	length=strlen(infix);
	
	while(i<length)
	{
		symbol=infix[i];
		
		switch(symbol)
		{
			case ')':
			{
				push(symbol);
				break;
				
			}
			
			case '(':
			{
				temp=pop();
				while(temp!=')')
				{
					prefix[pos]=temp;
					pos++;
					temp=pop();
				}
			
				break;
			}
			
			case '+':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					prefix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '-':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					prefix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '*':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					prefix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '/':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					prefix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			case '^':
			{
				while(prec(stack[top])>=prec(symbol))
				{
					temp=pop();
					prefix[pos]=temp;
					pos++;
				}
				push(symbol);
				break;
			}
			
			default:
			{
				prefix[pos]=symbol;
				pos++;
				break;
			}
		}
		i++;
		
		
	}
	while(top>=0)
	{
		temp=pop();
		prefix[pos]=temp;
		pos++;
	}
		
	prefix[pos]='\0';
	printf("The prefix expression is:");
	reverse(prefix);
	puts(prefix);
	
}



/* main */
void main()
{
	
	printf("1-Conversion to postfix\n2-Coversion to prefix\n3-Evaluation of postfix\n4-Evaluation of prefix\n5-Exit\n");
	
	int ch;
	int n=1;
	
	while(n==1)
	{
		printf("Enter your choice:");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				top=-1;
				printf("Enter the infix expression:");
				scanf("%s",input);
				
				infix_to_postfix(input);
				break;
			}
			
			
			case 2:
			{
				top=-1;
				printf("Enter the infix expression:");
				scanf("%s",input);
				
				reverse(input);
				
				infix_to_prefix(input);
				break;
			}
			
			case 3:
			{
				int top=-1,i;
				float stack[50],result,x,y;

				char postfix[50],symbol;

				printf("Enter the postfix expression:");
				scanf("%s",postfix);

				int length=strlen(postfix);

				for (i=0;i<length;i++)
				{

					symbol=postfix[i];
					
					if(isdigit(symbol))
						stack[++top]=symbol-'0'; //To get the digit from ASCII

					else
					{
						y=stack[top--];
						x=stack[top--];
						result=evaluate(symbol,x,y);
						stack[++top]=result;
					}
					
				}
				result=stack[top--];
				printf("The value of the postfix expression is:%f\n",result);
				break;
			}
			
			case 4:
			{
				int top=-1,i;
				float stack[50],result,x,y;

				char prefix[50],symbol;

				printf("Enter the prefix expression:");
				scanf("%s",prefix);

				int length=strlen(prefix);
				reverse(prefix);
				
				for (i=0;i<length;i++)
				{

					symbol=prefix[i];
			
					if(isdigit(symbol))
						stack[++top]=symbol-'0'; //To get the digit from ASCII

					else
					{
						x=stack[top--];
						y=stack[top--];
						result=evaluate(symbol,x,y);
						stack[++top]=result;
					}
					
				}
				result=stack[top--];
				printf("The value of the postfix expression is:%f\n",result);
				break;
				
				
			}
			case 5:
			{
				n=0;
				break;
			}
			
			
		}
		
	}
	
}
		