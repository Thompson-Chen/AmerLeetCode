// 数字与字符串间转换
// Fizz Buzz
// https://leetcode.cn/problems/fizz-buzz/solutions/1043126/fizz-buzz-by-leetcode-solution-s0s5/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // 暴力法：18.92/5.47
        vector<string> result;
        for (int i = 1; i <= n; i++)
        {
            bool mo_3 = i%3==0;
            bool mo_5 = i%5==0;
            if(mo_3 && mo_5)
            {
                result.push_back("FizzBuzz");
            }
            else if(mo_3)
            {
                result.push_back("Fizz");
            }
            else if (mo_5)
            {
                result.push_back("Buzz");
            }
            else
            {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};