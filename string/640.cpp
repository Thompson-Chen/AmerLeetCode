// 数字与字符串间转换
// 求解方程
// https://leetcode.cn/problems/solve-the-equation/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string solveEquation(string equation)
    {
        // 25.73/5.34
        // 个人想法：（关键是字符串的识别）
        // 1. 先提取两边的式子，然后分别看x的系数a1，a2和常数系数b1，b2
        // 2. 令ans1 = a1 - a2; ans2 = b2 - b1;
        // 3.
        //      若ans1 = 0 and ans2 != 0 -> 则说明 No solution
        //      若ans1 = 0 and ans2 = 0 -> 则说明 Infinite solutions
        //      若ans1 != 0-> 则说明有一个解

        // 找到等号的位置
        size_t equalSignPos = equation.find('=');

        string left = equation.substr(0, equalSignPos);
        string right = equation.substr(equalSignPos + 1);
        int *leftCoefficients = getCoefficients(left);
        int *rightCoefficients = getCoefficients(right);

        int ans1 = leftCoefficients[0] - rightCoefficients[0];
        int ans2 = rightCoefficients[1] - leftCoefficients[1];
        if (ans1 == 0 and ans2 != 0)
        {
            return "No solution";
        }
        else if (ans1 == 0 and ans2 == 0)
        {
            return "Infinite solutions";
        }
        else
        {
            return "x=" + to_string(ans2 / ans1);
        }
    }

    int *getCoefficients(string s)
    {
        // 难的部分是这里
        // 先根据加减号拆分
        vector<string> terms;
        int *coefficients = new int[2];
        coefficients[0] = 0;
        coefficients[1] = 0;

        size_t pos = 0;
        while (pos < s.length())
        {
            // 找到下一个加号或减号的位置
            size_t nextPos = s.find_first_of("+-", pos + 1);
            if (nextPos == string::npos)
            {
                nextPos = s.length();
            }

            // 提取当前部分
            string term = s.substr(pos, nextPos - pos);

            // 将term添加到向量中
            terms.push_back(term);

            pos = nextPos;
        }

        for (auto &term : terms)
        {
            int i = 0;
            int sign = 1;
            int temp = 0;
            bool has_num = false;
            int n = term.length();
            while (i < n)
            {
                if (term[i] == '-')
                {
                    sign = -1;
                }
                else if (isdigit(term[i]))
                {
                    temp = 10 * temp + term[i] - '0';
                    has_num = true;
                }
                i++;
            }
            if (term[n - 1] == 'x')
            {
                coefficients[0] += temp == 0 and !has_num? sign : sign * temp;
            }
            else
            {
                coefficients[1] += sign * temp;
            }
        }
        return coefficients;
    }
};

int main(int argc, char const *argv[])
{
    string equation = "3x=33+22+11";
    Solution s = Solution();
    cout << s.solveEquation(equation);
    return 0;
}
