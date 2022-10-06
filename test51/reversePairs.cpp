//
// Created by xiaohu feng on 2022/9/22.
//
#include "iostream"
#include "vector"
using namespace std;
int cnt;
void mergesort(vector<int>& nums,vector<int>& tmp,int left,int right)
{
  if(left>=right) return ;
  int mid = (left + right)/2;
  mergesort(nums,tmp,left,mid);
  mergesort(nums,tmp,mid+1,right);

  int i = left;
  int j = mid+1;
  int k = 0;

  while(i <= mid && j<=right)
  {
    if(nums[i] <= nums[j])
    {
      tmp[k++] = nums[i++];
    }
    else
    {
      tmp[k++] = nums[j++];
      cnt+= mid-i+1;
    }
  }
  while(i<=mid)
  {
    tmp[k++] = nums[i++];
  }
  while(j<=right)
  {
    tmp[k++] = nums[j++];
  }
  for(i=0,j=left;j<=right;i++,j++)
  {
    nums[j] = tmp[i];
  }
}
int reversePairs(vector<int>& nums) {
  vector<int>tmp(nums.size(),0);

  mergesort(nums,tmp,0,nums.size()-1);
  return cnt;
}
int main()
{
  vector<int>test{7,5,6,4};
  int res = reversePairs(test);

  return 0;
}
