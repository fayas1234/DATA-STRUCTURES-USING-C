//Prgram to implement merge sort
#include <stdio.h>

int arr[50],temp[50];


void merge(int low ,int mid,int high) /*For merging*/
{
	int i,j,k;
	
	i=low;
	j=mid+1;
	k=low;
	
	while((i<=mid)&&(j<=high))
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			k++;
			i++;
		}
		
		else
		{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	
	while(i<=mid) /*copying remaining elemnts in left side*/
	{
		temp[k]=arr[i];
		k++;
		i++;
	}
	
	while(j<=high) /*copying remaining elemnts in right side*/
	{
		temp[k]=arr[j];
		k++;
		j++;
	}
	
	for(i=low;i<=high;i++)/*/copying elemnets of temp into arr*/
		arr[i]=temp[i];
		
}


void merge_sort(int low,int high) /*For sorting*/
{
	int mid;
	
	if(low!=high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}


/*   main   */
void main()
{
	int n;
		
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	
	int i;
		
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(0,n-1); /* Sorting */
	
	printf("The sorted arrayis:");
	for(i=0;i<n;i++)  /* Displaying the sorted array*/
	{
		printf("%d\t",arr[i]);
	}

}