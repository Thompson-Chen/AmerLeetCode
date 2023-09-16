// 数字与字符串间转换
// 复数乘法
// https://leetcode.cn/problems/complex-number-multiplication/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
// 26.01/9.25
    string complexNumberMultiply(string num1, string num2)
    {
        // 分开识别实部和虚部

        int *parts1 = getparts(num1);
        int *parts2 = getparts(num2);

        int a, b, c;
        a = parts1[0] * parts2[0];                         // 纯实数
        b = -parts1[1] * parts2[1];                        // 纯虚数
        c = parts1[0] * parts2[1] + parts1[1] * parts2[0]; // 混合
        return to_string(a + b) + "+" + to_string(c) + "i";
    }

    int *getparts(string num)
    {
        // 创建字符串流对象
        istringstream ss(num);

        // 用'+'分割字符串
        string real_part_str, imaginary_part_str;
        getline(ss, real_part_str, '+');
        getline(ss, imaginary_part_str, 'i');

        // 转换为int类型
        int real_part, imaginary_part;
        real_part = stoi(real_part_str);
        imaginary_part = stoi(imaginary_part_str);

        int* arr = new int[2];
        arr[0] = real_part;
        arr[1] = imaginary_part;
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    string num1 = "1+1i", num2 = "1+1i";
    Solution solution = Solution();
    solution.complexNumberMultiply(num1,num2);
    return 0;
}
