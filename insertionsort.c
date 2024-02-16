#include <stdio.h>

void insertionsort(int a[100],int n)
{
    int i,  j,   temp;
   for(i = 1; i < n ;i++)
   {
    temp =a[i];
    j = i-1;
    while(j >= 0 && temp <= a[j])
    {
        a[j+1] = a[j];
        j = j-1;
    }
    a[j+1] = temp;
   }
}

int main()
{
    
    int n, a[100],i;

    printf("enter number\n");
    scanf("%d",&n);
    printf("enter into array\n");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("the array is\n");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    insertionsort(a,n);
    printf("the array after sortin\n");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }

}
