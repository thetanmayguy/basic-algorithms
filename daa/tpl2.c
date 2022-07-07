//Vertex removal method
#include <stdio.h>
int iscyc(int a[][10],int n,int s,int c)
{
	int i;
	if(a[c][s]==1)
		return 1;
	for(i=c+1;i<n;i++)
		if(a[c][i]==1)
			return (iscyc(a,n,s,i));
	return 0;
}
int iscyclic(int a[][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==1)
				if(iscyc(a,n,i,j))
					return 1;
	return 0;
}
void top_sort(int a[][10],int n)
{
	int vis[10]={0},indeg[10]={0},i,j,ctr=0;
	if(iscyclic(a,n))
	{
		printf("topological sort not possible for cyclic graph\n");
		return;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[j][i]==1)
				indeg[i]++;
	printf("topological ordering : <");
	while(ctr<n)
		for(i=0;i<n;i++)
			if((indeg[i]==0)&&(vis[i]==0))
			{
				printf("%d",i);
				if((ctr++)<(n-1))
					printf(",");
				vis[i]=1;
				for(j=0;j<n;j++)
					if(a[i][j]==1)
						indeg[j]--;
			}
	printf(">\n");				
}
int main()
{
	int a[10][10],i,j,n;
	printf("vertices : ");
	scanf("%d",&n);
	printf("adjacency matrix :-\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	top_sort(a,n);
	return 0;
}
