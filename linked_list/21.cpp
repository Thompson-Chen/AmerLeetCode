#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // // 直接法 61.99%/9.43%
        // ListNode *sentinel = new ListNode(-1);
        // ListNode *cur = sentinel;

        // while (list1 != nullptr and list2 != nullptr)
        // {
        //     if(list1->val <= list2->val)
        //     {
        //         cur->next = list1;
        //         cur = cur->next;
        //         list1 = list1->next;
        //     }
        //     else
        //     {
        //         cur->next = list2;
        //         cur = cur->next;
        //         list2 = list2->next;
        //     }
        // }

        // if(list1 != nullptr)
        // {
        //     cur->next = list1;
        // }
        // else if (list2 != nullptr)
        // {
        //     cur->next = list2;
        // }
        // return sentinel->next;

        // 递归
        if(list1 == nullptr)
        {
            return list2;
        }
        else if(list2 == nullptr)
        {
            return list1;
        }
        else if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};