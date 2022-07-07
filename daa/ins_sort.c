#include <stdio.h>
void ins(int a[],int n)
{
	int i,j,key;
	for(i=0;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while((a[j]>key)&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{
	int a[20],n,i;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ins(a,n);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
