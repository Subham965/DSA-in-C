#include <stdio.h>
int main()
{
int n, i, search;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter all the elements of array\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
  printf("Enter a number to search\n");
  scanf("%d", &search);


  for (i = 0; i < n; i++)
  {
    if (arr[i] == search)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", search, i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", search);

  return 0;
}