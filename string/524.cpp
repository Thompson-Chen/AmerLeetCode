// 通过删除字母匹配到字典里最长单词
// 判断子序列
// https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 双指针(55.34/11.10)
        // string word = "";
        // for(string str:dictionary)
        // {
        //     if(str.length() < word.length())
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         // 需要先判断是否是子序列
        //         if(isSubsequence(s,str) and (str.length() > word.length() or (str.length()==word.length() and str<word)))
        //         {
        //             word = str;
        //         }
        //     }
        // }
        // return word;
    }
    
    bool isSubsequence(string s, string w)
    {
        // s为长字符串，w为短字符串
        int i = 0, j = 0;
        while(i < s.length() && j < w.length())
        {
            if(s[i] == w[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if( j == w.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};