// 移除与插入链表元素
// 移除链表元素
// https://leetcode.cn/problems/remove-linked-list-elements/
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode *cur = sentinel;
        while (cur != nullptr)
        {
            if (cur->next != nullptr and cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return sentinel->next;
    }
};