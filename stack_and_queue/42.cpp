// 单调栈
// 接雨水
// https://leetcode.cn/problems/trapping-rain-water/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 独立完成 26.59%/5.04%
        stack<int> stk; // 单调递减栈，如果当前待加入的块高高于栈顶元素，就更新结果
        int leftmost = 0;
        int sum = 0;
        int cnt = 0;
        int temp = 0;
        for (auto &h : height)
        {
            temp = h > leftmost ? leftmost : h;
            while (!stk.empty() && h > stk.top())
            {
                sum += temp - stk.top();
                stk.pop();
                cnt++;
                // stk.push(temp);
            }
            leftmost = h > leftmost ? h : leftmost;
            // 下面条件判断和while循环的作用是用来抹平已经计算的水滴数
            if (stk.empty())
            {
                cnt = 0;
            }
            else
            {
                while (cnt > 0)
                {
                    cnt--;
                    stk.push(temp);
                }
            }

            stk.push(h);
        }

        return sum;
    }
};
