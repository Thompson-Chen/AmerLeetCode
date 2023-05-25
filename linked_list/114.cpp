// 链表的遍历
// 二叉树展开为链表
// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<TreeNode *> que; // 默认使用deque作为底层容器
    void flatten(TreeNode *root)
    {
        // 先序遍历
        // 方法1:用队列记录先序遍历的节点，然后依次弹出修改

        // 1. 先序遍历
        pre_order(root);

        // 2. 链表转化
        for (int i = 1; i < que.size(); i++)
        {
            this->que[i-1]->left = nullptr;
            this->que[i-1]->right = this->que[i];
        }
        
    }
    void pre_order(TreeNode *node)
    {
        if (node != nullptr)
        {
            this->que.push_back(node);
            pre_order(node->left);
            pre_order(node->right);
        }
    }
};