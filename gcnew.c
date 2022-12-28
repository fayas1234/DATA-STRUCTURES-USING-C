/*Program to implement garbage collection */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int size;
	struct node* rlink;
	struct node* llink;
};

typedef struct node node;

node* avail=NULL;

void create()
{
	node *ptr,*new;
	
	new=(node*)malloc(sizeof(node));
	avail=new;
	ptr=new;
	
	new->size=2;
	new->llink=NULL;
	new->rlink=NULL;
	
	for(int i=2;i<=5;i++)
	{
		new=(node*)malloc(sizeof(node));
		new->size=2*i;
		ptr->rlink=new;
		new->llink=ptr;
		new->rlink=NULL;
		
		ptr=new;
		
	}
	
}


node* GetNode(int mem)
{
	node *ptr,*ptr1;
	if(avail==NULL)
	{
		printf("\nMemory bank insufficient");
		return(NULL);
	}
	
	else if(avail->size>=mem)
	{
		ptr=avail;
		avail=avail->rlink;
		if(avail==NULL)
		{
			return(ptr);
		}
		
		else
		{
			avail->llink=NULL;
			return(ptr);
		}
	}
	else
	{
		ptr=avail;
		while(ptr->rlink!=NULL && ptr->size<mem)
		{
			ptr1=ptr;
			ptr=ptr->rlink;
		}
		
		if(ptr->rlink==NULL &&	ptr->size<mem)
		{
			printf("Memory request is too large");
			return(NULL);
		}
		
		else
		{
			ptr1->rlink=ptr->rlink;
			return(ptr);
			
		}
		
	}
	
}

			
node* ReturnNode(node *p)
{
	node *ptr,*ptr1;
	
	if(avail->size>=p->size)
	{
		p->rlink=avail;
		p->llink=NULL;
		avail->llink=p;
		avail=p;
	
	}
	
	else{
	ptr=avail;
	while(ptr->rlink!=NULL && ptr->size<p->size)
	{
		ptr1=ptr;
		ptr=ptr->rlink;
	}
	
	if(p->size<ptr->size)
	{
		ptr1->rlink=p;
		p->rlink=ptr;
		ptr->llink=p;
		p->llink=ptr1;
		
	}
	
	else
	{
		ptr->rlink=p;
		p->llink=ptr;
		p->rlink=NULL;
	}
	
	}
	
}
	





void main()
{
       
        create();
        
        int n=1;
        
        printf("\n1-GetNode\n2-ReturnNode\n3-Display\n4-Exit\n");
        
        while(n)
        {
                int ch;
                
                printf("\nEnter your choice:");
                scanf("%d",&ch);
                
                switch(ch)
                {
                        case 1:
                        {
                            int mem;
							printf("\nEnter the size reqiured:");
							scanf("%d",&mem);
							
							node *ptr;
							ptr=GetNode(mem);
							
							if(ptr!=NULL)
							{
								printf("\nThe size retrived is:%d",ptr->size);
							}
							
							break;
							
							
                        }
                        
                        
                        case 2:
                        {
                            int mem;
							printf("\nEnter the size returned:");
							scanf("%d",&mem);
							
							node* new;
							new=(node*)malloc(sizeof(node));
							new->size=mem;
							
							ReturnNode(new);
							break;
							
                        }
                        
                        case 3:
                        {
							printf("\nThe memory(size) available are:");
                            node* ptr=avail;
							
							if(ptr==NULL)
								printf("Empty");
							
							else
							{
								while(ptr!=NULL)
								{
									printf("%d\t",ptr->size);
									ptr=ptr->rlink;
								}
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
