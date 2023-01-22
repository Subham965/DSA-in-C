#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of vertex:");
    scanf("%d",&n);
    int cost[n+1][n+1];
    printf("Enter the graph:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }
    int vis[n+1];
    for(int i=1;i<=n;i++)
        vis[i]=0;
    vis[1]=1;
    int ne=1,minCost=0;
    while(ne<n)
    {
        int mn=999;
        int u,v,a,b;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]<mn)
                {
                    if(vis[i]!=0)
                    {
                        mn=cost[i][j];
                        a=i;
                        u=i;
                        b=j;
                        v=j;
                    }
                }
            }
        }
        if(vis[u]==0 || vis[v]==0)
        {
            printf("%d %d %d\n",a,b,mn);
            ne++;
            minCost+=mn;
            vis[b]=1;
        }
        cost[a][b]=999;
        cost[b][a]=999;
    }
    printf("MinCost is:%d",minCost);

    return 0;
}

