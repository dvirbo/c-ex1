#include <stdio.h>
#include <math.h>
#include "NumClass.h"

/**
 * recurcive isPalindrome1
 **/
int isPalindrome(int orginal)
{
  int reversed = 0, rem = 0, n = orginal;
  while (n != 0)
  {
    rem = n % 10;
    reversed = reversed * 10 + rem;
    isPalindrome(n /= 10);
  }
  if (reversed == orginal)
    return 1;
  else
    return 0;
}

/**
 * recurcive isArmstrong
 **/
int check_ArmstrongNumber(int a, int length)
{
  if (a > 0)
    return pow(a % 10, length) + check_ArmstrongNumber(a / 10, length); // recurcive call
}

int isArmstrong(int a)
{
  int length = 0;
  int temp = a;

  while (temp > 0) // geting the amount of digit in the number:
  {
    temp /= 10;
    length++;
  }

  // if(check_ArmstrongNumber(a,length)==a)
  int tr = check_ArmstrongNumber(a, length);
  if (tr - length == a) // thats it..
    return 1;           // True
  else
    return 0;
}