// 数字与字符串间转换
// 整数转罗马数字
// https://leetcode.cn/problems/integer-to-roman/description/
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
    string intToRoman(int num)
    {
        // 感觉思路蛮清晰的，依次往下除就好了
        // 5.32/9.62
        unordered_map<int, string> umap;
        umap[1000] = "M";
        umap[500] = "D";
        umap[100] = "C";
        umap[50] = "L";
        umap[10] = "X";
        umap[5] = "V";
        umap[1] = "I";
        umap[4] = "IV";
        umap[9] = "IX";
        umap[40] = "XL";
        umap[90] = "XC";
        umap[400] = "CD";
        umap[900] = "CM";

        string res = "";
        int divisor = 0;
        int temp = 0;
        while (num > 0)
        {
            divisor = getSecondMax(num);
            temp = num / divisor;
            for (int i = 0; i < temp; i++)
            {
                res += umap[divisor];
            }
            num %= divisor;
        }
        return res;
    }

    int getSecondMax(int num)
    {
        if (num >= 1000)
        {
            return 1000;
        }
        else if (num >= 900)
        {
            return 900;
        }
        else if (num >= 500)
        {
            return 500;
        }
        else if (num >= 400)
        {
            return 400;
        }
        else if (num >= 100)
        {
            return 100;
        }
        else if (num >= 90)
        {
            return 90;
        }
        else if (num >= 50)
        {
            return 50;
        }
        else if (num >= 40)
        {
            return 40;
        }
        else if (num >= 10)
        {
            return 10;
        }
        else if (num >= 9)
        {
            return 9;
        }
        else if (num >= 5)
        {
            return 5;
        }
        else if (num >= 4)
        {
            return 4;
        }
        else if (num >= 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    cout << solution.intToRoman(1994);
    return 0;
}
