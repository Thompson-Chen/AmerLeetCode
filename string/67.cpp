// 二进制求和
// 高精度运算
// https://leetcode.cn/problems/add-binary/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        // 粗暴方法：二进制转十进制转二进制（但是字符串长度最长到10的4次方，该方法显然会爆）
        // 模拟法：直接进行二进制的操作，不进行过渡进制的转换
        // 100/42.36
        string ans;
        // 反转后再操作会更直观
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;

        for (int i = 0; i < n; i++)
        {
            carry += i < a.size() ? (a[i] == '1') : 0;
            carry += i < b.size() ? (b[i] == '1') : 0;
            ans.push_back((carry%2)?'1':'0');
            carry /= 2;
        }

        if(carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};