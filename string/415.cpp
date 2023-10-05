// 字符串相加
// 高精度运算
// https://leetcode.cn/problems/add-strings/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        // 模拟法：先反转，然后逐位相加(70.92/28.09)
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0;
        int max_len = max(num1.length(), num2.length());
        int t1,t2;
        int sum = 0;
        string ans = "";
        for (int i = 0; i < max_len; i++)
        {
            t1 = (i< num1.length()) ? num1[i]-'0':0;
            t2 = (i< num2.length()) ? num2[i]-'0':0;
            sum = t1 + t2 + carry;
            carry = sum/10;
            ans += to_string(sum%10);
        }

        if(carry != 0)
        {
            ans += to_string(carry%10);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};