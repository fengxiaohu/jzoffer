//
// Created by xiaohu feng on 2022/9/23.
//

#include "iostream"
#include "unordered_map"
#include "vector"

 struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
   };

using namespace std;
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  unordered_map<ListNode*,int> map;
  ListNode *tmp = headA;
  while(tmp)
  {
    map[tmp]++;
    tmp = tmp->next;
  }
  tmp = headB;
  while(tmp)
  {
    if(map.count(tmp))
    {
      return tmp;
    }
    tmp = tmp->next;
  }
  return nullptr;
}
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  ListNode* l1 = headA;
  ListNode* l2 = headB;
  while(1)
  {
    if(l1 == l2)
    {
      return l1;
    }
    else if(!(l1->next)) l1 = headB;
    else if(!(l2->next)) l2 = headA;
    l1 = l1->next;
    l2 = l2->next;
  }
}
int main()
{
  return 0;
}
