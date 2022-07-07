#include <stdio.h>
int sum(int a[],int n)
{
	int s=0,i;
	for(i=0;i<n;i++)
		s+=a[i];
	return s;
}
int main()
{
	int a[20],n,i;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The sum of all the elements in the array = %d\n",sum(a,n));
	return 0;
}
