// 哈希表的查找、插入及删除
// 最长连续子序列
// https://leetcode.cn/problems/longest-consecutive-sequence/description/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 or nums.size() == 1)
        {
            return nums.size();
        }
        // // 暴力法（92.41%/91.2%）
        // sort(nums.begin(), nums.end());
        // int len = 1;
        // int max = INT_MIN;
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     if (nums[i] - nums[i - 1] == 1)
        //     {
        //         len++;
        //     }
        //     else if (nums[i] - nums[i - 1] == 0)
        //     {
        //     }
        //     else
        //     {
        //         max = len > max ? len : max;
        //         len = 1;
        //     }
        // }
        // // 不要漏了该情况：整个数组都是一个连续子序列
        // max = len > max ? len : max;
        // return max;

        // 使用set
        unordered_set<int> nums_set;
        for (auto &num : nums)
        {
            nums_set.emplace(num);
        }
        int max = 1;
        for (auto &num : nums_set)
        {
            // 跳过条件：当该数字是连续子序列的非起始点或该数字根本不在连续子序列中时，都不进行计数
            if (nums_set.count(num - 1))
            {
                continue;
            }
            else if(nums_set.count(num+1))
            {
                // 是连续子序列的起点
                int temp = num+1;
                int len = 2;
                while(nums_set.count(++temp))
                {
                    len++;
                }
                max = len > max ? len:max;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> test = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution s = Solution();
    cout << s.longestConsecutive(test);
    return 0;
}