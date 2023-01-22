#include<stdio.h>
#include<string.h>
int match(char text[],char pat[])
{
 char temp[100];
 int n=strlen(text);
 int m=strlen(pat);
 int i,j,s,k,count=0;
 for(s=0;s<=n;s++)
 {
  for(j=s,k=0;j<m;j++,k++)
   temp[k]=text[s+k];
  temp[k]='\0';
  if(strcmp(pat,temp)==0)
  {
  return s;
  count++;
  }
  m++;
 }
  return count;
}
int main()
{
    int position;
    char a[20], b[20];
    printf("Enter the text: ");
    gets(a);
    printf("Enter the pattern: ");
    gets(b);
    position = match(a, b);
    if(position != 1)
        printf("string is found at location: %d", position + 1);
    else
        printf("\n not found");
    return 0;
}
