#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parents[9];
int main()
{

    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d",&n);
    printf("ENTER THE ADJACECNCY MATRIX:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }


        }
    }
    while(ne<n)
    {

        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(parents[u]!=0)
        {
            u=parents[u];
        }
        while(parents[v]!=0)
        {

            v=parents[v];
        }
        if(u!=v)
        {
            ne++;
            printf("\n %d %d %d\n",a,b,min);
            mincost+=min;
            parents[v]=u;
        }
        cost[a][b]=cost[b][a]=999;
    }
   printf("minimum cost be: %d",mincost);
   return 0;
}
