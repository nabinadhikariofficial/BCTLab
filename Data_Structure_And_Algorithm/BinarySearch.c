#include <stdio.h>

int main()
{
   int i, j, first, last, middle, n, search, array[100],temp;

   printf("Enter number of elements\n");
   scanf("%d",&n);

   printf("Enter %d integers\n", n);

   for (i = 0; i < n; i++)
      scanf("%d",&array[i]);

   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(array[i]>array[j])
           {
               temp=array[i];
               array[i]=array[j];
               array[j]=temp;
           }
       }
   }
   printf("Sorted data.\n");
   for(i=0;i<n;i++)
        printf("%d\t",array[i]);

    printf("\n");
   printf("Enter value to find\n");
   scanf("%d", &search);

   first = 0;
   last = n - 1;
   middle = (first+last)/2;

   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);

   return 0;
}


