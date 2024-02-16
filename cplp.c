#include <stdio.h>
int main(){
    float cost,sell,profit,loss,prof_perc,loss_perc;

    printf("enter the cost price and selling price\n");
    scanf("%f \t\t  %f",&cost,&sell);

    if(cost> sell){
        loss= cost-sell;
        printf("'tis a loss of %f\n",loss);
        loss_perc= (loss/cost)*100;
        printf("and loss percentage is %f",loss_perc);
    }

    else  if(sell > cost){
        profit= sell-cost;
        printf("'tis a profit of %f\n",sell-cost);
        prof_perc=(profit/cost)*100;
        printf("and profit percentage is %f",prof_perc);
    }
    else{
        printf("no loss no profit");
    }
    return 0;
}