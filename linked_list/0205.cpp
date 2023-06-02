// 链表高精度加法
// 面试题 02.05. 链表求和
// https://leetcode.cn/problems/sum-lists-lcci/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 这个和编号为2的题有啥区别……
        // 默认拿链表1来当结果的存储链表(60.18%/91.73%)
        int carry = 0;
        ListNode *head = l1;
        if(l1 == nullptr)
        {
            return l2;
        }
        else if (l2 == nullptr)
        {
            return l1;
        }
        while (l1 != nullptr or l2 != nullptr)
        {
            int temp = l1->val + l2->val + carry;
            l1->val = temp % 10;
            carry = temp / 10 == 0 ? 0 : 1;
            if (l1->next == nullptr and l2->next != nullptr)
            {
                ListNode *newl1 = new ListNode(0);
                l1->next = newl1;
            }
            else if (l2->next == nullptr and l1->next != nullptr)
            {
                ListNode *newl2 = new ListNode(0);
                l2->next = newl2;
            }
            else if (l1->next == nullptr and l2->next == nullptr and carry == 1)
            {
                // 判断carry是否等于1
                ListNode *newl1 = new ListNode(1);
                l1->next = newl1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return head;
    }
};