#include <iostream>
#include <vector>
using namespace std;
int dfs(int i, int m,int j,int n, int k,int count, vector<vector<int>> &isVisit);
bool isMove(int i,int j,int k);
int caculateSum(int number);
int movingCount(int m, int n, int k) {
    vector< vector<int> >isVisit (n,vector<int>(m,0));
    int count = dfs(0,m,0,n,k,count,isVisit);
    return count;
    }
int dfs(int i, int m,int j,int n, int k,int count, vector<vector<int>> &isVisit)
    {
        if(i<0 || i>=m || j<0 || j>=n || isVisit[j][i]) return 0;
        if(!isMove(i,j,k)) return 0;
        isVisit[j][i] = 1;
       
        return dfs(i+1,m,j,n,k,count,isVisit)
            +dfs(i,m,j+1,n,k,count,isVisit)+1;
         
        
    }
    bool isMove(int i,int j,int k)
    {
        int sumRow = caculateSum(i);
        int sumCol = caculateSum(j);
        if(sumCol+sumRow<=k) return true;
        else return false;
    }
    int caculateSum(int number)
    {
        int res=0;
        if(number<0) return 0;
        
        while(number>0)
        {
            res = res+number%10;
            
            number = number/10;
        }
        return res; 
    } 
int main(void)
{
    int res = movingCount(38,15,9);
 } 
