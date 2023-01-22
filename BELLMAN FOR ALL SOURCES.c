#include<stdio.h>

void bellman(int n,int v,int cost[10][10],int dist[])
{
    int flag[n+1];
    for(int i=1;i<=n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];
    }
    int count=2;
    while(count<=n)
    {
        int min=99,u=-1;
        for(int w=1;w<=n;w++) //D
        {
            if(dist[w]<min && !flag[w])
            {
                min=dist[w];
                u=w;
            }
        }
        flag[u]=1;
        count++;
        for(int w=1;w<=n;w++)
        {
            if(dist[u]+cost[u][w]<dist[w] && !flag[w])
                dist[w]=dist[u]+cost[u][w];
        }
    }
}

int main()
{
    int n,INF=99;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    int cost[10][10];
    int dist[10];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }
    printf("All pairs are:\n");
    for(int v=1;v<=n;v++)
    {
        bellman(n,v,cost,dist);
        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);
        printf("\n");
    }
    /*
    bellman(n,1,cost,dist);
        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);*/

    return 0;
}
