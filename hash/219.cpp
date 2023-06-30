// 哈希表与索引
// 存在重复元素 II
// https://leetcode.cn/problems/contains-duplicate-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // 75.5/62.42
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i]))
            {
                if (abs(i - umap[nums[i]]) <= k)
                {
                    return true;
                }
                else
                {
                    umap[nums[i]] = i;
                }
            }
            else
            {
                umap[nums[i]] = i;
            }
        }

        return false;
    }
};