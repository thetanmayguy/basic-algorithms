#include <stdio.h>
void top_sort(int a[][10],int n)
{
	int vis[10]={0},ctr,indeg[10]={0},i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[j][i]==1)
				indeg[i]++;
	printf("topological ordering : <");
	for(ctr=0;ctr<n;ctr++)
		for(i=0;i<n;i++)
			if((indeg[i]==0)&&(vis[i]==0))
			{
				printf("%d",i);
				if(ctr<(n-1))
					printf(",");
				vis[i]=1;
				for(k=0;k<n;k++)
					if(a[i][k]==1)
						indeg[k]--;
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
