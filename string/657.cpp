// 字符的统计
// 机器人能否返回原点
// https://leetcode.cn/problems/robot-return-to-origin/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        // 52.17/24.71
        int row = 0;
        int col = 0;
        for (char c : moves)
        {
            switch (c)
            {
            case 'L':
                col--;
                break;
            case 'R':
                col++;
                break;
            case 'U':
                row++;
                break;
            case 'D':
                row--;
                break;
            default:
                break;
            }
        }
        return row == 0 and col == 0;
    }
};