#include <stdio.h>
int lin(int a[],int n,int k)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==k)
			return i;
	return -1;
}
int main()
{
	int a[20],n,i,key;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the key element to be searched : ");
	scanf("%d",&key);
	i=lin(a,n,key);
	if(i==-1)
		printf("The key element is not found\n");
	else
		printf("The key is found at position %d\n",i+1);
	return 0;
}
