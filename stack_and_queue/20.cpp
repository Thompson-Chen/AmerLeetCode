// 栈与括号匹配
// 有效的括号
// https://leetcode.cn/problems/valid-parentheses/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '{' or s[i] == '(' or s[i] == '[')
            {
                stk.push(s[i]);
            }
            else
            {
                switch (s[i])
                {
                case ')':
                    if (!stk.empty() and stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (!stk.empty() and stk.top() == '[')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (!stk.empty() and stk.top() == '{')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    break;
                }
            }
        }

        // 最后还要判断左边的括号是否都有被匹配
        return stk.empty();
    }
};