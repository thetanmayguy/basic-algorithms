#include <stdio.h>
int partition(int a[],int low,int high)
{
	int pivot=a[low],i=low,j=high,temp;
	while(i<j)
	{
		while((a[i]<=pivot)&&(i<high))
			i++;
		while((a[j]>=pivot)&&(j>low)&&(j>=i))
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
}
void quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}
int main()
{
	int a[20],n,i;
	printf("array size : ");
	scanf("%d",&n);
	printf("array elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	printf("sorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
