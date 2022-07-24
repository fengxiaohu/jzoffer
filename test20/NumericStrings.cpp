//


#include <stdio.h>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);
bool isExp(const char** str);

// 分别判断整数。小数部分，指数部分
// return true for the right format
bool isNumeric(const char* str)
{
  bool is_interger,is_exp,is_dot,is_dot_integer;
  if(str == NULL)
  {
    return false;
  }
  is_interger = scanInteger(&str);

  if(*str == 'E' || *str == 'e')
  {
    ++str;
    // 必须同时满足Integer(+-)E(Integer) -100+E12
    return is_interger && scanInteger(&str);
  }


  if(*str == '.')
  {
    str++;
    is_dot_integer = scanInteger(&str);
    // reach the end
    if(*str == '\0')
    {
      return is_dot_integer;
    }
    else if(*str == 'E' || *str == 'e')
    {
      ++str;
      // 必须同时满足Integer(+-)E(Integer) -100+E12

    }

    else{}
    //

    return is_dot_integer && scanInteger(&str);

  }
  return is_interger;
}
bool scanInteger(const char**str)
{
  if(**str == '+' || **str == '-')
  {
    (*str)++;
  }
  return scanUnsignedInteger(str);
}

bool scanUnsignedInteger(const char** str)
{
  const char* start = *str;
  while(!(**str == '.' || **str == '\0'))
  {
    if(**str>='0' && **str<='9')
    {
      (*str)++;
    }
    else if(**str == 'e' || **str == 'E')
    {

      return true;
    }
    else
    {
      return false;
    }
  }
  return *str>start;
}



// ====================���Դ���====================
void Test(const char* testName, const char* str, bool expected)
{
  if(testName != nullptr)
    printf("%s begins: ", testName);

  if(isNumeric(str) == expected)
    printf("Passed.\n");
  else
    printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
  Test("Test1", "100", true);
  Test("Test2", "123.45e+6", true);
  Test("Test3", "+500", true);
  Test("Test4", "5e2", true);
  Test("Test5", "3.1416", true);
  Test("Test6", "600.", true);
  Test("Test7", "-.123", true);
  Test("Test8", "-1E-16", true);
  Test("Test9", "1.79769313486232E+308", true);

  printf("\n\n");

  Test("Test10", "12e", false);
  Test("Test11", "1a3.14", false);
  Test("Test12", "1+23", false);
  Test("Test13", "1.2.3", false);
  Test("Test14", "+-5", false);
  Test("Test15", "12e+5.4", false);
  Test("Test16", ".", false);
  Test("Test17", ".e1", false);
  Test("Test18", "e1", false);
  Test("Test19", "+.", false);
  Test("Test20", "", false);
  Test("Test21", nullptr, false);

  return 0;
}
