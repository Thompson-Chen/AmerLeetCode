// 表达式求值
// 基本计算器II
// https://leetcode.cn/problems/basic-calculator-ii/
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
    void calSum(char opt, stack<int> &stk)
    {
        double num1 = 0.1;
        int num2 = 0, sum = 0;
        if (!stk.empty())
        {
            num2 = stk.top();
            stk.pop();
        }
        if (!stk.empty())
        {
            num1 = stk.top();
            stk.pop();
        }

        switch (opt)
        {
        case '+':
            sum = (int)(num1 + num2);
            break;
        case '-':
            sum = (int)(num1 - num2);
            break;
        case '*':
            sum = (int)(num1 * num2);
            break;
        case '/':
            sum = (int)(num1 / num2);
            break;
        default:
            break;
        }
        stk.emplace(sum);
    }
    int calculate(string s)
    {
        int i = 0;
        int sum = 0;
        int num = 0;
        int n = s.length();
        stack<char> operator_stk; // 操作符栈
        stack<int> operand_stk;   // 操作数栈

        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0'); // 注意，这里要加括号，否则可能会整型溢出
            }
            else
            {
                // 把操作数加入栈中
                operand_stk.emplace(num);
                num = 0;
                // 如果栈为空，直接入栈
                // 如果栈不为空，要比较优先级（乘除优先级大于加减优先级）：
                // 单调栈思想——
                // 如果入栈元素优先级大于栈顶元素，则直接入栈；
                // 如果入栈元素优先级小于或等于栈顶元素，则栈顶元素弹出栈计算后入栈元素再入栈
                if (!operator_stk.empty())
                {
                    if ((s[i] == '*' or s[i] == '/') and (operator_stk.top() == '+' or operator_stk.top() == '-'))
                    {
                        // 入栈元素优先级大于栈顶元素
                        operator_stk.emplace(s[i]);
                    }
                    else
                    {
                        // 入栈元素优先级小于或等于栈顶元素
                        // 注意这里要用while判断，使得始终栈为单调栈，不能仅仅在第一次弹出栈顶元素就无了
                        while (!operator_stk.empty() and !((s[i] == '*' or s[i] == '/') and (operator_stk.top() == '+' or operator_stk.top() == '-')))
                        {
                            char opt = operator_stk.top();
                            operator_stk.pop();
                            calSum(opt, operand_stk);
                        }
                        operator_stk.emplace(s[i]);
                    }
                }
                else
                {
                    operator_stk.emplace(s[i]);
                }
            }
            i++;
        }

        operand_stk.emplace(num);
        num = 0;

        while (!operator_stk.empty())
        {
            char opt = operator_stk.top();
            operator_stk.pop();
            calSum(opt, operand_stk);
            if (operand_stk.top() < 0)
            {
            }
        }
        return operand_stk.top();
    }
};

int main(int argc, char const *argv[])
{
    string test = "2147483647";
    Solution solution = Solution();
    cout << solution.calculate(test);
    return 0;
}
