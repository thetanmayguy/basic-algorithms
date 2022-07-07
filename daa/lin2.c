#include <stdio.h>
int main()
{
	int a[20],n,i,k,ctr=0;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the key element to be searched : ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			ctr++;
			if(ctr==1)
				printf("The key element is found at position(s) %d",i+1);
			else
				printf(",%d",i+1);
		}
	}
	if(ctr==0)
		printf("The key element is not found\n");
	else
		printf(" (%d)times\n",ctr);
	return 0;
}			
