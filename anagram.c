#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[10];
    scanf("%s",s);
    
    if(s[8] == 'P')
    {
        if(s[0] != 1 || s[1] != 2)
        {
            s[0] ++;
            s[1] += 2;
        }
    }
    else{
        if(s[0] == 0 && s[1] == 2)
        {
            s[0] = 0;
            s[1] = 0;
        }
    }
    s[8] = '\0';
    printf("%s",s);
    
    return 0;
}