// 字符串相乘
// 高精度运算
// https://leetcode.cn/problems/multiply-strings/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        // 模拟法：先反转，然后一个一个乘
        // 63.24/38.21
        if (num1 == "0" or num2 == "0")
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = 0, m = 0, mul = 0;
        int carry = 0;
        string sum = "";
        vector<string> sums;
        // 阶段1：先进行各个位的乘法
        for (int i = 0; i < num1.length(); ++i)
        {
            n = num1[i] - '0';
            sum = "";
            carry = 0;
            for (int j = 0; j < num2.length(); ++j)
            {
                m = num2[j] - '0';
                mul = n * m + carry;
                carry = mul / 10;
                sum += to_string(mul % 10);
            }
            if (carry)
            {
                sum += to_string(carry % 10);
            }
            sums.push_back(sum);
        }
        string ans = sums[0];
        string temp_str = "";
        int temp_sum = 0;
        // 阶段2：再进行各个子项的加法
        for (int i = 1; i < sums.size(); i++)
        {
            temp_str = sums[i];
            carry = 0;
            temp_sum = 0;
            for (int j = 0; j < temp_str.length(); j++)
            {
                m = (i + j < ans.length()) ? ans[i + j] - '0' : 0;
                n = temp_str[j] - '0';
                temp_sum = m + n + carry;
                carry = temp_sum / 10;
                if (i + j < ans.length())
                {
                    ans[i + j] = temp_sum % 10 + '0';
                }
                else
                {
                    ans += temp_sum % 10 + '0';
                }
            }
            if (carry)
            {
                ans += carry % 10 + '0';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string num1 = "123", num2 = "456";
    Solution solution = Solution();
    cout << solution.multiply(num1, num2);
    return 0;
}
