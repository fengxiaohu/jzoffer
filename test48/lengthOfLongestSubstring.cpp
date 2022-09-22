//
// Created by xiaohu feng on 2022/9/19.
//
#include "iostream"
#include "string"
#include "vector"
using namespace std;
#include "unordered_map"
int lengthOfLongestSubstring(string s) {

  unordered_map<char,int> map;
  vector<int> dp(s.size(),0);
  dp[0] = 1;
  map[s[0]] = 0;
  int prev=0;
  for(int i = 1;i<dp.size();i++)
  {
    if(map.count(s[i])==0)
    // 之前从未出现过字符
    {
      dp[i] = dp[i-1] + 1;

    }
    else
    　// 之前出现过字符，看是否在dp[i-1] 范围内
    {
      if(dp[i-1] >= i-map[s[i]])
      {
        dp[i] = i - map[s[i]];
      }
      else
      {
        dp[i] = dp[i-1] + 1;
      }
    }
    map[s[i]] = i;

  }
  sort(dp.begin(),dp.end());
  return dp[dp.size()-1];
}

int main(void)
{
   string  str("pwwkew");
  //string  str("ab");
  int res  = lengthOfLongestSubstring(str);
  return 0;
}
