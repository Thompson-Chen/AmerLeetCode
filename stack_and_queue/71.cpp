// 用栈访问最后若干元素
// 简化路径
// https://leetcode.cn/problems/simplify-path/
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
    string simplifyPath(string path)
    {
        stack<string> stk; // 存储路径
        string file = "";
        for (char c : path)
        {
            if (c == '/')
            {
                if (file == ".")
                {
                }
                else if (file == "..")
                {
                    if (!stk.empty())
                    {
                        stk.pop();
                    }
                }
                else if (file != "")
                {
                    stk.push(file);
                }
                file = "";
            }
            else
            {
                file.push_back(c);
            }
        }
        if (file == ".")
        {
        }
        else if (file == "..")
        {
            if (!stk.empty())
            {
                stk.pop();
            }
        }
        else if (file != "")
        {
            stk.push(file);
        }
        file = "";
        string filepath = stk.empty() ? "/" : "";
        while (!stk.empty())
        {
            filepath = "/" + stk.top() + filepath;
            stk.pop();
        }
        return filepath;
    }
};

int main(int argc, char const *argv[])
{
    string path = "/a//b////c/d//././/..";
    Solution solution = Solution();
    cout << solution.simplifyPath(path);
    return 0;
}
