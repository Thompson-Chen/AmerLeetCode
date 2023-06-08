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
    ListNode *partition(ListNode *head, int x)
    {
        // 88.6%/36.5%
        if (head == nullptr or head->next == nullptr)
        {
            return head;
        }
        ListNode *sentinel = new ListNode(-1, head);
        // 双指针法——一个指向当前小于x的子链表的末尾，一个指向当前要判断的节点
        ListNode *small = sentinel;
        ListNode *pre = sentinel;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            if (cur->val >= x)
            {
                cur = cur->next;
                pre = pre->next;
            }
            else
            {
                if (pre == small)
                {
                    // 如果当前要判断的节点刚好在small的后面，则直接移位不需要交换
                    small = small->next;
                    cur = cur->next;
                    pre = pre->next;
                    continue;
                }
                // 节点移动操作
                pre->next = cur->next;
                cur->next = small->next;
                small->next = cur;
                small = small->next;
                cur = pre->next;
            }
        }

        return sentinel->next;
    }
};