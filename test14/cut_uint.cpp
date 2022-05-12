class Solution {
public:
    int cuttingRope(int n) {
    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 2;
    int numOf3 = n/3;
    int leftNumber = n%3;
    if(leftNumber == 0) return pow(3,numOf3);
    if(leftNumber == 1) return pow(3,numOf3-1)*4;
    if(leftNumber == 2) return pow(3,numOf3)*2; 
    return 0;
    }
};
