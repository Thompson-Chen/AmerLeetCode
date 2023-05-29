// 链表的旋转与反转
// 反转链表 II
// 这道题字节跳动2022年12月面试出了
// https://leetcode.cn/problems/reverse-linked-list-ii/
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

class Solution
{
private:
    void reverseLinkedList(ListNode *head)
    {
        // 也可以使用递归来翻转一个链表（虽然自己不太会 emo）
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // // 法1：穿针引线(100%/8.1%)
        // // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        // ListNode *dummyNode = new ListNode(-1);
        // dummyNode->next = head;

        // ListNode *pre = dummyNode;
        // // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        // // 建议写在 for 循环里，语义清晰
        // for (int i = 0; i < left - 1; i++) {
        //     pre = pre->next;
        // }

        // // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        // ListNode *rightNode = pre;
        // for (int i = 0; i < right - left + 1; i++) {
        //     rightNode = rightNode->next;
        // }

        // // 第 3 步：切断出一个子链表（截取链表）
        // ListNode *leftNode = pre->next;
        // ListNode *curr = rightNode->next;

        // // 注意：切断链接
        // pre->next = nullptr;
        // rightNode->next = nullptr;

        // // 第 4 步：同第 206 题，反转链表的子区间
        // reverseLinkedList(leftNode);

        // // 第 5 步：接回到原来的链表中
        // pre->next = rightNode;
        // leftNode->next = curr;
        // return dummyNode->next;

        // 法2：一次遍历（头插法，设置三个节点）(100%/82.29%)
        if (head->next == nullptr or left == right)
            return head;
        ListNode *sentinel = new ListNode(0, head);
        ListNode *prev = sentinel;
        // 移动到待反转链表的前驱结点
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next; // curr是始终不变的，指向待反转链表的头结点
        ListNode *next = curr->next; // next节点是当前要操作的，即放到待反转链表头结点位置的节点

        for (int i = 0; i < right - left; i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        return sentinel->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode * n5 = new ListNode(5);
    ListNode * n4 = new ListNode(4,n5);
    ListNode * n3 = new ListNode(3,n4);
    ListNode * n2 = new ListNode(2,n3);
    ListNode * n1 = new ListNode(1,n2);
    Solution *s = new Solution();
    s->reverseBetween(n1,2,4);
    return 0;
}
