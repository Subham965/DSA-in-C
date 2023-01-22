#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp(char substr[], char str[])
{
   int i, j, N, M;

   N = strlen(str);
   M = strlen(substr);

   int *d = (int*)malloc(M * sizeof(int));
   d[0] = 0;

   for(i = 0, j = 0; i < M; i++)
   {
      while(j > 0 && substr[j] != substr[i])
      {
         j = d[j - 1];
      }

      if(substr[j] == substr[i])
      {
         j++;
         d[i] = j;
      }
   }

   for(i = 0, j = 0; i < N; i++)
   {
      while(j > 0 && substr[j] != str[i])
      {
         j = d[j - 1];
      }

      if(substr[j] == str[i])
      {
         j++;
      }

      if(j == M)
      {
         free(d);
         return i - j + 1;
      }
   }

   free(d);

   return -1;
}

int main(void)
{
   char substr[] = "World",
      str[] = "Hello World!";

   int pos = kmp(substr, str);

   printf("position starts at: %i\r\n", pos);

   return 0;
}