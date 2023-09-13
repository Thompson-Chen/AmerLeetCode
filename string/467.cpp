// 字符的统计
// 环绕字符串中唯一的子字符串
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        // 利用集合(无法解决子串之间包含的问题，例如aabb，其中ab包含了a和b)
        // set<string> mySet;
        // int start = 0, len = 1;
        // int i = 0;
        // while (start + len < s.length() and i < s.length() - 1)
        // {
        //     int diff = s[i + 1] - s[i];
        //     if (diff == 1 or diff == -25)
        //     {
        //         len++;
        //     }
        //     else
        //     {
        //         string subs = s.substr(start, len);
        //         int found = s.find(subs);
        //         if (found == string::npos or found == start)
        //         {
        //             mySet.insert(subs);
        //         }
        //         start = i + 1;
        //         len = 1;
        //     }
        //     i++;
        // }
        // string subs = s.substr(start, len);
        // int found = s.find(subs);
        // if (found == string::npos or found == start)
        // {
        //     mySet.insert(subs);
        // }
        // int ans = 0;
        // for (string el : mySet)
        // {
        //     int len = el.length();
        //     ans += (1 + len) * len / 2;
        // }

        // return ans;

        // 看的官方题解：动态规划 (14.7/83.61)
        // 关键思路：题目要求不同的子串个数，那么对于两个以同一个字符结尾的子串，长的那个子串必然包含短的那个。
        // 定义 dp[α]\textit{dp}[\alpha]dp[α] 表示 ppp 中以字符 α\alphaα 结尾且在 sss 中的子串的最长长度，知道了最长长度，也就知道了不同的子串的个数。
        vector<int> dp(26);
        int len = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if (i && ((s[i] - s[i - 1] + 26) % 26 == 1)) // 字符之差为1或-25
            {
                ++len;
            }
            else
            {
                len = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }
        return accumulate(dp.begin(), dp.end(),0); // 返回元素和
    }
};

int main(int argc, char const *argv[])
{
    string s = "zaba";
    Solution solution = Solution();
    cout << solution.findSubstringInWraproundString(s);
    return 0;
}
