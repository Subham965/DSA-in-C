#include<stdio.h>
#define MAX 100
int n;
int a[MAX][MAX];
int visited[MAX];
int cost=0;

void get()
{
    printf("Enter the no of cities:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
}

int least(int c)
{
    int min=999,nc=999;
    int kmin;
    for(int i=0;i<n;i++)
    {
        if(a[c][i]!=0 && visited[i]==0)
        {
            if(a[c][i]<min)
            {
                min=a[i][0]+a[c][i];
                kmin=a[c][i];
                nc=i;
            }
        }
    }
    if(min!=999)
    {
        cost=cost+kmin;
    }
    return nc;
}

void minCost(int city)
{
    visited[city]=1;
    printf("%d ",city+1);
    int nCity=least(city);
    if(nCity==999)
    {
        nCity=0;
        printf("%d ",nCity+1);
        cost=cost+a[city][nCity];
        return;
    }
    minCost(nCity);
}

void put()
{
    printf("\n");
    printf("The cost is:%d",cost);
}

int main()
{
    get();
    minCost(0);
    put();

    return 0;
}

