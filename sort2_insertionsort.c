#include<stdio.h>

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
   
    
    int n, i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter all the elements of array\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
