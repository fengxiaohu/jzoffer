//
// Created by xiaohu feng on 2022/9/21.
//
#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"
#include "queue"
using namespace std;

/*
int nthUglyNumber(int n) {
  vector<int> factors{2,3,5};
  unordered_set<long> set;
  priority_queue<long,vector<long>,greater<>> queue;
  set.insert(1);
  queue.push(1);
  long cur = 1;
  for(int i=0;i<n;i++)
  {
    cur = queue.top();
    queue.pop();
    for(long num : factors)
    {
      if(set.count(num * cur)==0)
      {
        queue.push(num * cur);
        set.insert(num * cur);

      }
    }
  }
  return cur;

}
 */
int nthUglyNumber(int n) {
  vector<int> dp(n,0);
  dp[0] = 1;
  int a,b,c = 0;
  for(int i = 1;i<n;i++)
  {
    int n1 = 2*dp[a];
    int n2 = 3*dp[b];
    int n3 = 5*dp[c];
    dp[i] = min(min(n1,n2),n3);
    if(dp[i]==n1) a++;
    if(dp[i] == n2) b++;
    if(dp[i] == n3) c++;
  }
  return dp[n-1];
}
int main()
{
  int n = 10;
  int res = nthUglyNumber(n);

  return 0;
}
