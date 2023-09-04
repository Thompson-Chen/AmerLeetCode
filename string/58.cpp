// 单词
// 最后一个单词的长度
// https://leetcode.cn/problems/number-of-segments-in-a-string/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        // 倒序遍历
        // 44.76/23.58
        int i = s.length() - 1;
        while(i >= 0 and s[i] == ' ')
        {
            i--;
        }
        int cnt = 0;
        while(i >= 0 and s[i] != ' ')
        {
            cnt++;
            i--;
        }
        return cnt;
    }
};