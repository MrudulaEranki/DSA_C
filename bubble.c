#include<stdio.h>

void bubblesort(int a[100], int n)
{
    int i, j ,swap;
    for(i=0; i<n ; i++){
        for(j = 0 ; j<n ;j++){
            if(a[j] > a[j+1]){
                swap = a[j];
                a[j]= a[j+1];
                a[j+1] = swap;
            }
        }
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
    bubblesort(a,n);
    printf("the array after sortin\n");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }

}
