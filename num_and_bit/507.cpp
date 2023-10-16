// 七进制数
// 进制转换
// https://leetcode.cn/problems/base-7/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        // 28.88/25.63
        if (num == 0)
            return "0";
        bool is_neg = num > 0 ? false : true;
        num = num < 0 ? -num : num;
        string res;
        while(num > 0)
        {
            res += to_string(num%7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return is_neg ? "-"+res : res;
    }
};