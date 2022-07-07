#include <stdio.h>
void merge(int a[],int l,int m,int h)
{
	int i,j,k,b[20];
	for(i=l,j=m+1,k=0;(i<=m)&&(j<=h);)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	for(;i<=m;i++)
		b[k++]=a[i];
	for(;j<=h;j++)
		b[k++]=a[j];
	for(i=l,k=0;i<=h;i++,k++)
		a[i]=b[k];
}
void mergesort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}
int main()
{
	int a[20],n,i;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	printf("Enter the array elements :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("The sorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
