class Solution {
public:
       
    double fastpow(double x,int n)
    {
        double temp=1.0;
    while(n!=0)
    {
        if(n&1) temp *= x;
        x = x*x;
        n >>=1;
    }
    return temp;
    
    }
    
    double myPow(double x, int n) {
    
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(n==1) return x;
    if(n==0 && x!=0) return 1;
    if(n<0) {
        x = 1.0/x;
        if(n == 0x80000000) 
        {   n=32;
            return fastpow(x,n);
        }
        n = -n;
    }
    return fastpow(x,n);
    }
};
