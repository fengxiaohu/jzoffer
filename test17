class Solution {
public:
    int hammingWeight(uint32_t n) {
        int digit,count=0;
        while(n!=0)
        {
            digit = n & 0x0001;
            if(digit == 1) count++;
            n = n >>1;
        }
        return count;
    }
};
