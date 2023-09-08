// 字符串的反转
// 反转字符串中的单词
// https://leetcode.cn/problems/reverse-words-in-a-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 数组 (68.91/43.03)
        int arr[26] = {0};
        for(char c:magazine)
        {
            arr[c-'a']++;
        }
        int temp = 0;
        for(char c:ransomNote)
        {
            temp = c-'a';
            if(arr[temp]>0)
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