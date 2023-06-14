// 链表中的双指针技巧
// 重排链表
// https://leetcode.cn/problems/reorder-list/
#include <iostream>
#include <deque>
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
    void reorderList(ListNode *head)
    {
        // 双端队列deque
        deque<ListNode *> dq;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            dq.push_back(curr);
            curr = curr->next;
        }
        ListNode *sentinel = new ListNode(0,head);
        curr = sentinel;
        // 双端出队列
        while (!dq.empty())
        {
            curr->next = dq.front();
            curr = curr->next;
            dq.pop_front();
            if (!dq.empty())
            {
                curr->next = dq.back();
                curr = curr->next;
                dq.pop_back();
            }
            else
            {
                curr->next = nullptr;
            }
        }
    }
};

int main()
{
    ListNode *t1 = new ListNode(3);
    ListNode *t2 = new ListNode(2,t1);
    ListNode *t3 = new ListNode(1,t2);

    Solution s = Solution();
    s.reorderList(t3);
}