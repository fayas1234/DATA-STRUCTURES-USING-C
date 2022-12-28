//Program to implement Quick Sort

#include <stdio.h>

void quicksort(int arr[],int s,int e)
{
	int l,r,temp,p;
	
	if(s<e){
	p=arr[s];
	l=s;
	r=e;
	
	while(l<r)
	{
		while(arr[l]<=p)
		{
		
			l++;
		}
		while(arr[r]>p)
		{
		 
			r--;
		}
		
		if(l<r)
		{
			temp=arr[l];
			arr[l]=arr[r];
			arr[r]=temp;
		}
	
	}
	arr[s]=arr[r];
	arr[r]=p;
	
	quicksort(arr,s,r-1);
	quicksort(arr,r+1,e);
	}
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
		
		
		quicksort(arr,0,n-1);
		
		printf("The sorted array is:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		
}