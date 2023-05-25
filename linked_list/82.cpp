// 移除与插入链表元素
// 删除排序链表中的重复元素 II
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 双指针法(66.57/8.54)
        ListNode *sentinel = new ListNode(-101, head);
        ListNode *prev = sentinel;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            if (cur->next != nullptr and cur->val == cur->next->val)
            {
                // 移动节点
                cur = cur->next;
            }
            else
            {
                if (prev->next != cur)
                {
                    // 中间隔着的都是重复值
                    prev->next = cur->next;
                }
                else
                {
                    // 正常移动即可
                    prev = prev->next;
                }
                cur = cur->next;
            }
        };
        return sentinel->next;
    }
};