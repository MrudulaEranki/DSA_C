#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//bubble sort

/*int main()
{
    int n,i,j;
    int* ptr;
    int temp;

    printf("enter number of elements\n");
    scanf("%d",&n);

    ptr = (int*)malloc(n * sizeof(int));
   for(i=0;i<n;i++)
   {
    scanf("%d",&ptr[i]);
   }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(ptr[j]>ptr[j+1])
            {
                temp = ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
   {
    printf("%d\t",ptr[i]);
   }
   return 0;


}
*/

/*int main()
{
    int n,i,j;
    int* ptr;
    int temp;
    int min;


    printf("enter number of elements\n");
    scanf("%d",&n);

    ptr = (int*)malloc(n * sizeof(int));
   for(i=0;i<n;i++)
   {
    scanf("%d",&ptr[i]);
   }
   //selection sort
   for(i=0;i<n-1;i++)
   {

    min = i;
    for(j=i+1;j<n;j++)
    {
        if(ptr[j]<ptr[min])  //basically ptr[j]>ptr[i]
        {
           min = j; 
        }
       
    }
    if(min != i)
     swap(&ptr[min],&ptr[i]);
     
   }

   for(i=0;i<n;i++)
   {
    printf("%d\t",ptr[i]);
   }
   return 0;
}
*/

            //INSERTION SORT


int main()
{
    int n,i,j;
    int* ptr;
    int temp;

    printf("enter number of elements\n");
    scanf("%d",&n);

    ptr = (int*)malloc(n * sizeof(int));
    printf("enter number of elements\n");

   for(i=0;i<n;i++)
   {
    scanf("%d",&ptr[i]);
   }

   for(i=1 ; i<n ; i++)
   {
    temp = ptr[i];
    j = i-1;
    while(j>=0 && temp <= ptr[j])
    {
        ptr[j+1] = ptr[j];
        j= j-1;
    }
    ptr[j+1]=temp;

   }

   for(i=0;i<n;i++)
   {
    printf("%d\t",ptr[i]);
   }
   return 0;

}