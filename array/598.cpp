// 二维数组及滚动数组
// 范围求和II
// https://leetcode.cn/problems/range-addition-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        // 思路：找最短长和最短宽
        if (ops.size() == 0)
        {
            return m * n;
        }
        int min_length = m;
        int min_width = n;
        for (auto &op : ops)
        {
            if(op[0]< min_length)min_length = op[0];
            if(op[1]<min_width)min_width = op[1];
        }
        return min_length*min_width;
    }
};
