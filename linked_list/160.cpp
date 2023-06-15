// 链表中的双指针技巧
// 相交链表
// https://leetcode.cn/problems/intersection-of-two-linked-lists/
#include <iostream>
#include <stack>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 栈（90.46%/19.49%）
        stack<ListNode *> stkA;
        stack<ListNode *> stkB;

        while (headA != nullptr)
        {
            stkA.push(headA);
            headA = headA->next;
        }

        while (headB != nullptr)
        {
            stkB.push(headB);
            headB = headB->next;
        }

        ListNode *intersect = nullptr;
        while (!stkA.empty() and !stkB.empty())
        {
            if (stkA.top() == stkB.top())
            {
                intersect = stkA.top();
                stkA.pop();
                stkB.pop();
            }
            else
            {
                break;
            }
        }

        if (intersect == nullptr)
        {
            return NULL;
        }
        return intersect;
    }
};

int main()
{
}