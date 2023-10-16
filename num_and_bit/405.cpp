// 数字转换为十六进制数
// 进制转换
// https://leetcode.cn/problems/convert-a-number-to-hexadecimal/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        // 一个16进制占4位 用0x开头表示16进制符号然后和num的后四位进行与运算即可
        if (num == 0) return "0";
        string map = "0123456789abcdef", res = "";
        while (num && res.size() < 8) {
            res = map[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }

};