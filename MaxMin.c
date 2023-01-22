#include<stdio.h>
#include<stdio.h>
int a[100];
int max,min;
max_min(i,j){
    int max1,min1;
    if(i==j){
        max=a[i];
        min=a[j];

    }
    else if(i==j-1){
        if(a[i]>a[j]){
            max=a[i];
            min=a[j];
        }
        else{

            max=a[j];
            min=a[i];

        }
    }
    else
    {
    int mid=(i+j)/2;
    max_min(i,mid);
    max1=max;
    min1=min;
    max_min(mid+1,j);
    if(max1>max){
        max=max1;
    }
    if(min>min1)
        min=min1;
    }
}
int main(){

    int n,i;
    printf("Enter the total elements:\n");
    scanf("%d",&n);
    printf("Enter the element \n");

    for( i=1;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    max_min(1,n);
    printf("Maximum Element:%d\n",max);
    printf("Minimum Element:%d\n",min);
    return 0;
}


