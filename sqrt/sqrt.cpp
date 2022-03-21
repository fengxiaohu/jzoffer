#include<iostream>
#include<math.h>
using namespace std;
/*
binary search
int mySqrt(int x)
{
    int left = 0;
    int right = x;
    int res = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(mid*mid > x)
        {
            
            right = mid-1;
            res = right;
        }
        else if(mid*mid < x)
        {
            res = left;
            left = mid+1;
            
        }
        else 
        {
            res = mid;
            break;
        }#include<iostream>
#include<math.h>
using namespace std;
/*
binary search
int mySqrt(int x)
{
    int left = 0;
    int right = x;
    int res = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(mid*mid > x)
        {
            
            right = mid-1;
            res = right;
        }
        else if(mid*mid < x)
        {
            res = left;
            left = mid+1;
            
        }
        else 
        {
            res = mid;
            break;
        }
        
    }
    return res;
} 
*/ 
// x0 = (c/x0+x0)/2
// newton method to find sqrt
int mySqrt(int x)
{
   double x0 =x;
   int c = x;
   int res;
   while(fabs(x0*x0-x)>0.1)
   {
       
       x0 = (c/x0+x0)*0.5;
       
   }
   res = floor(x0);
    
    
}



int main(void)
{
    int value = 3;
    int res = mySqrt(value);
    
} 




        
    }
    return res;
} 
*/ 
// x0 = (c/x0+x0)/2
int mySqrt(int x)
{
   double x0 =x;
   int c = x;
   int res;
   while(fabs(x0*x0-x)>0.1)
   {
       
       x0 = (c/x0+x0)*0.5;
       
   }
   res = floor(x0);
    
    
}



int main(void)
{
    int value = 3;
    int res = mySqrt(value);
    
} 



