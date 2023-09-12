// 字符的统计
// 计数二进制子串
// https://leetcode.cn/problems/count-binary-substrings/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        // 25.38/27.01
        // 计数统计分组
        vector<int> res;
        int ptr = 0, n = s.size();
        while(ptr < n)
        {
            char c = s[ptr];
            int count = 0;
            while(ptr < n and s[ptr] == c)
            {
                ++ptr;
                ++count;
            }
            res.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < res.size(); i++)
        {
            ans = min(res[i-1],res[i]);
        }
        return ans;
        
    }
};