// 栈的实现
// 用栈操作构建数组
// https://leetcode.cn/problems/build-an-array-with-stack-operations/
#include <iostream>
#include <vector>
using namespace std;

// 不像中等题，更像是简单题

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int peek = 1;
        vector<string> result;
        int i = 0;
        while (i < target.size())
        {
            if (target[i] > peek)
            {
                while (peek < target[i])
                {
                    result.push_back("Push");
                    result.push_back("Pop");
                    peek++;
                }
            }
            if (target[i] == peek)
            {
                result.push_back("Push");
                peek++;
            }
            i++;
        }
        return result;
    }
};