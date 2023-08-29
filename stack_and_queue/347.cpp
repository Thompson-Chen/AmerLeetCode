// 求前 K 个高频元素
// 前 K 个高频元素
// https://leetcode.cn/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 49.81/57.75
        // 先遍历一遍，把结果统计出来，开销为n
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if(umap.count(nums[i]))
            {
                umap[nums[i]]++;
            }
            else
            {
                umap[nums[i]] = 1;
            }
        }
        
        // 然后利用最小堆这一数据结构，返回前K个元素
        priority_queue<pair<int, int>> q;
        for (const auto& kvp : umap)
        {
            q.emplace(kvp.second, kvp.first);
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};