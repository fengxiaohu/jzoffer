#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
using namespace std;
// Hint: consider we use the assert to test


/* method1: using hashset time:O(n) sqpce: O(n)
class Solution_dup_num{
    public:
    int findRepeatNumber(vector<int>& nums)
    {
        unordered_map<int,int> res;
        for(int num:nums)
        {
            res[num]++; // 
            if(res[num]>1)
            {
                cout<<"dup number is "<<num<<endl;
                return num; 
            }
            
            
        }
        return -1;
    }
};
*/
// method 2  time:O(n) sqpce: O(1)
class Solution_dup_num{
    public:
    int findRepeatNumber(vector<int>& nums)
    {
        int i=0;
        
            while(i<nums.size())
            {
                if(nums[i] == i)
                {
                    i++;
                    continue;
                }
                if(nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }
                else
                {
                    int temp;
                    temp = nums[i];
                    nums[i]=nums[nums[i]];
                    nums[temp] = temp;
                    i++;
                }
               
            }
            return -1;
        
    }
};
int main(int argc,char** argv)
{
    Solution_dup_num dup_num;
    vector<int> nums = {2,3,1,0,2,5,3};
   
    int res = dup_num.findRepeatNumber(nums);
    cout<<"result dup is "<<res<<endl;
     
    
}

