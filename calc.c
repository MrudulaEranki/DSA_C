#include<stdio.h>
//#include<conio.h>

int string_ln(char* p[20]);

void main(){
    char str[20];
    int length;
    

    scanf("%s",str);
    length = string_ln(str);

    printf("length of given string is : \n %d",length);
    //getch();
}

int string_ln(char  p[20])//p=&str[0]
{
    int count= 0;
    int i=0;
    while (p[i] != '\0'){
        count ++;
        p++;
    }

    return count;
}