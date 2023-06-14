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
        // // 双端队列deque
        // deque<ListNode *> dq;
        // ListNode *curr = head;

        // while (curr != nullptr)
        // {
        //     dq.push_back(curr);
        //     curr = curr->next;
        // }
        // ListNode *sentinel = new ListNode(0,head);
        // curr = sentinel;
        // // 双端出队列
        // while (!dq.empty())
        // {
        //     curr->next = dq.front();
        //     curr = curr->next;
        //     dq.pop_front();
        //     if (!dq.empty())
        //     {
        //         curr->next = dq.back();
        //         curr = curr->next;
        //         dq.pop_back();
        //     }
        //     else
        //     {
        //         curr->next = nullptr;
        //     }
        // }

        // （解法2）反转链表 + 找中点 + 合并
        // 快慢指针找中点以及反转链表
                if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

        ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }

};

int main()
{
    ListNode *t1 = new ListNode(3);
    ListNode *t2 = new ListNode(2, t1);
    ListNode *t3 = new ListNode(1, t2);

    Solution s = Solution();
    s.reorderList(t3);
}