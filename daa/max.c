#include <stdio.h>
int max(int a[],int n)
{
	int m=a[0],i;
	for(i=0;i<n;i++)
		if(a[i]>m)
			m=a[i];
	return m;
}
int main()
{
	int a[20],i,n;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The largest element in the array is %d\n",max(a,n));
	return 0;
}
