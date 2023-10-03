// 最长特殊序列 I
// 判断子序列
// https://leetcode.cn/problems/longest-uncommon-subsequence-i/description/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        // 脑筋急转弯
        if (a == b)
        {
            return -1;
        }
        else
        {
            int l = a.length() > b.length() ? a.length() : b.length();
            return l;
        }
    }
};