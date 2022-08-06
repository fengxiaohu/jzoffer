//
// Created by xiaohu feng on 2022/8/5.
//
/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/


#include <cstdio>
#include "Utilities/BinaryTree.h"
#include <vector>

using namespace std;
void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<vector<int>> &res,vector<int> &path);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
  if(pRoot == nullptr)
    return;
  vector<vector<int>> res;
  vector<int> path;
  FindPath(pRoot, expectedSum,res,path);
}

void FindPath
    (
        BinaryTreeNode*   pRoot,
        int               expectedSum,
        vector<vector<int>> &res,
        vector<int> &path
    )
{
  if(pRoot == nullptr) return;
  expectedSum = expectedSum-pRoot->m_nValue;
  path.push_back(pRoot->m_nValue);
  if(pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr && expectedSum ==0)
  {
    vector<int>*pathcopy = (new vector<int>(path));
    res.push_back(*pathcopy);
  }
  FindPath(pRoot->m_pLeft,expectedSum,res,path);
  FindPath(pRoot->m_pRight,expectedSum,res,path);
  path.pop_back();
}



// ====================���Դ���====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
  if(testName != nullptr)
    printf("%s begins:\n", testName);

  FindPath(pRoot, expectedSum);

  printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 22
void Test1()
{
  BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode10, pNode5, pNode12);
  ConnectTreeNodes(pNode5, pNode4, pNode7);

  printf("Two paths should be found in Test1.\n");
  Test("Test1", pNode10, 22);

  DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// û��·���ϵĽ���Ϊ15
void Test2()
{
  BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode10, pNode5, pNode12);
  ConnectTreeNodes(pNode5, pNode4, pNode7);

  printf("No paths should be found in Test2.\n");
  Test("Test2", pNode10, 15);

  DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// ��һ��·������Ľ���Ϊ15
void Test3()
{
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

  ConnectTreeNodes(pNode5, pNode4, nullptr);
  ConnectTreeNodes(pNode4, pNode3, nullptr);
  ConnectTreeNodes(pNode3, pNode2, nullptr);
  ConnectTreeNodes(pNode2, pNode1, nullptr);

  printf("One path should be found in Test3.\n");
  Test("Test3", pNode5, 15);

  DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// û��·������Ľ���Ϊ16
void Test4()
{
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNode1, nullptr, pNode2);
  ConnectTreeNodes(pNode2, nullptr, pNode3);
  ConnectTreeNodes(pNode3, nullptr, pNode4);
  ConnectTreeNodes(pNode4, nullptr, pNode5);

  printf("No paths should be found in Test4.\n");
  Test("Test4", pNode1, 16);

  DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test5()
{
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

  printf("One path should be found in Test5.\n");
  Test("Test5", pNode1, 1);

  DestroyTree(pNode1);
}

// ����û�н��
void Test6()
{
  printf("No paths should be found in Test6.\n");
  Test("Test6", nullptr, 0);
}
void Test7()
{
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(-2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(-3);
  ConnectTreeNodes(pNode2,NULL,pNode3);
  Test("Test7",pNode2,-5);
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

  return 0;
}

