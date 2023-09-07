// 字符的统计
// 字符串中的第一个唯一字符
// https://leetcode.cn/problems/first-unique-character-in-a-string/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        // hash (22.85/37.37)
        // unordered_map<char, int> charCount;
        // for (char c : s)
        // {
        //     if (charCount.find(c) == charCount.end())
        //     {
        //         charCount[c] = 1;
        //     }
        //     else
        //     {
        //         charCount[c]++;
        //     }
        // }

        // for (int i = 0; i < s.length(); i++)
        // {
        //     if(charCount[s[i]] == 1)
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        // 优化：数组 (91.68/89.61)
        int a[26] = {0};
        for(char c:s)
        {
            a[c-'a']++;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(a[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};