// 数组的改变/移动
// 非递减数列
// https://leetcode.cn/problems/non-decreasing-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 */
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        // 我的想法：遍历，判断是否没有或只有一对降序对，是的话则说明可以，反之不行
        // int n = nums.size();
        // if (n == 1)
        // {
        //     return true;
        // }
        // int count = 0;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (nums[i] > nums[i + 1])
        //     {
        //         if (i < n - 2 && (nums[i] > nums[i + 2]))
        //         {
        //             if (nums[i + 1] <= nums[i + 2])
        //                 nums[i] = nums[i + 1];
        //             else
        //             {
        //                 return false;
        //             }
        //             break;
        //         }
        //         else
        //         {
        //             nums[i + 1] = nums[i];
        //             break;
        //         }
        //     }
        // }

        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (nums[i] > nums[i + 1])
        //     {
        //         return false;
        //     }
        // }

        // return true;

        // 官方题解
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int x = nums[i];
            int y = nums[i + 1];
            if (x > y)
            {
                // 要么把x变为y要么把y变为x
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end()))
                {
                    // 如果是非递减序列
                    return true;
                }
                else
                {
                    // 不是非递减序列，则尝试把y变为x
                    nums[i] = x;
                    nums[i + 1] = x;
                    if (is_sorted(nums.begin(), nums.end()))
                    {
                        // 如果是非递减序列
                        return true;
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution *s = new Solution();
    vector<int> v = {3, 4, 2, 3};
    vector<int> v2 = {5, 7, 1, 8};
    cout << (bool)(s->checkPossibility(v)) << endl;
    cout << (bool)(s->checkPossibility(v2));
    return 0;
}