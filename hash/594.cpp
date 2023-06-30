// 哈希表与统计
// 最长和谐子序列
// https://leetcode.cn/problems/longest-harmonious-subsequence/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        // 88.76/31.11
        unordered_map<int, int> umap;
        for (auto &num : nums)
        {
            if (umap.count(num))
            {
                umap[num] += 1;
            }
            else
            {
                umap[num] = 1;
            }
        }
        int max = 0;
        // unordered_map的遍历
        for (auto iter = umap.begin(); iter != umap.end(); ++iter)
        {
            if(umap.count(iter->first+1))
            {
                max = max < iter->second + umap[iter->first+1]? iter->second + umap[iter->first+1]:max;
            }
        }
        // 另一种更简便的方式
        // for (auto [key, val] : umap) {
        //     if (umap.count(key + 1)) {
        //         res = max(res, val + umap[key + 1]);
        //     }
        // }


        return max;
    }
};