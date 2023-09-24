// 数字与字符串间转换
// 罗马数字转整数
// https://leetcode.cn/problems/roman-to-integer/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // 81.50/5.55
        unordered_map<string, int> map;
        map["IV"] = 4;
        map["IX"] = 9;
        map["XL"] = 40;
        map["XC"] = 90;
        map["CD"] = 400;
        map["CM"] = 900;
        if (map.count(s))
        {
            return map[s];
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'I':
                if (i < s.length() - 1 and s[i + 1] == 'V')
                {
                    ans += 4;
                    i++;
                }
                else if (i < s.length() - 1 and s[i + 1] == 'X')
                {
                    ans += 9;
                    i++;
                }
                else
                {
                    ans += 1;
                }
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (i < s.length() - 1 and s[i + 1] == 'L')
                {
                    ans += 40;
                    i++;
                }
                else if (i < s.length() - 1 and s[i + 1] == 'C')
                {
                    ans += 90;
                    i++;
                }
                else
                {
                    ans += 10;
                }
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (i < s.length() - 1 and s[i + 1] == 'D')
                {
                    ans += 400;
                    i++;
                }
                else if (i < s.length() - 1 and s[i + 1] == 'M')
                {
                    ans += 900;
                    i++;
                }
                else
                {
                    ans += 100;
                }
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            default:
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    string s = "MCMXCIV";
    cout<<solution.romanToInt(s);
    return 0;
}
