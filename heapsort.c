#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int arr[],int a, int b)
{
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr,i,largest);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr,0,i);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
 
    printf("Original array is \n");
    printArray(arr, n);

    heapSort(arr, n);
 
    printf("Sorted array is \n");
    printArray(arr, n);
}