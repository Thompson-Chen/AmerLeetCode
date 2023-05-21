// 数组的旋转
// 旋转函数
// https://leetcode.cn/problems/rotate-function/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        // // 个人想法：实际上不用实际旋转数组，直接操作下标即可(思路是对的，但超时了通过了42/58)
        // int n = nums.size();
        // // 系数定义&初始化
        // vector<int> v(n);
        // for (int i = 0; i < n; i++)
        // {
        //     v[i] = i;
        // }

        // int max = INT_MIN;
        // for (int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for (int j = 0; j < n; j++)
        //     {
        //         sum += v[(j + i) % n] * nums[j];
        //     }
        //     max = sum > max ? sum : max;
        // }
        // return max;

        // 找规律……
        // 核心思路是，比较两个相邻的要计算的值，看这两个值的差 F(i)-F(i-1)，总结成一个公式，这样就能从 F(0) 出发，O(1) 地计算出下一个 F 值。
        /*
        nums: [A0,A1,A2,A3]

        F0 = 0*A0 + 1*A1 + 2*A2 + 3*A3

        F1 = 0*A3 + 1*A0 + 2*A1 + 3*A2
            = F0 + A0 + A1 + A2 - 3*A3
            = F0 + sum-A3 - 3*A3
            = F0 + sum - 4*A3

        F2 = 0*A2 + 1*A3 + 2*A0 + 3*A1
            = F1 + A0 + A1 + A3 - 3*A2
            = F1 + sum - 4*A2

        F3 = 0*A1 + 1*A2 + 2*A3 + 3*A0
            = F2 + A2 + A3 + A0 - 3*A1
            = F2 + sum - 4*A1
        */
        // 总结： F(n) = F(n-1) + sum - n*A(sum.size()-n)
        int n = nums.size();
        int numsum = 0;
        int F0 = 0;
        for (int i = 0; i < n; i++)
        {
            F0 += i * nums[i];
            numsum += nums[i];
        }

        int max = F0;
        int F_i = 0;
        int F_prev = F0;
        for (int i = 1; i < n; i++)
        {
            F_i = F_prev + numsum - n * nums[n - i];
            max = F_i > max ? F_i : max;
            F_prev = F_i;
        }
        return max;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {4, 3, 2, 6};
    cout << s->maxRotateFunction(v);
    return 0;
}