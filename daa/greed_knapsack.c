#include <stdio.h>
void knapsack(int n,float c,float p[],float w[],float x[])
{
	int i,j,ctr;
	float r[10][2],max;
	for(i=0;i<n;i++)
	{
		r[i][0]=p[i]/w[i];
		r[i][1]=0;
		x[i]=0;
	}
	for(ctr=n;ctr>0;ctr--)
	{
		max=r[0][0];
		for(j=0;j<n;j++)
			if((r[j][0]>=max)&&(r[j][1]==0))
			{
				max=r[j][0];
				i=j;
			}
		r[i][1]=1;
		if(w[i]<=c)
		{
			x[i]=1;
			c-=w[i];
		}
		else
		{
			x[i]=c/w[i];
			c=0;
			return;
		}
	}
}
int main()
{
	int n,i;
	float p[10],w[10],x[10],max=0,c;
	printf("no. of object : ");
	scanf("%d",&n);
	printf("capacity of knapsack : ");
	scanf("%f",&c);
	printf("enter %d weights and profits associated with each object:-\n",n);
	for(i=0;i<n;i++)
		scanf("%f %f",&w[i],&p[i]);
	knapsack(n,c,p,w,x);
	printf("ratio of objects taken inside the knapsack are:-\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f ",x[i]);
		max+=p[i]*x[i];
	}
	printf("\nmaximum profit = %.2f\n",max);
	return 0;
}