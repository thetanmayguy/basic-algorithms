#include <stdio.h>
void dijkstras(int n,int cm[][10],int s,int d[],int path[][10])
{
    int i,min,vis[10],unvis,j,k;
    for(i=0;i<n;i++)//initial setup
    {
        vis[i]=0;
        d[i]=cm[s][i];
        for(j=0;j<n;j++)
            path[i][j]=999;
        path[i][9]=1;
    }
    vis[s]=1;
    for(i=0;i<n;i++)
    {
        min=999;
        for(j=0;j<n;j++)
            if(vis[j]==0)
                if(d[j]<min)
                {
                    min=d[i];
                    unvis=i;
                }
        vis[unvis]=1;
        for(j=0;j<n;j++)
            if((cm[unvis][j]!=999)&&(vis[j]==0))
                if(d[j]>(d[unvis]+cm[unvis][j]))
                {
                    d[j]=d[unvis]+cm[unvis][j];
                    path[j][9]--;
                    path[j][path[j][9]++]=unvis;
                }
    }
}
int main()
{
    int cm[10][10],n,dis[10],i,j,k,s,path[10][10];
    printf("n : ");
    scanf("%d",&n);
    printf("enter the cost adjacency matrix :-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cm[i][j]);
    printf("enter source vertex : ");
    scanf("%d",&s);
    s=s-1;
    dijkstras(n,cm,s,dis,path);
    printf("The shortest paths from source to:-\n");
    for(i=0;i<n;i++)
    {
        printf("%d: %d = [%d",i+1,dis[i],s+1);
        for(j=0;path[i][j]!=999;j++)
        {
            for(k=0;path[path[i][j]][k]!=999;k++)
                printf("->%d",path[path[i][j]][k]+1);
            printf("->%d",path[i][j]+1);
        }
        if(i!=s)
            printf("->%d",i+1);
        printf("]\n");
    }
    printf("\n");
    return 0;
}