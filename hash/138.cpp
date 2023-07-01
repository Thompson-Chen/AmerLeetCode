// 哈希表的查找、插入及删除
// 复制带随机指针的链表
// https://leetcode.cn/problems/copy-list-with-random-pointer/
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // 97.88/89.88
        // 初始链表为空这个一定不要忘记，否则通过不了的！！
        if (head == nullptr)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> umap;
        Node *sentinel = new Node(-1);
        Node *temp = sentinel;
        Node *h1 = head;
        sentinel->next = temp;

        // 创建初始链表
        while (head != nullptr)
        {
            temp->next = new Node(head->val);
            temp = temp->next;
            umap.emplace(head, temp);
            head = head->next;
        }

        // 为各节点的随机指针赋值
        temp = sentinel->next;
        while (temp != nullptr)
        {
            if (umap.count(h1->random))
            {
                temp->random = umap.at(h1->random);
            }
            else
            {
                temp->random = nullptr;
            }
            temp = temp->next;
            h1 = h1->next;
        }
        return sentinel->next;
    }

    // // 可以参考下官方做法，也是写的很简洁的，递归法
    // class Solution
    // {
    // public:
    //     unordered_map<Node *, Node *> cachedNode;

    //     Node *copyRandomList(Node *head)
    //     {
    //         if (head == nullptr)
    //         {
    //             return nullptr;
    //         }
    //         if (!cachedNode.count(head))
    //         {
    //             Node *headNew = new Node(head->val);
    //             cachedNode[head] = headNew;
    //             headNew->next = copyRandomList(head->next);
    //             headNew->random = copyRandomList(head->random);
    //         }
    //         return cachedNode[head];
    //     }
    // };
};

int main()
{
    return 0;
}