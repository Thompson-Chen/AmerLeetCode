// 数字与字符串间转换
// 求解方程
// https://leetcode.cn/problems/solve-the-equation/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        // 个人想法：（关键是字符串的识别）
        // 1. 先提取两边的式子，然后分别看x的系数a1，a2和常数系数b1，b2
        // 2. 令ans1 = a1 - a2; ans2 = b2 - b1;
        // 3. 
        //      若ans1 = 0 and ans2 != 0 -> 则说明 No solution
        //      若ans1 = 0 and ans2 = 0 -> 则说明 Infinite solutions
        //      若ans1 != 0-> 则说明有一个解
    }
};