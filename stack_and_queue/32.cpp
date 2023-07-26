// 栈与括号匹配
// 最长有效括号
// https://leetcode.cn/problems/longest-valid-parentheses/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // （个人以为最好的方法）计数器，不需要额外的栈空间
        // 双向遍历：从左往右——left记录左括号的个数，right记录右括号的个数，当left和right相等时，则计算当前有效字符串的长度，当right大于left时则计数器同时变为0
        // 从右往左——反过来即可
        int left = 0, right = 0;
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if(left == right)
            {
                maxlen = max(maxlen, right*2);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }

        left = right = 0;
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if(left == right)
            {
                maxlen = max(maxlen, left*2);
            }
            else if( left > right)
            {
                left = right = 0;
            }
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    string s = "()(()";
    Solution solution = Solution();
    solution.longestValidParentheses(s);
    return 0;
}
