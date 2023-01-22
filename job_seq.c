#include<stdio.h>
int d[100],p[100],n,i,j,t,m,k;
void job(int [],int [],int);
int main()
{
	printf("Enter no. of jobs: ");
	scanf("%d",&n);
	printf("Enter the deadline: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("Enter the profit: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	job(d,p,n);
	return 0;
}
void job(int d[],int p[],int n)
{
	//t=0;
	printf("\nPrint Solution,Sequence & Profit\n");
	for(i=1;i<=n;i++)
	{
		printf("Profit %d of jobiD %d\n",p[i],i);
		if(t<p[i])
		{
			t=0;
		}
		t=p[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(d[i]!=1 || d[j]!=1)
			{
				m=p[i]+p[j];
				printf("m for dedaline combination(%d,%d)= %d\n",d[i],d[j],m);
				if(m>t)
				{
					t=m;
				}
			}
		}
	}
	printf("MAX profit= %d",t);
	return ;
}

// 4
// 2 1 2 1
// 100 10 15 27