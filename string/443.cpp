// 数字与字符串间转换
// 压缩字符串
// https://leetcode.cn/problems/string-compression/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        // 个人想法：使用pop_back从后往前遍历字符串（感觉比erase删除后所有元素前移效率更高），用栈来存元素，最后再把元素弹出栈，依次存到原数组中
        // 36.59%/5%
        char start = chars[chars.size() - 1];
        int cnt = 0;
        stack<char> stk;
        while (!chars.empty())
        {
            if (start == chars[chars.size() - 1])
            {
                cnt++;
                chars.pop_back();
            }
            else
            {
                if (cnt > 1)
                {
                    string s = to_string(cnt);
                    for (int i = s.length() - 1; i >= 0; i--)
                    {
                        stk.emplace(s[i]);
                    }
                }

                stk.emplace(start);
                start = chars[chars.size() - 1];
                cnt = 0;
            }
        }
        if (cnt > 1)
        {
            string s = to_string(cnt);
            for (int i = s.length() - 1; i >= 0; i--)
            {
                stk.emplace(s[i]);
            }
        }
        stk.emplace(start);

        while (!stk.empty())
        {
            chars.push_back(stk.top());
            stk.pop();
        }
        return chars.size();
    }
};

int main(int argc, char const *argv[])
{
    // vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars = {'a'};
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    Solution s = Solution();
    cout << s.compress(chars);
    return 0;
}
