// 链表中的双指针技巧
// 环形链表
// https://leetcode.cn/problems/linked-list-cycle/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // 92.45%/66.28%
        if (head == nullptr)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        } while (fast != nullptr and fast != slow);

        if (fast != nullptr and fast == slow)
            return true;
        else
            return false;
    }
};