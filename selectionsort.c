#include<stdio.h>
void selectionsort(int array[100],int n);

int main(){
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
    selectionsort(a,n);
    printf("the array after sortin\n");
    for(i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
}

void selectionsort(int a[100],int n){
    int i,j,pos, min;

    for(i=0 ;i<n-1;i++)
    {
        pos = i;
        min = a[i];
        for(j=i+1 ; j<n ; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                pos = j;
            }

        }
        a[pos] = a[i];
        a[i] = min;
    }
}