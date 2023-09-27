// 数字与字符串间转换
// 判断子序列
// https://leetcode.cn/problems/is-subsequence/description/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 100/41.3
        int n = s.length();
        int i = 0;
        if(n == 0)
        {
            return true;
        }
        for(auto c: t)
        {
            if(s[i] == c)
            {
                i++;
            }
            if(i == n)
            {
                return true;
            }
        }
        return false;
    }
};