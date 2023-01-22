#include<stdio.h>
 
void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n){
    int temp;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
 
void bubbleSortAdaptive(int A[], int n){
    int temp;
    int isSorted;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
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
    printArray(arr, n); // Printing the array before sorting
    bubbleSortAdaptive(arr, n); // Function to sort the array
    printArray(arr, n); // Printing the array after sorting
    return 0;
}
