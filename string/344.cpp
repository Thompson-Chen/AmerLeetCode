// 字符串的反转
// 反转字符串
// https://leetcode.cn/problems/reverse-string/description/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针法(15.79/5.45)
        // int i = 0, j = s.size()-1;
        // char temp;
        // while(i < j)
        // {
        //     temp = s[i];
        //     s[i] = s[j];
        //     s[j] = temp;
        //     i++;
        //     j--;
        // }

        // 官方的双指针法题解(97.42/12.42)
        int n = s.size();
        for(int left = 0, right = n-1; left < right; ++left, --right)
        {
            swap(s[left], s[right]);
        }

    }
};