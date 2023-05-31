// 链表高精度加法
// 两数相加
// https://leetcode.cn/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0; // 进位变量
        int temp = 0;
        ListNode *l1_temp = l1;
        ListNode *l2_temp = l2;
        // 判断谁长，谁长用谁
        while (l1_temp != nullptr and l2_temp != nullptr)
        {
            l1_temp = l1_temp->next;
            l2_temp = l2_temp->next;
        }
        ListNode *head = new ListNode();
        ListNode *curr = new ListNode();
        ListNode *add = new ListNode();
        if (l1_temp == nullptr)
        {
            head = l2;
            add = l2;
            curr = l1;
        }
        else
        {
            head = l1;
            add = l1;
            curr = l2;
        }

        while (curr != nullptr)
        {
            temp = add->val + curr->val + carry;
            add->val = temp % 10;
            carry = temp >= 10 ? 1 : 0;
            if (add->next == nullptr and carry != 0)
            {
                add->next = new ListNode(carry);
                add = nullptr;
                break;
            }
            else
            {
                add = add->next;
                curr = curr->next;
            }
        }

        while (add != nullptr)
        {
            temp = add->val + carry;
            add->val = temp % 10;
            carry = temp >= 10 ? 1 : 0;
            if (add->next != nullptr or carry == 0)
            {
                add = add->next;
            }
            else if (carry != 0)
            {
                add->next = new ListNode(carry);
                break;
            }
        }
        return head;
    }
};