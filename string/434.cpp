// 单词
// 字符串中的单词数
// https://leetcode.cn/problems/number-of-segments-in-a-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        // 100%/25.48%
        if(s.empty())
        {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ' and (i == s.length() - 1 or s[i+1] == ' '))
            {
                cnt++;
            }
        }
        return cnt;
    }
};