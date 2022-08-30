//
// Created by xiaohu feng on 2022/8/29.
//
#include "iostream"
#include "cmath"
#include "algorithm"
using namespace std;
int findNthDigit(int n) {
  if(n<0) return -1;
  if(n>0 && n<9) return n;
  n-=10;
  int digit = 1;
  int offset = 0;
  int remind = 0;
  int res = 0;
  while(n>0)
  {
    //long long tmp = ( (digit+1) * 9 * (int)pow(10,digit));
    long long tmp = (digit+1)*(int)pow(10,digit);
    if(n>(9 * tmp))
    {
      n-=(9 * tmp);
    }
    else break;
    digit++;
  }
  offset = n / (digit+1);
  remind = n - offset * (digit+1);
  int number = (int)pow(10,digit) + offset;
  remind = digit + 1 - remind;
  while(number)
  {
    if(!(remind--)) return res;
    res = number%10;
    number /=10;

  }
}

int main()
{
  int res = findNthDigit(1000000000);
  return 0;
}
