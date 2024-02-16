#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int minimum_number(int n, char *password);

int main()
{

    int n;
    scanf("%i",&n);

    char *password = (char*
    ) malloc(512000 * sizeof(char)); 
    scanf("%s",password);

    int answer = minimum_number(n,password);
    printf("%d",answer);

    return 0;

}

int minimum_number(int n, char *password){

    int len;

    len = strlen(password);

    int lower_case = 0;
    int upper_case = 0;
    int number =  0;
    int special_char = 0;

    int i;

    for(i=0 ; i <n ; i++){
        if(password[i] >= 'a' || password[i] <= 'z')
           lower_case++;
        else if(password[i] >= 'A' || password[i] <= 'Z')
           upper_case++;
        else if(password[i] >= '0' || password[i] <= '9')
            number++;
        else
            special_char++;
    }
    int add = 0;
    if(lower_case == 0)
       add++;
    if(upper_case == 0)
       add++;
    if(number == 0)
       add++;
    if(special_char == 0)
       add++;
    
    len = len + add;

    if(len < 6)
      add = add + 6 - len;
    
    return add;

    


}