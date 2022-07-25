//
// Created by xiaohu feng on 2022/7/24.
//



#include <cstdio>

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// ====================����һ====================
void ReorderOddEven_1(int *pData, unsigned int length)
{
  int *p1,*p2;
  int temp= 0;
  p1 = pData;
  p2 = pData+1;
  while(p1!=(pData+length))
  {
    p2 = p1+1;
    if((*p1 % 2) == 1)
    {
      p1++;
      continue;

    }
      else
      {
        while (p2 != (pData + length)) {
          if (*p2 % 2 == 1) {
            temp = *p1;
            *p1 = *p2;
            *p2 = temp;
            break;
          }
          else
          {
            p2++;
          }

        }
      }
      p1++;
  }
}

// ====================������====================
void ReorderOddEven_2(int *pData, unsigned int length)
{
  Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
  if(pData == nullptr || length == 0)
    return;

  int *pBegin = pData;
  int *pEnd = pData + length - 1;

  while(pBegin < pEnd)
  {
    // ����ƶ�pBegin
    while(pBegin < pEnd && !func(*pBegin))
      pBegin ++;

    // ��ǰ�ƶ�pEnd
    while(pBegin < pEnd && func(*pEnd))
      pEnd --;

    if(pBegin < pEnd)
    {
      int temp = *pBegin;
      *pBegin = *pEnd;
      *pEnd = temp;
    }
  }
}

bool isEven(int n)
{
  return (n & 1) == 0;
}

// ====================���Դ���====================
void PrintArray(int numbers[], int length)
{
  if(length < 0)
    return;

  for(int i = 0; i < length; ++i)
    printf("%d\t", numbers[i]);

  printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
  if(testName != nullptr)
    printf("%s begins:\n", testName);

  int* copy = new int[length];
  for(int i = 0; i < length; ++i)
  {
    copy[i] = numbers[i];
  }

  printf("Test for solution 1:\n");
  PrintArray(numbers, length);
  ReorderOddEven_1(numbers, length);
  PrintArray(numbers, length);

  printf("Test for solution 2:\n");
  PrintArray(copy, length);
  ReorderOddEven_2(copy, length);
  PrintArray(copy, length);

  delete[] copy;
}

void Test1()
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7};
  Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
  int numbers[] = {2, 4, 6, 1, 3, 5, 7};
  Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
  int numbers[] = {1, 3, 5, 7, 2, 4, 6};
  Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
  int numbers[] = {1};
  Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
  int numbers[] = {2};
  Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
  Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();

  return 0;
}
