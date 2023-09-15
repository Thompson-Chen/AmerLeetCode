// 数字与字符串间转换
// 最优除法
// https://leetcode.cn/problems/optimal-division/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        // 要使计算后的表达式为最大值，实际上是要使分母足够小,分子足够大，
        // 那么实际上对于ans = num0 ÷ num1 ÷ num2 ÷ ... ÷ numi，分子最大为num0，分母最小为num1 ÷ num2 ÷ ... ÷ numi
        int n = nums.size();
        if (n == 1)
        {
            return to_string(nums[0]);
        }
        if (n == 2)
        {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++)
        {
            res.append("/" + to_string(nums[i]));
        }
        res.append(")");
        return res;
    }
};