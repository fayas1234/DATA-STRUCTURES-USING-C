//Program to implement Bubble Sort

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
		
		int j,temp;
		
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
			
		}
		printf("The sorted arrayis:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
}