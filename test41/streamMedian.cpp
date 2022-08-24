//
// Created by xiaohu feng on 2022/8/24.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include "exception"

using namespace std;

template<typename T> class DynamicArray
{
 public:
  void Insert(T num)
  {

    if((min.size()+max.size()) & 1)
    {
      if( max.size() && num < max.front() )
      {
        max.push_back(num);
        // default is max heap
        push_heap(max.begin(),max.end());
        num  = max.front();

        pop_heap(max.begin(),max.end());
        max.pop_back();

      }
      min.push_back(num);
      push_heap(min.begin(),min.end(),greater<T>());

    }
    else
    {
      if(  min.size() && num > min.front() )
      {
        min.push_back(num);
        push_heap(min.begin(),min.end(),greater<T>());
        num = min.front();
        pop_heap(min.begin(),min.end(),greater<T>());
        min.pop_back();
      }
      max.push_back(num);
      push_heap(max.begin(),max.end());

    }
  }
  T GetMedian()
  {
    if( (min.size() + max.size()) & 1 && max.size())
    {
      return max.front();
    }
    else if(max.size() && min.size())
    {
      return  (max.front() +  min .front()) / 2;
    }
    else
    {
      throw runtime_error("No numbers are available");
    }

  }

 private:
  vector<T> min;
  vector<T> max;
};

// ====================���Դ���====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
  if(testName != nullptr)
    printf("%s begins: ", testName);

  if(abs(numbers.GetMedian() - expected) < 0.0000001)
    printf("Passed.\n");
  else
    printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
  DynamicArray<double> numbers;

  printf("Test1 begins: ");
  try
  {
    numbers.GetMedian();
    printf("FAILED.\n");
  }
  catch(const exception&)
  {
    printf("Passed.\n");
  }

  numbers.Insert(5);
  Test("Test2", numbers, 5);

  numbers.Insert(2);
  Test("Test3", numbers, 3.5);

  numbers.Insert(3);
  Test("Test4", numbers, 3);

  numbers.Insert(4);
  Test("Test6", numbers, 3.5);

  numbers.Insert(1);
  Test("Test5", numbers, 3);

  numbers.Insert(6);
  Test("Test7", numbers, 3.5);

  numbers.Insert(7);
  Test("Test8", numbers, 4);

  numbers.Insert(0);
  Test("Test9", numbers, 3.5);

  numbers.Insert(8);
  Test("Test10", numbers, 4);

  return 0;
}
