#include <stdio.h>
int bin(int a[],int n,int k)
{
	int m,l=0,h=n-1;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==k)
			return m;
		else if(a[m]>k)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}
int main()
{
	int a[20],n,i,k;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the aray key element to be searched : ");
	scanf("%d",&k);
	i=bin(a,n,k);
	if(i==-1)
		printf("The key element is not found\n");
	else
		printf("The key element is found at position %d\n",i+1);
	return 0;
}
