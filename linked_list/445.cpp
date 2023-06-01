// 链表高精度加法
// 两数相加 II
// https://leetcode.cn/problems/add-two-numbers-ii/
#include <iostream>
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 栈(其实和原本的编号为2的“两数相加”，没什么区别，只是加了一个逆序)(83.82%, 53.24%)
        stack<ListNode *> stk1;
        stack<ListNode *> stk2;

        ListNode *temp = l1;
        int carry = 0;

        while (temp != nullptr)
        {
            stk1.push(temp);
            temp = temp->next;
        }

        temp = l2;
        while (temp != nullptr)
        {
            stk2.push(temp);
            temp = temp->next;
        }
        ListNode *add1 = new ListNode(0);
        ListNode *add2 = new ListNode(0);

        while (!stk1.empty() or !stk2.empty())
        {
            if (!stk1.empty())
            {
                add1 = stk1.top();
                stk1.pop();
            }
            else
            {
                temp = new ListNode(0, add1);
                add1 = temp;
            }

            if (!stk2.empty())
            {
                add2 = stk2.top();
                stk2.pop();
            }
            else
            {
                temp = new ListNode(0, add2);
                add2 = temp;
            }

            int num = (add1->val + add2->val + carry);
            add1->val = num % 10;
            carry = num / 10 == 0 ? 0 : 1;
        }

        if (carry != 0)
        {
            temp = new ListNode(carry, add1);
            carry = 0;
            add1 = temp;
        }

        return add1;
    }
};