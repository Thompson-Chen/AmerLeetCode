// 链表的旋转与反转
// 两两交换链表中的节点
// https://leetcode.cn/problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head)
    {
        // // 法1：三指针法(56.67%、37.70)
        // // 无节点或单节点
        // if(head == nullptr or head->next == nullptr)
        // {
        //     return head;
        // }
        // ListNode * sentinel = new ListNode(0,head);

        // ListNode * prev = sentinel;
        // ListNode * cur = head;
        // ListNode * next = head->next;

        // while(cur != nullptr and next != nullptr)
        // {
        //     prev->next = next;
        //     cur->next = next->next;
        //     next->next = cur;

        //     prev = cur;
        //     cur = cur->next;
        //     if(cur == nullptr){
        //         break;
        //     }
        //     else{
        //         next = cur->next;
        //     }
        // }

        // return sentinel->next;

        // 法2：递归（6.34%/5.49%）
        // swapPairs(ListNode head) 的意义就是两两翻转链表中的节点+返回翻转后的新的头结点
        if (head == nullptr or head->next == nullptr)
        {
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};