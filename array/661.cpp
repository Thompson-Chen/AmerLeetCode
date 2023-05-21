// 二维数组及滚动数组
// 图片平滑器
// https://leetcode.cn/problems/image-smoother/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();    // row
        int n = img[0].size(); // col
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 and x < m and y >= 0 and y < n)
                        {
                            num++;
                            sum += img[x][y];
                        }
                    }
                }
                ret[i][j] = sum/num;
            }
        }
        return ret;
    }
};