#include<stdio.h>
#define PI 3.14
#include<math.h>
#define volume(r) (4/3.0)*PI*pow(r,3)

void main(){
    float v1,v2,v3;

    v1 = volume(5);
    v2 = volume(10);
    v3 = volume(15);

    printf("%f\n%f\n%f\n",v1,v2,v3);
}