#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *thousands[] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion"};

void convertLessThanThousand(int num)
{
   if (num >= 100)
   {
      printf("%s hundred ", ones[num / 100]);
      num %= 100;
   }

   if (num >= 20)
   {
      printf("%s ", tens[num / 10]);
      num %= 10;
   }

   if (num >= 10)
   {
      printf("%s ", teens[num - 10]);
      return;
   }

   if (num > 0)
   {
      printf("%s ", ones[num]);
   }
}

void convertNumberToWords(long long number)
{
   if (number == 0)
   {
      printf("zero");
      return;
   }

   int count = 0;

   while (number > 0)
   {
      if (number % 1000 != 0)
      {
         convertLessThanThousand(number % 1000);
         printf("%s ", thousands[count]);
      }
      number /= 1000;
      count++;
   }
}

int main()
{
   long long number;
   printf("Enter a number: ");
   scanf("%lld", &number);

   printf("In words: ");
   convertNumberToWords(number);

   return 0;
}
