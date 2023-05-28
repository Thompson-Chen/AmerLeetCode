// 两两交换链表中的节点
// 反转链表
// https://leetcode.cn/problems/reverse-linked-list/
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 栈 (50.28%/10.87)
        stack<ListNode *> stk;
        while(head != nullptr) {
            stk.push(head);
            head = head->next;
        }
        ListNode * sentinel = new ListNode(0);
        ListNode * tmp = sentinel;
        while(!stk.empty()){
            tmp->next = stk.top();
            tmp = tmp->next;
            tmp->next = nullptr; // 这一行非常关键，没有这一行会报错，因为如果不加最后一个节点（原head节点）会成环
            stk.pop();
        }

        return sentinel->next;

        // 改用递归，因为其实函数的栈，递归就是栈
        // reverseList函数的作用是返回传入节点的下一个节点
        // if (!head || !head->next){
        //     return head;
        // }
        // ListNode *temp = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        
        // return temp;
    }
};