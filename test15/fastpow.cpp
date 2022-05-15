#include<iostream>
#include<math.h>
using namespace std;
double myPow(double x, int n) {
    double temp= 0;
    if(x == 0) return 0;
    if(n==1) return x;
    if(n==0 && x!=0) return 1;
    if(n<0) {
        x = 1.0/x;
        n = -n;
    }
    
   
    
    while(n!=1)
    {
        if(n&1) temp = x;
        x = x*x;
        n >>=1;
    }
    return temp*x;
    
    }
int main(void)
{
    long long result = myPow(2.0000,-2);
}
