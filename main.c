#include <stdio.h>
#include "NumClass.h"

// Author: Dvirb

/////////////***////////////////
void print_prime(int min, int max)
{
  printf("\n");
  printf("The Prime numbers are:");
  int print_ans;
  
  while (min <= max)
  {
    print_ans = isPrime(min);
    if (print_ans == 1) // mean that the ans is True
      printf(" %d", min);
    min++;
  }
}

/////////////***////////////////
void print_amstrong(int min, int max)
{
   printf("The Armstrong numbers are:");
  int print_ans;
  while (min <= max)
  {
    print_ans = isArmstrong(min);
    if (print_ans == 1) // mean that the ans is True
      printf(" %d", min);
    min++;
  }
}

/////////////***////////////////
void print_strong(int min, int max)
{
  printf("\n");
  printf("The Strong numbers are:");
  int print_ans;
  while (min <= max)
  {
    print_ans = isStrong(min);
    if (print_ans == 1) // mean that the ans is True
      printf(" %d", min);
    min++;
  }
}

/////////////***////////////////
void print_Palindrome(int min, int max)
{
  printf("\n");
  printf("The Palindromes are:");
  int print_ans;
  while (min <= max)
  {
    print_ans = isPalindrome(min);
    if (print_ans == 1) // mean that the ans is True
      printf(" %d", min);
    min++;
  }
}

void print_func(int min, int max)
{

  print_amstrong(min, max);
  print_Palindrome(min, max);
  print_prime(min, max);
  print_strong(min, max);
}

//main function :

int main()
{
  int x, y;
  scanf("%d%d", &x, &y);

  if (x > y)
    print_func(y, x);
  else
    print_func(x, y);
  return 0;
}