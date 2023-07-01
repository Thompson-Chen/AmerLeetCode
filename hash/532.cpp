// 哈希表的查找、插入及删除
// 数组中的 k-diff 数对
// https://leetcode.cn/problems/k-diff-pairs-in-an-array/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        // 90.32/43.25
        unordered_set<int> num_set;
        unordered_set<int> repeat_nums;
        int cnt = 0;

        for (auto &num : nums)
        {
            if (num_set.count(num))
            {
                repeat_nums.emplace(num);
            }
            else
            {
                num_set.emplace(num);
            }
        }
        if (k == 0)
            return repeat_nums.size();
        for (auto &num : num_set)
        {
            if (num_set.count(num - k))
            {
                cnt++;
            }
        }

        return cnt;

        // // 官方代码，整体思想是一样的，但更简洁
        // unordered_set<int> visited;
        // unordered_set<int> res;
        // for (int num : nums)
        // {
        //     if (visited.count(num - k))
        //     {
        //         res.emplace(num - k);
        //     }
        //     if (visited.count(num + k))
        //     {
        //         res.emplace(num);
        //     }
        //     visited.emplace(num);
        // }
        // return res.size();
    }
};

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    Solution s = Solution();
    s.findPairs(nums, k);
    return 0;
}