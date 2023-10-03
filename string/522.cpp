// 最长特殊序列 II
// 判断子序列
// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/description/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        // 特殊序列只能是本身
        // 枚举 (67.58/11.24)
        int max_len = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string s_1 = strs[i];
            bool check = true;
            for (int j = 0; j < strs.size(); j++)
            {
                string s_2 = strs[j];
                if (i != j and isSubStr(s_1, s_2))
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                int temp = s_1.length();
                max_len = temp > max_len ? temp : max_len;
            }
        }
        return max_len == 0 ? -1 : max_len;
    }

    bool isSubStr(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        else if (s1 == s2)
        {
            return true;
        }
        // 判断s1是否为s2的子序列
        int p1 = 0;
        int p2 = 0;
        while (p1 < s1.length() and p2 < s2.length())
        {
            if (s1[p1] == s2[p2])
            {
                p1++;
            }
            p2++;
        }

        if (p1 == s1.length())
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"aabbcc", "aabbcc","c","e","aabbcd"};
    Solution solution = Solution();
    cout << solution.findLUSlength(strs);
    return 0;
}
