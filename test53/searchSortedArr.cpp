//
// Created by xiaohu feng on 2022/9/23.
//


#include "iostream"
#include "vector"

using namespace std;

int search(vector<int>& nums, int target) {
  if(nums.size() == 0) return 0;
  int left = 0;
  int right = nums.size()-1;
  int mid;
  while(left<=right)
  {
    mid = (left + right)/2;
    if(nums[mid]<=target) left = mid+1;
    else right = mid-1;
  }
  if(right>=0 && nums[right] != target)
  {
    return 0;
  }
  int right_bound = left;
  left = 0;
  right = nums.size()-1;

  while(left <= right)
  {
    mid = (left + right)/2;
    if(nums[mid] >= target)
    {
      right = mid-1;
    }
    else left = mid+1;
  }
  int left_bound = right;
  return  right_bound-left_bound-1;

}
/*
int search(vector<int>& nums, int target) {
  if(nums.size() == 0) return 0;
  int left = 0;
  int right = nums.size()-1;
  int mid;

  while(left <= right)
  {
    mid = (left + right)/2;
    if(nums[mid] <= target)
    {
      left = mid+1;
    }
    else right = mid-1;

  }

  if(nums[right] !=target ) return 0;
  int right_bound = right;
  left = 0;
  right = nums.size()-1;
  while(left <= right)
  {
    mid = (left + right) / 2;
    if(nums[mid] >= target)
    {
      right = mid-1;
    }

    else left = mid+1;

  }
  return right_bound-left + 1;


}
 */
int main()
{
   vector<int>test{5,7,7,8,8,10};
  //vector<int>test{2,2};
  int res = search(test,8);
  return 0;
}

