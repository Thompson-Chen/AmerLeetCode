// 链表的遍历
// 扁平化多级双向链表
// https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *DFS(Node *head)
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->child == nullptr)
            {
                if (cur->next != nullptr)
                {
                    cur = cur->next;
                }
                else
                {
                    break;
                }
            }
            else
            {
                // 当前节点存在子链表
                Node *sub_tail = this->DFS(cur->child);
                if (cur->next != nullptr)
                {
                    sub_tail->next = cur->next;
                    cur->next->prev = sub_tail;
                }
                cur->child->prev = cur;
                cur->next = cur->child;
                cur->child = nullptr;
            }
        }
        return cur; // 返回的是尾节点
    };
    Node *flatten(Node *head)
    {
        // 深度优先搜索(100%/25.78%)
        Node *cur = head;

        this->DFS(head);

        return head;
    }
};