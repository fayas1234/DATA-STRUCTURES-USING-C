//Program to implement Insertion Sort

#include <stdio.h>


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
		
		int j;
		
		for(i=1;i<n;i++)
		{
			j=i-1;
			int temp=arr[i];
			
			while(j>=0 && arr[j]>temp)
			{
				arr[j+1]=arr[j];
				j--;
			}
			
			arr[j+1]=temp;
		}
		
		printf("The sorted arrayis:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
}
