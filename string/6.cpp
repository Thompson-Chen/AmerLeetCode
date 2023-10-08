// N 字形变换
// 字符串变换
// https://leetcode.cn/problems/zigzag-conversion/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 题解大佬的想法：每一行单开一个数组，模拟法即可 (65.86/40.21)
        if (numRows < 2)
        {
            return s;
        }
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s)
        {
            rows[i].push_back(c);
            if(i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }

        string res;
        for(const string &row: rows)
        {
            res += row;
        }
        return res;
    }
};