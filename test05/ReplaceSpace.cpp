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

void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    
    const char* str = replaceSpace(str, str.le);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}



/*
int main(int argc,char **argv)
{
    string test = "we are happy.";
    string replace_str = replaceSpace(test);
    cout << test<<endl;
    cout<<replace_str<<endl;
    return 0;
}
*/



