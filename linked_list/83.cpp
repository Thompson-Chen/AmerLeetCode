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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 98.74/59.44
        ListNode *sentinel = new ListNode(-101,head);

        ListNode *cur = sentinel;

        while(cur != nullptr)
        {
            if(cur->next!= nullptr and cur->val == cur->next->val)
            {
                // 执行删除操作
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }

        return sentinel->next;
    }
};