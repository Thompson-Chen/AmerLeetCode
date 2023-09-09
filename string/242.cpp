// 字符的统计
// 反转字符串中的单词
// https://leetcode.cn/problems/reverse-words-in-a-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 数组 (57.82/57.78)
        if (s.length() != t.length())
        {
            return false;
        }
        int arr[26] = {0};
        for (char c : s)
        {
            arr[c - 'a']++;
        }
        int temp = 0;
        for (char c : t)
        {
            temp = c - 'a';
            if (arr[temp] > 0)
            {
                arr[temp]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};