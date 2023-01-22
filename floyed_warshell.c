#include<stdio.h>
#define MAX 100
int a[MAX][MAX];
int path[MAX][MAX];

int display(int mat[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int minimum(int a,int b)
{
    if(a<=b)
        return a;
    return b;
}

int main()
{
    int n;
    printf("Enter the no of vertices:");
    scanf("%d",&n);
    int INF=-1;
    int INF2=1e6;
    printf("Enter the matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    display(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                path[i][j]=0;
            else if(a[i][j]==INF)
                path[i][j]=INF2;
            else
                path[i][j]=a[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                path[i][j]=minimum(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    display(path,n);
    return 0;
}
