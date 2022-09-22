//
// Created by xiaohu feng on 2022/9/19.

#include "iostream"
#include "string"
#include "vector"
using namespace std;

int maxValue(vector<vector<int>>& grid) {
  vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size()));
  dp[0][0] = grid[0][0];
  for(int i=0;i<grid.size();i++)
  {
         for(int j=0;j<grid[i].size();j++)
    {
      if(i==0 && j==0) dp[i][j] = grid[i][j];
      else if(i==0 && j!=0) dp[i][j] = dp[i][j-1] + grid[i][j];
      else if(i!=0 && j==0) dp[i][j] = dp[i-1][j] + grid[i][j];
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
    }
  }
  return dp[grid.size()-1][grid[0].size()-1];
}
int main()
{
  vector<vector<int>> test = {{1,3,1},
                              {1,5,1},
                              {4,2,1}
  };
  int res = maxValue(test);

  return 0;
}
