// 哈希表与统计
// 两个数组的交集 II
// https://leetcode.cn/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // 43.24/11.23
        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;
        vector<int> res;

        for (auto &num : nums1)
        {
            if (umap1.count(num))
            {
                umap1[num] += 1;
            }
            else
            {
                umap1[num] = 1;
            }
        }

        for (auto &num : nums2)
        {
            if (umap2.count(num))
            {
                umap2[num] += 1;
            }
            else
            {
                umap2[num] = 1;
            }

            if (umap1.count(num) && umap2.count(num))
            {
                if (umap2[num] <= umap1[num])
                {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};