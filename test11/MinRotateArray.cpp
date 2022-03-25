#include <iostream>
#include <vector>
using namespace std;

int minArray(const vector<int>& numbers) {
    int left = 0;
    int right = numbers.size()-1;
    if(numbers[left]<numbers[right]) return numbers[left];
    // we assume that numbers[left] < numbers[right]
    while((left+1)!=right)
    {
        int mid = left + (right-left)/2;
        if(numbers[mid]>numbers[left])
        {
            left = mid;
        }
        else if(numbers[mid]<numbers[right])
        {
            right = mid;
        }
        /** case numbers[mid] = numbers[left] = numbers[right]
        *  {1,0,1,1,1} and {1,1,0,1,1}  
        */
        else if(numbers[mid] == numbers[left] ||  numbers[mid] ==  numbers[right])
        {
            int min = numbers[left];
            for(int i=left;i<=right;i++)
            {
                if(min>numbers[i]) min = numbers[i]; 
            }
            return min;
        }
    }
    return numbers[right];
   
}
int main(void)
{
    //vector<int> testvec = {3,4,5,7,8,9,1,2};
    vector<int> testvec = {3,1,1};
    int res = minArray(testvec);
}

        
