// 字符串的反转
// 反转字符串II
// https://leetcode.cn/problems/reverse-string-ii/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        // 居然用到了递归…… (26.63/5.04)
        // reverse(s, 0, k - 1);
        // int reminder = s.length() - 2 * k;
        // if (reminder > 0)
        // {
        //     if (reminder < k)
        //     {
        //         reverse(s, 2 * k, s.length() - 1);
        //     }
        //     else if (reminder >= k and reminder < 2 * k)
        //     {
        //         reverse(s, 2 * k, 3 * k - 1);
        //     }
        //     else
        //     {
        //         s = s.substr(0,2*k) + reverseStr(s.substr(2*k, s.length()),k);
        //     }
        // }

        // return s;

        // 官方题解就几行，md
        // int n = s.length();
        // for (int i = 0; i < n; i += 2 * k)
        // {
        //     reverse(s.begin() + i, s.begin() + min(i + k, n));
        // }
        // return s;
    }

    void reverse(string &s, int start, int end)
    {
        if (start >= 0 and end >= 0 and start <= end)
        {
            end = end >= s.length() ? s.length() - 1 : end;
            for (; start < end; start++, end--)
            {
                swap(s[start], s[end]);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    string s = "txrlvugsaphqzxllwebukgatzfybprfmmfithphccxfsogsgqsnvckjvnskk";
    cout << s.length() << endl;
    return 0;
}
