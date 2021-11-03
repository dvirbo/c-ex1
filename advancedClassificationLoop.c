#include <stdio.h>
#include <math.h>
#include "NumClass.h"

/**isPalindrome & isArmstrong --> by loop
 * 1=true, 0=false
 **/
int isPalindrome(int orginal)
{
  int reversed = 0;
  int rem = 0;
  int n = orginal;

  while (n != 0)
  {
    rem = n % 10;
    reversed = reversed * 10 + rem;
    n /= 10;
  }
  if (reversed == orginal)
    return 1;
  else
    return 0;
}

int isArmstrong(int a)
{

  int reminder;
  double ans;
  int length = 0;
  int temp = a;

  while (temp > 0)
  { // geting the amount of digit in the number
    temp /= 10;
    length++;
  }
  temp = a;
  while (temp > 0)
  {
    reminder = temp % 10;
    ans = ans + pow(reminder, length);
    temp /= 10;
  }
  if ((int)ans == a)
    return 1; // True
  else
    return 0;
}
