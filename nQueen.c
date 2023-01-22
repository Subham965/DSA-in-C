#include<stdio.h>

void print_Solution(int n,int x[])
{
    char c[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            c[i][j]='*';
    }
    for(int i=1;i<=n;i++)
        c[i][x[i]]='Q';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%c",c[i][j]);
        printf("\n");
    }
}
int place(int x[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(x[i]==x[n] || i-x[i]==n-x[n] || i+x[i]==n+x[n])
            return 0;
    }
    return 1;
}
void nQueen(int n)
{
    int x[n+1];
    int k=1;
    int cnt =0;
    x[k]=0;
    while(k!=0)
    {
        x[k]+=1;
        while(x[k]<=n && !place(x,k))
                x[k]+=1;
        if(x[k]<=n)
        {
            if(k==n)
            {
                cnt++;
                printf("cnt =%d\n",cnt);
                print_Solution(n,x);
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
        {
            k--;
        }
        for(int i=1;i<=n;i++)
            printf("%d",x[i]);
    }
}
int main()
{
    int n;
    printf("Enter the no. of queens :");
    scanf("%d",&n);
    nQueen(n);

    return 0;
}
