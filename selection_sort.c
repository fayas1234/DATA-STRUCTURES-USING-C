//Program to implement Selection Sort

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
		
		int j,temp,index;
		
		for(i=0;i<n-1;i++)
		{
			index=i;
			for(j=i+1;j<n;j++)
			{
				if(arr[j]<arr[index])
				{
					index=j;
				}
			}
			temp=arr[i];
			arr[i]=arr[index];
			arr[index]=temp;
			
		}
		
		printf("The sorted arrayis:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
	
}
