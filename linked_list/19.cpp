// 移除与插入链表元素
// 删除链表的倒数第N个结点
#include <iostream>
#include <stack>
using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 创建哑结点
        ListNode *sentinel = new ListNode(0,head);

        // 双指针法(100%/65.8%)
        // ListNode *first = head;
        // ListNode *second = sentinel;

        // for(int i = n-1; i >= 0; i--)
        // {
        //     first = first->next;
        // }

        // while(first != nullptr)
        // {
        //     first = first->next;
        //     second = second->next;
        // }

        // second->next = second->next->next;

        // return sentinel->next;

        // 栈
        stack<ListNode*> stk;
        ListNode * cur = sentinel;
        while (cur != nullptr) 
        {
            stk.push(cur);
            cur = cur->next;
        }
        
        for (int i = 0; i < n; i++)
        {
            stk.pop();
        }

        ListNode *prev = stk.top();
        prev->next = prev->next->next;

        return sentinel->next;
        
        
    }
};