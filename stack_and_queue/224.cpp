// 表达式求值
// 基本计算器
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        // 官方题解，因为只有加减号，所以把所有括号展开后其实数字是不会变的，只是运算符可能会发生翻转
        stack<char> stk; // 存储正负符号
        int res = 0, sign = 1, i = 0, n = s.length();
        stk.emplace(sign);

        while (i < n)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '+')
            {
                sign = stk.top();
                i++;
            }
            else if (s[i] == '-')
            {
                sign = -stk.top();
                i++;
            }
            else if (s[i] == '(')
            {
                stk.emplace(sign);
                i++;
            }
            else if (s[i] == ')')
            {
                stk.pop();
                i++;
            }
            else
            {   
                long num = 0;
                // 数字
                while (i < n and s[i] >= '0' and s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += sign * num;
            }
        }
        return res;
    }
};