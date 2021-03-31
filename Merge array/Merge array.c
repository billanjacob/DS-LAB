
#include <stdio.h>
int main()
{
   int array1[50],array2[50],res[100],m,n,i,j,k;
   printf(" enter the number  of element in the array1");
   scanf("%d",&m);
  printf(" enter  array1 in sorted order");
   
  for(i=0;i<m;i++)
   {
        
       scanf("%d",&array1[i]);
      
   }
    printf(" enter the number of elements in array2");
   scanf("%d",&n);
   printf(" enter  array2 in sorted order");
   for(j=0;j<n;j++)
   {
       scanf("%d",&array2[j]);
      
   }
   i=j=k=0;
    while(i<m&&j<n)
    
    {
        if(array1[i]<array2[j])
        {
        res[k]=array1[i];
        i++;
        k++;
        }
    else

    {
        res[k]=array2[j];
        j++;
        k++;
    }
    
}
while(i<m)
{
    res[k]=array1[i];
    i++;
    k++;
    
}
while(j<n)
{
    res[k]=array2[j];
    j++;
    k++;
    
}

for(i=0;i<m+n;i++)

{
    printf("%d",res[i]);
}
    return 0;
}

