//Program to implement hash table
#include <stdio.h>

int hash[50];
int size,count=0;

int hashfunc(int key)
{
	int index=key%size;
	return(index);
}

void display()
{
	for(int i=0;i<size;i++)
		printf("%d\t",i);
	printf("\n");
	
	for(int i=0;i<size;i++)
	{
		if(hash[i]!=0)
			printf("%d\t",hash[i]);
		else
			printf("-\t");
	}

}

void insert(int key)
{
	int index=hashfunc(key);
	
	if(count==size)
	{
		printf("\nAraay full insertion not possible");
	}
	
	else
	{
		int temp=index;
		for(int i=0;i<size;i++)
		{
			if(hash[index]==0)
			{
				hash[index]=key;
				count++;
				break;
			}
			else
			{
				index=hashfunc(temp+i);
			}
		}
		display();
		
	}

}


int search(int key)
{
	int index=hashfunc(key);
	
	int temp=index;
	for(int i=0;i<size;i++)
	{
		if(hash[index]==key)
		{
			return(index);
		}
		else
		{
			index=hashfunc(temp+i);
		}
	}
	return(-1);

}

void delete(int key)
{
	int index=search(key);
	
	if(index==-1)
		printf("\nElement not found");
	
	else
	{
		hash[index]=0;
		display();
	}
}


/*  main */
void main()
{
	printf("Hash table by using linear probing\n\n");
	printf("1-Insert\n2-Delete\n3-Search\n4-Exit\n");  
	
	int ch,n=1,item,key;
	
	printf("\nEnter the size of the hash table:");
	scanf("%d",&size);
	
	while(n)
	{
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				int key;
				printf("\nEnter the item:");
				scanf("%d",&key);
				
				insert(key);
				break;
				
				
			}
			
			case 2:
			{
				int key;
				printf("\nEnter the item to be deleted:");
				scanf("%d",&key);
				delete(key);
				break;
			}
			
			case 3:
			{
				int key;
				printf("\nEnter the item to be searched:");
				scanf("%d",&key);
				
				int index=search(key);
				if(index!=-1)
				{
					printf("\nElement found at position:%d",index);
				}
				else
				{
					printf("\nElement not found");
				}
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