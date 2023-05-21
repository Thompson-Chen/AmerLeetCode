// 二维数组及滚动数组
// 杨辉三角
// https://leetcode.cn/problems/pascals-triangle/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> yanghui;

        for (int line = 0; line < numRows; line++)
        {
            vector<int> temp_line;
            temp_line.push_back(1);
            for (int i = 1; i < line; i++)
            {
                temp_line.push_back(yanghui[line-1][i]+yanghui[line-1][i-1]);
            }
            if (line >= 1)
            {
                temp_line.push_back(1);
            }
            yanghui.push_back(temp_line);
        }
        return yanghui;
    }
};

int main()
{
    return 0;
}