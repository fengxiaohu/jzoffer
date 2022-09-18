//
// Created by xiaohu feng on 2022/9/17.
//

#include "iostream"
#include "string"
#include "vector"
using namespace std;

/*
void backtrace(vector<int>& nums,string path,vector<string>& allres,int depth,vector<bool>& visited)
{
  if(depth>=nums.size())
  {
    allres.push_back(path);
    return;
  }
  for(int i = 0;i<nums.size();i++)
  {

    if(visited[i]==false) {
      visited[i] = true;
      path += to_string(nums[i]);
      backtrace(nums, path, allres, depth + 1, visited);
      visited[i] = false;
      path.erase(path.size()- to_string(nums[i]).size(),to_string(nums[i]).size());

    }



  }

}

string minNumber(vector<int>& nums) {
  string  res;
  vector<string> allres;
  vector<bool> visited(nums.size(), false);
  if(nums.size() == 0) return res;
  backtrace(nums,res,allres,0,visited);
  sort(allres.begin(),allres.end());
  return *allres.begin();

}
 */

bool cmp(string& str1,string& str2)
{
  return str1+str2 < str2+str1;
}
string minNumber(vector<int>& nums) {
  vector<string> str;
  string  res;
  for(int i=0;i<nums.size();i++)
  {
    str.push_back(to_string(nums[i]));
  }
  sort(str.begin(),str.end(),cmp);
  for(int i=0;i<nums.size();i++)
  {
    res.append(str[i]);
  }
  return res;


}
int main(void)
{
  vector<int> test = {3,32,321};
  string  res = minNumber(test);

  return 0;



}
