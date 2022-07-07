#include <stdio.h>
int bin(int a[],int key,int l,int h)
{
	int m=(l+h)/2;
	if(l>h)
		return 0;
	if(a[m]==key);
		return 1;
	if(a[m]>key)
		return bin(a,key,l,m-1);
	else
		return bin(a,key,m+1,h);
}
int main()
{
	int a[20],n,i,k;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the key element to be searched : ");
	scanf("%d",&k);
	i=bin(a,k,0,n-1);
	if(i==0)
		printf("The key is not found\n");
	else
		printf("The key is found\n");
	return 0;
}
