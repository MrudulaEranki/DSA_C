#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int frequency[26];

int main()
{
    char s[10000];

    scanf("%s",s);

    int len  = strlen(s);

    int i;

    for (i = 0; i< len ; i++){
        frequency[s[i] - 'a']++;
    }

    int flag = 0;
    int count  = 0; 
    int same  = 0;

    for (i = 0; i< 26 ; i++)
    {
        if(flag == 0 && frequency[i] != 0)
        {
            flag =1 ;
            same = frequency[i];
        }
        if(flag == 1 && frequency[i] != 0 && frequency[i] != same)
        {
            count++ ;

        }
    }
    if(count <= 1)
       printf("valid");
    else 
       printf("not  valid");

    return 0;
}