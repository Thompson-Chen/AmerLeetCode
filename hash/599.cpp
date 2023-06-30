// 哈希表与索引
// 两个列表的最小索引总和
// https://leetcode.cn/problems/minimum-index-sum-of-two-lists/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        // 25.3/47.6
        unordered_map<string, int> umap;
        vector<string> res;
        int min = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
        {
            umap.emplace(list1[i], i);
        }

        for (int i = 0; i < list2.size(); i++)
        {
            if (umap.find(list2[i]) != umap.end())
            {
                int idx_sum = i + umap[list2[i]];
                if (min == idx_sum)
                {
                    res.push_back(list2[i]);
                }
                else if (min > idx_sum)
                {
                    res.resize(0);
                    res.push_back(list2[i]);
                    min = idx_sum;
                }
            }
        }
        return res;
    }
};
