#include <stdio.h>
void prims(int cm[][10],int n,int s)
{
    int vis[10],unvis[10],i,j,k,u,v,min,cost=0;
    for(i=0;i<n;i++)//initial setup
    {
        if(i!=(s-1))
        {
            vis[i]=0;
            unvis[i]=1;
        }
        else
        {
            vis[i]=1;
            unvis[i]=0;
        }
    }
    //calculating MCST
    for(i=1;i<n;i++)
    {
        min=999;
        for(j=0;j<n;j++)
            if(vis[j]==1)//v must be in spanning tree
                for(k=0;k<n;k++)
                    if((unvis[k]==1)&&(cm[j][k]!=999))//u must not be in spanning tree and is a fringe vertex of v
                        if(min>cm[j][k])
                        {
                            min=cm[j][k];
                            v=j;
                            u=k;
                        }
        vis[u]=1;
        unvis[u]=0;
        cost+=min;
        printf("edge added: %d to %d\n",v+1,u+1);
    }
    printf("total cost of MCST is %d\n",cost);
}
int main()
{
    int cm[10][10],n,i,j,s;
    printf("verices : ");
    scanf("%d",&n);
    printf("adjacency matrix :-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cm[i][j]);
    printf("source : ");
    scanf("%d",&s);
    prims(cm,n,s);
    return 0;
}