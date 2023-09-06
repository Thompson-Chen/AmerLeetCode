// 字符串的反转
// 反转字符串中的单词 III
// https://leetcode.cn/problems/reverse-words-in-a-string-iii/solutions/393471/fan-zhuan-zi-fu-chuan-zhong-de-dan-ci-iii-by-lee-2/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // 简单的方法，栈
        // 10.97/17.92
        stack<char> stk;
        string new_s = "";
        for (auto &c : s)
        {
            if (c == ' ')
            {
                while (!stk.empty())
                {
                    new_s.push_back(stk.top());
                    stk.pop();
                }
                new_s.push_back(' ');
            }
            else
            {
                stk.emplace(c);
            }
        }
        while (!stk.empty())
        {
            new_s.push_back(stk.top());
            stk.pop();
        }
        return new_s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "God Ding";
    Solution solution = Solution();
    solution.reverseWords(s);
    return 0;
}
