#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*int password(int n, char *s){

    int lower_case = 0;
    int upper_case = 0;
    int number = 0;
    int spl_digit = 0;

    for(int i = 0; i<n ; i++)
    {
        if(s[i] >= 'a'&& s[i] <= 'z')
           lower_case++;
        else if(s[i] >= 'A'&& s[i] <= 'Z')
           upper_case++;
        else if(s[i] >= '0'&& s[i] <= '9')
           number++;
        else
           spl_digit++;
    }

    int add = 0;

    if(lower_case == 0)
      add++;
    if(upper_case == 0)
      add++;
    if(number == 0)
      add++;
    if(spl_digit == 0)
      add++;

    int len  = strlen(s);
    
    len = len + add;

    if(len < 6)
      add = add + 6 - len;

    return add;
}*/

/*int main()
{
    int n,i ;
    int f[300]={0};
    int ans = 0;
    char s[10000];
    gets(s);
    int l = strlen(s);

    for(i = 0; i< l ; i++)
    {
        if(s[i] == ' ')
          continue;
        if(s[i]>='a')
         s[i] = s[i] - ('a' - 'A');
        if(!(f[s[i]]++))
          ans++;
    }

    if(ans != 26)
      printf("not ");
      printf("pangram\n");

    return 0;
}*/

#include <stdio.h>

int main(){
    int y; 
    scanf("%d",&y);
    if(y<1918){
        if(y%4){
            printf("13.09.%4d\n",y);
        }
        else{
            printf("12.09.%4d\n",y);
        }
    }
    else if(y== 1918){
        printf("26.09.1918\n");
    }
    else{
        if((y%400 == 0) || (y%4 == 0 && y%100)){
            printf("12.09.%4d\n",y);
        }
        else{
            printf("13.09.%4d\n",y);
        }
    }
    return 0;
}
   