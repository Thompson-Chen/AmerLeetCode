// 链表中的双指针技巧
// 环形链表II
// https://leetcode.cn/problems/linked-list-cycle-ii/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 77%/35.46%
        // 推导数学关系式
        // 相遇点到成环点的距离和起点到成环点的距离相等
        if (head == nullptr)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
            }
            if (fast == nullptr or slow == nullptr)
                return nullptr;
        } while (slow != fast);

        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }

        return head;
    }
};