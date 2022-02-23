#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string replaceSpace(string str)
{
    int original_len = str.length();
    int resize_len;
    int numberOfBalnk = 0;
    int i,j;
    for(i=0;i<original_len;i++)
    {
        if(str[i]==' ')
        {
            numberOfBalnk++;
        }
    }
    resize_len = original_len+2*numberOfBalnk;
    
    str.resize(resize_len);
    for(i = original_len-1,j=resize_len-1;i>=0;i--,j--)
    {
        if(str[i] == ' ')
        {
            str[j] = '0';
            str[j-1] = '2';
            str[j-2] = '%';
            j=j-2;
            
        }
        else
        {
            str[j] = str[i];
        }
    }
    return str;  
}



int main(int argc,char **argv)
{
    string test = "we are happy.";
    string replace_str = replaceSpace(test);
    cout << test<<endl;
    cout<<replace_str<<endl;
    return 0;
}



