/*
isStrong, isPrime
*/
#include <stdio.h>
#include <math.h>

/*if true--> return 1, else -1
 */
int isPrime(int p)
{
   
   if (p == 2 || p == 1)
      return 1;
   if (p % 2 == 0 && p != 2)
   {
      return 0;
   }
   int i = 3;
   while (i * i <= p)
   {
      if (p % i == 0)
      {
         return 0;
      }
      i++;
   }
   return 1;
}

/*
This funct check if pactorial of each digit in a given num
is equal to the num himself
*/
int factorial(int num)
{
   int ans = 1;
   for (int i = 1; i <= num; i++)
   {
      ans = ans * i;
   }
   return ans;
}

int isStrong(int a)
{

   int reminder;
   int ans = 0;
   int temp = a;
   while (temp != 0)
   {
      reminder = temp % 10;
      int f = factorial(reminder);
      temp /= 10;
      ans += f;
   }

   if (ans == a)
      return 1; // T
   else
      return 0; // F
}