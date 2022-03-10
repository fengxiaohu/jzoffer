#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/* method1: dynamic programming  
int fib(int n)
{
    vector<int> dp(n+1);
    //int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    if(n==0) return dp[0];
    if(n==1) return dp[1];
    for(int i=2;i<=n;i++) 
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
*/
// method2 save space
int fib(int n)
{
    int fib_0 = 0;
    int fib_1 = 1;
    int fib_2;
    
    if(n==0) return fib_0;
    if(n==1) return fib_1;
    for(int i=2;i<=n;i++) 
    {
        fib_2 = (fib_0+fib_1)% 1000000007;
        fib_0 = fib_1;
        fib_1 = fib_2;    
        //dp[i] = dp[i-1]+dp[i-2];
    }
    return fib_2;
}

int main(void)
{
    int res = fib(5);
}
