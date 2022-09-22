//
// Created by xiaohu feng on 2022/9/18.
//
#include "iostream"
#include "string"
#include "vector"
using namespace std;
bool istranslate(string &str1,string& str2)
{
  if(str1 >="0" && str1 <= "1") return true;
  else if(str1 == "2" && str2>="0" && str2 <= "5") return true;
  else return false;
}

int translateNum(int num) {
  //if(num<10 && num>=0) return 1;
  vector<string> nums;
  int temp = num;
  while(temp)
  {
    int reminder = temp%10;
    temp = temp/10;
    nums.push_back(to_string(reminder));
  }
  std::reverse(nums.begin(), nums.end());
  vector<int> dp(nums.size()+1,0);
  dp[0] = 1;
  dp[1] = 1;
  string zero("0");
  for(int i=2;i<=nums.size();i++)
  {
    if(i>0 && istranslate(nums[i-2],nums[i-1]))
    {
      if( (nums[i-2].compare(zero)) == 0) dp[i] = dp[i-1];
      else dp[i] = dp[i-1] + dp[i-2];

    }

    else {
      dp[i] = dp[i-1];
    }

  }
  return dp[nums.size()];
}
int main()
{
  int num = 18822;
  int res = translateNum(num);
  return 0;
}
