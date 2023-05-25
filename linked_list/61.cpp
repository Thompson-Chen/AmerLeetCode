// 链表的旋转与反转
// 旋转链表
// https://leetcode.cn/problems/rotate-list/
#include <iostream>
using namespace std;

// Definition for singly-linked list
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // 20.34%/28.65%
        ListNode *tail = head;
        if (tail == nullptr)
        {
            return tail;
        }
        int count = 1;
        while (tail->next != nullptr)
        {
            count++;
            tail = tail->next;
        }
        k = k % count;
        if (k == 0)
        {
            return head;
        }
        int num = count - 1 - k;
        ListNode *split = head;
        for (int i = 0; i < num; i++)
        {
            split = split->next;
        }

        tail->next = head;
        head = split->next;
        split->next = nullptr;
        return head;
    }
};