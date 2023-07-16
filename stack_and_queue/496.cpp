// 单调栈
// 下一个更大元素
// https://leetcode.cn/problems/next-greater-element-i/
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// 这道题我感觉不是很简答……
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // 暴力法——枚举遍历
        // int m = nums1.size();
        // int n = nums2.size();
        // vector<int> res(m);
        // for (int i = 0; i < m; ++i)
        // {
        //     int j = 0;
        //     while (j < n && nums2[j] != nums1[i])
        //     {
        //         ++j;
        //     }
        //     int k = j + 1;
        //     while (k < n && nums2[k] < nums2[j])
        //     {
        //         ++k;
        //     }
        //     res[i] = k < n ? nums2[k] : -1;
        // }
        // return res;
        // 单调栈 + 哈希表
        /**
         * 两个子问题：
         * 1. 如何更高效地计算nums2中每个元素右边的第一个更大的值
         * 2. 如何存储第1个子问题的结果
         */
        stack<int> stk; // 单调栈，用于维护当前位置右边的更大的元素列表，从栈底到栈顶的元素是单调递减的。
        unordered_map<int,int> umap; // 因为题目规定了nums2是没有重复元素的，所以我们可以使用哈希表来解决第2个子问题，将元素值与其右边第一个更大的元素值的对应关系存入哈希表。
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int num = nums2[i];
            while(!stk.empty() && num >= stk.top())
            {
                stk.pop();
            }
            umap[num] = stk.empty()?-1:stk.top();
            stk.push(num);
        }
        vector<int> res;
        for(auto &num: nums1)
        {
            res.push_back(umap[num]);
        }
        return res;
    }
};