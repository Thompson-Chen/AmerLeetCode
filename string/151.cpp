// 字符串的反转
// 反转字符串中的单词
// https://leetcode.cn/problems/reverse-words-in-a-string/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // 简单方法，队列+栈
        // 7.65/24.79
        // stack<string> stk;
        // queue<char> q;
        // for (auto &c : s)
        // {
        //     if (c != ' ')
        //     {
        //         q.push(c);
        //     }
        //     else
        //     {
        //         string temp = "";
        //         while (!q.empty())
        //         {
        //             temp.push_back(q.front());
        //             q.pop();
        //         }
        //         if (temp != "")
        //         {
        //             stk.emplace(temp);
        //         }
        //     }
        // }
        // string temp = "";
        // while (!q.empty())
        // {
        //     temp.push_back(q.front());
        //     q.pop();
        // }
        // if (temp != "")
        // {
        //     stk.emplace(temp);
        // }
        // string res = "";
        // while (!stk.empty())
        // {
        //     res += stk.top();
        //     stk.pop();
        //     if(stk.size() > 0)
        //     {
        //         res += " ";
        //     }
        // }
        // return res;

        // 个人优化：从后往前+栈(性能大幅提升)
        // 77.94/30.90
        stack<char> stk;
        string res = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' and !stk.empty())
            {
                while (!stk.empty())
                {
                    res.push_back(stk.top());
                    stk.pop();
                }
                res += " ";
            }
            else if (s[i] != ' ')
            {
                stk.emplace(s[i]);
            }
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res[res.length() - 1] == ' '? res.substr(0, res.length() - 1):res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "  hello world  ";
    Solution solution = Solution();
    solution.reverseWords(s);
    return 0;
}
