#include <stdio.h>
void mul(int a[][5],int b[][5],int m,int n,int p,int q,int c[][5])
{
	int i,j,k;
	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		{
			c[i][j]=0;
			for(k=0;k<p;k++)
				c[i][j]+=((a[i][k])*(b[k][j]));
		}
}
int main()
{
	int a[5][5],b[5][5],c[5][5],m,n,p,q,i,j;
	printf("Enter the dimensions of first matrix : ");
	scanf("%d %d",&m,&n);
	printf("Enter the dimensions of second matrix : ");
	scanf("%d %d",&p,&q);
	if(n!=p)
	{
		printf("Matrix multiplication not possible\n");
		return 0;
	}
	printf("Enter the first matrix :-\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter the second matrix :-\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	mul(a,b,m,n,p,q,c);
	printf("The product matrix is :-\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
