// 链表中的双指针技巧
// 链表的中间节点
// https://leetcode.cn/problems/middle-of-the-linked-list/

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
    ListNode *middleNode(ListNode *head)
    {
        // 100%/94.61%
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=nullptr)
        {
            fast = fast->next;
            if(fast!=nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return slow;
    }
};