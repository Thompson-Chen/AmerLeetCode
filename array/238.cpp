// 前缀和数组
// 除自身以外数组的乘积
// https://leetcode.cn/problems/product-of-array-except-self/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 要求：不能用除法，并且时间复杂度要求O(n)
        // 想法：创建两个数组，一个用来存左边开始算的乘积，一个用来存右边开始算的乘积
        int n = nums.size();
        vector<int> left_multiply(n, 1);
        vector<int> right_multiple(n, 1);

        for (int i = 1; i < n; i++)
        {
            left_multiply[i] = left_multiply[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right_multiple[i] = right_multiple[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = left_multiply[i] * right_multiple[i];
        }
        return nums;
    }
};