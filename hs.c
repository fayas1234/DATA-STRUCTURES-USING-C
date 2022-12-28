//Program to implement Heap Sort

#include <stdio.h>

void heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l]>arr[largest])
		largest=l;
	
	if(r<n && arr[r]>arr[largest])
		largest=r;

	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];      /* Swapping */
		arr[largest]=temp;
		
		heapify(arr,n,largest);
	}
	return;
}

void heap_sort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);  /* Creating the initial max heap*/

	for(int i=n-1;i>0;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];      /* Swapping root and last node*/
		arr[i]=temp;
		
		heapify(arr,i,0);

	}
	return;
}





void main()
{
		int n;
		
		printf("Enter the number of elements in the array:");
		scanf("%d",&n);
		
		int arr[n];
		int i;
		
		printf("Enter the elements of the array:");
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		
		heap_sort(arr,n);
		
		printf("The sorted arrayis:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		
}