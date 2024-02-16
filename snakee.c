// C program to build the outline

// boundary using Boundary()

#include <stdio.h>

#include <stdlib.h>

 

//Game Variables

int i, j, Length = 28;

int width = 28, game_over, Score;

 

// Function to draw a boundary

void Boundary()

{

 

for (i = 0; i < Length; i++) {

     for (j = 0; j < width; j++) {

         if (i==0 || i==width - 1 || j == 0

             || j == Length - 1) {

                printf("*");

         }

         else {

                printf(" ");

         }

     }

        printf("\n");

}

}

 

//  Driver Function

int main()

{

Boundary(); // Function Call

 

return 0;

} 

//  Driver Function

