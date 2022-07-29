/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������26�������ӽṹ
// ��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��

#include <cstdio>

struct BinaryTreeNode
{
  double                 m_dbValue;
  BinaryTreeNode*        m_pLeft;
  BinaryTreeNode*        m_pRight;
};

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool Equal(double num1, double num2);

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
  if(pRoot1== nullptr || pRoot2== nullptr)
  {
    return false;
  }
  bool res1,res2;
  if(Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
  {
    res1 = DoesTree1HaveTree2(pRoot1,pRoot2);
  }
  res2 = HasSubtree(pRoot1->m_pLeft,pRoot2) || HasSubtree(pRoot1->m_pRight,pRoot2);


  return res1 || res2;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
  if(pRoot2 == NULL)
  {
    return  true;
  }
  if(pRoot1 == NULL)
  {
    return false;
  }
  if(Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
  {
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
  }
  else
  {
    return false;
  }


}

bool Equal(double num1, double num2)
{
  if(num1>num2)
  {
    return  num1-num2<1e-15;
  } else
  {
    return num2-num1<1e-15;
  }
}

// ====================�������Դ���====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
  BinaryTreeNode* pNode = new BinaryTreeNode();
  pNode->m_dbValue = dbValue;
  pNode->m_pLeft = nullptr;
  pNode->m_pRight = nullptr;

  return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
  if(pParent != nullptr)
  {
    pParent->m_pLeft = pLeft;
    pParent->m_pRight = pRight;
  }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
  if(pRoot != nullptr)
  {
    BinaryTreeNode* pLeft = pRoot->m_pLeft;
    BinaryTreeNode* pRight = pRoot->m_pRight;

    delete pRoot;
    pRoot = nullptr;

    DestroyTree(pLeft);
    DestroyTree(pRight);
  }
}

// ====================���Դ���====================
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
  if(HasSubtree(pRoot1, pRoot2) == expected)
    printf("%s passed.\n", testName);
  else
    printf("%s failed.\n", testName);
}

// ���н�㺬�зֲ棬��B����A���ӽṹ
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
  ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
  ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

  Test("Test1", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ���н�㺬�зֲ棬��B������A���ӽṹ
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
  ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
  ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

  Test("Test2", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ���н��ֻ�����ӽ�㣬��B����A���ӽṹ
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
void Test3()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
  ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
  ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
  ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
  ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

  Test("Test3", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ���н��ֻ�����ӽ�㣬��B������A���ӽṹ
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
void Test4()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
  ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
  ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
  ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);

  ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
  ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

  Test("Test4", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ���н��ֻ�����ӽ�㣬��B����A���ӽṹ
//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
void Test5()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
  ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
  ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, nullptr, pNodeB3);

  Test("Test5", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ��A�н��ֻ�����ӽ�㣬��B������A���ӽṹ
//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
void Test6()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
  ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
  ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

  Test("Test6", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// ��AΪ����
void Test7()
{
  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

  Test("Test7", nullptr, pNodeB1, false);

  DestroyTree(pNodeB1);
}

// ��BΪ����
void Test8()
{
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

  Test("Test8", pNodeA1, nullptr, false);

  DestroyTree(pNodeA1);
}

// ��A����B��Ϊ��
void Test9()
{
  Test("Test9", nullptr, nullptr, false);
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
