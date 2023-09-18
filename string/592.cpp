// 数字与字符串间转换
// 分数加减运算
// https://leetcode.cn/problems/fraction-addition-and-subtraction/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string fractionAddition(string expression)
    {
        // 100/5.15
        // 个人思路：（关键是字符串的识别）本质上是模拟法
        // 1. 先找到最小公倍数作为分母；2.每个分子乘以各基数，得到分子；3. 分子分母约分——查找最大公倍数
        long long x = 0, y = 1;
        int index = 0, n = expression.size();
        while (index < n)
        {
            // 读取分子
            long long x1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+')
            {
                sign = expression[index] == '-' ? -1 : 1;
                index++;
            }
            while (index < n && isdigit(expression[index]))
            {
                x1 = x1 * 10 + expression[index] - '0';
                index++;
            }
            x1 = sign * x1;
            index++;

            // 读取分母
            long long y1 = 0;
            while (index < n && isdigit(expression[index]))
            {
                y1 = y1 * 10 + expression[index] - '0';
                index++;
            }

            x = x * y1 + x1 * y;
            y *= y1;
        }
        if (x == 0)
        {
            return "0/1";
        }
        long long g = gcd(abs(x), y); // 获取最大公约数
        return to_string(x / g) + "/" + to_string(y / g);
    }
};