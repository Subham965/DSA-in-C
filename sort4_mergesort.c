#include <stdio.h>

int n;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[n]; //n is the max size of temporary array B[]
    i = low; // initializing pointer of first sorted subarray
    j = mid + 1; // initializing pointer of second sorted subarray
    k = low; // initializing pointer of temporary array

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    // copying all elements from temporary array to original array 
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);  // dividing into subarray
        mergeSort(A, mid+1, high); // dividing into  subarray
        merge(A, mid, low, high); // merging the subarrays
    }
}

int main()
{
    int n, i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter all the elements of array\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
