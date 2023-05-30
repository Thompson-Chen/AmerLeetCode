// 链表的旋转与反转
// K个一组翻转链表
// https://leetcode.cn/problems/reverse-nodes-in-k-group/

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
private:
    ListNode *reverseLinkedList(ListNode *prev, int k)
    {
        ListNode *cur = prev->next;
        ListNode *next = cur;
        // 判断剩余的节点数是否大于等于k
        for (size_t i = 0; i < k; i++)
        {
            if (next == nullptr)
            {
                return nullptr;
            }
            next = next->next;
        }

        // 执行反转操作
        next = cur->next;
        for (int i = 0; i < k - 1; i++)
        {
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }

        return cur;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 模拟法（54.36%/83.61%）
        if (head == nullptr or head->next == nullptr or k <= 1)
            return head;

        ListNode *sentinel = new ListNode(0, head);
        ListNode *node = sentinel;
        while (node != nullptr)
        {
            node = reverseLinkedList(node,k);
        }
        return sentinel->next;
    }
};