class Solution {
public:
    
    int cuttingRope(int n) {
    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 2;
    int numberOf3 = n/3;
    int reminder = n%3;
    long ret = 1;
    for(int i=1;i<=((reminder==1)?(numberOf3-1):numberOf3);i++)
    {
        ret = (ret*3)%1000000007;
    }
    if(reminder==0) return ret;
    if(reminder==1) return ret*4%1000000007;
    return ret*2%1000000007;
    }
};
