// 二维数组及滚动数组
// 杨辉三角2
// https://leetcode.cn/problems/pascals-triangle-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // // 1. 滚动数组
        // vector<int> cur, pre;
        // for (int i = 0; i <= rowIndex; i++)
        // {
        //     cur.resize(i+1);
        //     cur[0] = cur[i] = 1;
        //     for (int j = 1; j < i; j++)
        //     {
        //         cur[j] = pre[j-1] + pre[j];
        //     }
        //     pre = cur;
            
        // }
        // return pre;

        // 2. 使用一个数组倒着计算，这样能保证计算到第i项时，第i−1项仍然是上一行的值。
        vector<int> cur;
        for (int i = 0; i <= rowIndex; i++)
        {
            cur.resize(i+1);
            cur[0] = cur[i] = 1;
            for (int j = i-1; j > 0; j--)
            {
                cur[j] += cur[j-1];
            }
        }
        return cur;
        
    }
};

int main()
{
    return 0;
}