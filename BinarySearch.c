#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[],int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array \n");
    scanf("%d",&n);
    int * arr = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        printf("Enter the %d th element :\n", i+1);
        scanf("%d",&arr[i]);
    }

    int high = n-1;
    int low = 0;
    int a;
    printf("Enter the element to search \n");
    scanf("%d", &a);
    int x= binarySearch(arr, low, high, a);
    if(x!=-1){
        printf("The element %d is found\n", a);
    }
    else{
        printf("The element is not found\n");
    }

    return 0;
}
