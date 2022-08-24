//
// Created by xiaohu feng on 2022/8/24.
//
#include "iostream"
#include "vector"
using namespace std;
int maxSubArray(vector<int>& nums) {
  vector<int> dp(nums.size(),0);
   dp[0] = nums[0];
  int max = nums[0];
  for(int i = 1;i<nums.size();i++)
  {
    dp[i-1] > 0 ? dp[i] = dp[i-1] + nums[i] : dp[i] = nums[i];
    if(dp[i] > max) max = dp[i];
  }
  return max;



}
int main(){
vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
int res = maxSubArray(test);


}
