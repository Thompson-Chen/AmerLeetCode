// 表达式求值
// 逆波兰表达式求值
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isNumber(const string &str)
    {   
        if(str.length() > 1 and str[0] == '-')
        {
            return true;
        }
        for (char ch : str)
        {
            if (!isdigit(ch))
            {
                return false; // 如果有一个字符不是数字字符，则返回false
            }
        }
        return true; // 所有字符都是数字字符，返回true
    }
    int evalRPN(vector<string> &tokens)
    {
        int sum = 0;
        stack<int> stk;
        if(tokens.size() == 1)
        {
            return stoi(tokens[0]);
        }
        for (int i = 0; i < tokens.size(); i++)
        {
            if (isNumber(tokens[i]))
            {
                // 数字
                stk.emplace(stoi(tokens[i]));
            }
            else
            {   
                int x=0,y=0;
                // 二元操作符
                if (!stk.empty())
                {
                    y = stk.top();
                    stk.pop();
                }
                if (!stk.empty())
                {
                    x = stk.top();
                    stk.pop();
                }

                if (tokens[i] == "+")
                {
                    sum = x + y;
                }
                else if (tokens[i] == "-")
                {
                    sum = x - y;
                }
                else if (tokens[i] == "*")
                {
                    sum = x * y;
                }
                else
                {   
                    if(y==0)
                    {
                        y++;
                    }
                    sum = x / y;
                }
                stk.emplace(sum);
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> test = {"3","-4","+"};
    Solution s = Solution();
    s.evalRPN(test);
    return 0;
}
