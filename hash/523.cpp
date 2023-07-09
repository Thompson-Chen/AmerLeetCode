// 哈希表与前缀和
// 连续的子数组和
// https://leetcode.cn/problems/continuous-subarray-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // 方法1：枚举 ( 超时-98个测试用例通过93个)
        // 计算前缀和
        // if (nums.size() <= 1)
        //     return false;

        // for (int i = 1; i < nums.size(); i++)
        // {
        //     nums[i] += nums[i - 1];
        // }
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if (nums[i] % k == 0)
        //     {
        //         return true;
        //     }
        // }
        // for (int j = nums.size() - 1; j >= 2; j--)
        // {
        //     for (int i = 0; i < j - 1; i++)
        //     {
        //         if((nums[j] - nums[i])%k == 0)
        //         {
        //             return true;
        //         }
        //     }
        // }

        // return false;

        // 方法2：在方法1的基础上基于哈希表进行优化(5.43/53.48)
        // 思路：哈希表不是存储前缀和，而是存储每个前缀和除以k之后的余数，当当前元素之前在哈希表中存在相同的余数时，并且value（即下标）差大于2时，返回true
        // if (nums.size() <= 1)
        //     return false;

        // for (int i = 1; i < nums.size(); i++)
        // {
        //     nums[i] += nums[i - 1];
        // }
        // unordered_map<int, int> umap;

        // umap[0] = -1;
        // int reminder = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     reminder = nums[i] % k;
        //     if (umap.count(reminder))
        //     {
        //         if (i - umap[reminder] >= 2)
        //             return true;
        //     }
        //     else
        //     {
        //         umap[reminder] = i;
        //     }
        // }
        // return false;

        // 方法3：针对方法2的优化，不需要一次遍历的开销来计算前缀和
        int m = nums.size();
        if (m < 2)
        {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++)
        {
            remainder = (remainder + nums[i]) % k; // 关键掌握这一步，这里实际上就涉及到了前缀和的思想
            if (mp.count(remainder))
            {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2)
                {
                    return true;
                }
            }
            else
            {
                mp[remainder] = i;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {23, 2, 4, 6, 6};
    Solution s = Solution();
    s.checkSubarraySum(nums, 7);
    return 0;
}