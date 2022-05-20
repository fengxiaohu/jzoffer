#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool addNumInString(string &s);
void addNumInVector(int num);

vector<int> res;
vector<int> printNum(int n)
{
    
    string s(n,'0');
    while(!addNumInString(s))
    {
        addNumInVector(stoi(s));                                      
    }
    return res;
}
bool addNumInString(string &s)
{
    int carry = 0;
    bool isOverflow = false;
    for(int i=s.length()-1;i>=0;i--)
    {
        int current = (s[i]-'0')+carry;
        if(i == s.size()-1) current++;
        if(current>=10)
            {
                if(i==0) 
                {isOverflow = true;}
                else
                {
                    s[i] = current -10+'0';
                    carry =1;
                }
            }
        else 
            {
                s[i] = '0'+current;
                break;
                
            }
    }
    return isOverflow;
}
void addNumInVector(int num)
{
    res.push_back(num);
}
int main(void)
{
    printNum(3);
    
    for(auto &it : res)
    {
        cout << it <<endl;
    }
    
}
















